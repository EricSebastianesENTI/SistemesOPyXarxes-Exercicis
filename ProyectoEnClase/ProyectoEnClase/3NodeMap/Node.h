#pragma once
#include "Vector2.h"
#include "INodeContent.h"
#include <mutex>
class Node
{
public:
	Node(Vector2 position);

	INodeContent* GetContent();

	// MICKEY Herramienta para mas tarde
	template <typename T, typename = typename std::enable_if<std::is_base_of<INodeContent,T>::value>::type>
	T* GetContent()
	{
		if (_contents == nullptr)
			return nullptr;
		T* contentCasted = dynamic_cast<T*>(_contents);
		return contentCasted;
	}

	template <typename T>
	bool GetContent(T* outContent)
	{
		if (_contents == nullptr)
			return false;
		outContent = dynamic_cast<T*>(_contents);
		return outContent != nullptr;
	}

	void SetContent(INodeContent* nodeContent);
	void DrawContent(Vector2 offset);

	void Lock();
	void Unlock();

private:
	Vector2 _position;
	INodeContent* _contents;
	std::mutex _classMutex;
};

