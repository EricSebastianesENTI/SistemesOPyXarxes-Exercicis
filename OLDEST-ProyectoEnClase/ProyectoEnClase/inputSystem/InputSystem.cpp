#include "InputSystem.h"
#include "../utils/ConsoleControler.h"

InputSystem::KeyBinding::KeyBinding(int key, OnKeyPress onKeypress)
{
	_key = key;
	_onKeyPress = onKeypress;
}

InputSystem::KeyBinding::~KeyBinding()
{

}

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
	for (std::pair<int, KeyBindingList> pair : _keyBindingsMap)
	{
		KeyBindingList bindingList = pair.second;
		for (KeyBinding* binding : bindingList)
		{
			delete binding;
		}
		bindingList.clear();
	}
	_keyBindingsMap.clear();
}

InputSystem::KeyBinding* InputSystem::AddListener(int key, KeyBinding::OnKeyPress onKeyPress)
{
	_classMutex.lock();
	
	if (_keyBindingsMap.find(key) == _keyBindingsMap.end())
	{
		_keyBindingsMap[key] = KeyBindingList();
	}

	KeyBinding* keyBinding = new KeyBinding(key, onKeyPress);
	_keyBindingsMap[key].push_back(keyBinding);

	_classMutex.unlock();
		return keyBinding;
}

void InputSystem::RemoveAndDeleteListener(KeyBinding* keyBinding)
{
	int key = keyBinding->_key;
	_classMutex.lock();

	if (_keyBindingsMap.find(key) != _keyBindingsMap.end())
	{
		KeyBindingList list = _keyBindingsMap[key];
		list.remove(keyBinding);
		delete keyBinding;

		if (list.size() <= 0)
		{
			_keyBindingsMap.erase(key);
		}
	}
	_classMutex.unlock();
}

void InputSystem::StartListen()
{
	_classMutex.lock();

	if (_state != Stoped)
	{
		_classMutex.unlock();
		return;
	}
	_state = Starting;

	std::thread* listenLoopThread = new std::thread(&InputSystem::Listenloop, this);
	listenLoopThread->detach();

	_classMutex.unlock();
}

void InputSystem::StopListen()
{
	_classMutex.lock();

	if (_state != Listening)
	{
		_classMutex.unlock();
		return;
	}

	_state = Stopping;

	_classMutex.unlock();
}

void InputSystem::Listenloop()
{
	_classMutex.lock();

	_state = Listening;
	State currentState = _state;
	CC::ClearKeyBuffer();

	_classMutex.unlock();

	while (currentState == Listening)
	{
		int key = CC::ReadNextKey();

		if (key != 0)
		{
			_classMutex.lock();
			
			if (_keyBindingsMap.find(key) != _keyBindingsMap.end())
			{
				KeyBindingList list = _keyBindingsMap[key];

				for (KeyBinding* binding : list)
				{		//Ejecuta lo que toque
					std::thread* onKeypressThread = new std::thread(binding->_onKeyPress);
					onKeypressThread->detach();
				}
			}
			_classMutex.unlock();
		}
		_classMutex.lock();
		currentState = _state;
		_classMutex.unlock();
	}
	_classMutex.lock();
	if (_state == Stopping)
	{
		_state = Stoped;
	}
	_classMutex.unlock();
}