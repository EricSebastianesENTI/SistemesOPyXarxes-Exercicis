#include <iostream>
#include <string>
#include "utils/ConsoleControler.h"
#include "2InputSystem/InputSystem.h"
#include <functional>
#include <list>
#include <Windows.h>
#include "3NodeMap/Timer.h"
#include "3NodeMap/Nodemap.h"
#include <json/json.h>
#include <fstream>
//typedef std::function<int(int, int)> SumaFunction;
//typedef std::function<std::list<std::list<int>>> Test;
//void TestLambdasMolonas(std::function<void()> funcionMolona)
//{
//	std::cout << "Voy a ejecutar una funcion que estaba en una variable" << std::endl;
//
//	funcionMolona();
//
//	std::cout << "Ya la he ejecutado" << std::endl;
//}
//
//class Tree : public INodeContent
//{
//	void Draw(Vector2 offset) override
//	{
//		CC::Lock();
//		CC::SetColor(CC::DARKGREY, CC::BLACK);
//		CC::SetPosition(offset.X, offset.Y);
//		std::cout << "T";
//		CC::Unlock();
//	}
//};
class Player
{
public:
	int life = 0;
	std::string name = "Test Player";
	unsigned int coins = 0;

	Player() {}
	~Player() {}

	void Decode(Json::Value json) // Des Serializar
	{
		life = json["life"].asInt();
		name = json["name"].asString();
		coins = json["coins"].asUInt();
	}
	Json::Value Encode() // Serializar
	{
		Json::Value json;

		json["life"] = life;
		json["name"] = name;
		json["coins"] = coins;

		return json;
	}
};
int main()
{
	Player* player = new Player();
	player->coins = 69;
	player->life = 67;
	player->name = "Perro Sanxe";

	Json::Value newJson;

	newJson["Player"] = player->Encode();


	/*Nodemap* mymap = new Nodemap(Vector2(20, 20), Vector2(2, 2));

	Tree* t1 = new Tree();
	Tree* t2 = new Tree();
	Tree* t3 = new Tree();
	Tree* t4 = new Tree();
	Tree* t5 = new Tree();

	mymap->SafePickNode(Vector2(0, 0), [t1](Node* node)
	{
			node->SetContent(t1);
	});
	mymap->SafePickNode(Vector2(19, 0), [t2](Node* node)
		{
			node->SetContent(t2);
		});
	mymap->SafePickNode(Vector2(0, 19), [t3](Node* node)
		{
			node->SetContent(t3);
		});
	mymap->SafePickNode(Vector2(19, 19), [t4](Node* node)
		{
			node->SetContent(t4);
		});
	mymap->SafePickNode(Vector2(10, 10), [t5](Node* node)
		{
			node->SetContent(t5);
		});

	mymap->UnSafeDraw();
	InputSystem* iS = new InputSystem();
	iS->AddListener(K_UP, [mymap]()
		{
			std::list<Vector2> positions;
			positions.push_back(Vector2(10, 10));
			positions.push_back(Vector2(10, 9));

			mymap->SafeMultiPickNode(positions, [mymap](std::list<Node*> nodes)
				{
					std::list<Node*>::iterator it = nodes.begin();

					Node* n1 = *it;
					it++;
					Node* n2 = *it;

					n2->SetContent(n1->GetContent());

					n1->SetContent(nullptr);
					n1->DrawContent(Vector2(2, 2));
					n2->DrawContent(Vector2(2, 2));

				});
		});
	iS->StartListen();*/
	///*
	//std::cout << "Start" << std::endl;
	//
	//Timer::StartTimer(3000, []()
	//{
	//	std::cout << "3 Seconds Elapsed" << std::endl;
	//});

	//std::cout << "End" << std::endl;

	///*std::string name = "Pepe";
	//std::list<std::list<int>> listaDeListas;
	//std::function<char()> funcionQueHaceCosasPeroEsUnaVariable = [name](){
	//	
	//	std::cout << "Esto no es como pero funciona y devuelve el nombre --> " << name <<std::endl;
	//	return 54;
	//	};
	//TestLambdasMolonas(funcionQueHaceCosasPeroEsUnaVariable);
	//InputSystem* iS = new InputSystem();

	//InputSystem::KeyBinding* kb = iS->AddListener(K_1, []() {
	//CC::Lock(); 
	//std::cout << "Pressed 1 " << std::endl; 
	//CC::Unlock();
	//});
	//InputSystem::KeyBinding* kb2 = iS->AddListener(K_2, []() {
	//	CC::Lock();
	//	std::cout << "Pressed 2 " << std::endl;
	//	CC::Unlock();
	//	});
	//InputSystem::KeyBinding* kb3 = iS->AddListener(K_3, []() {
	//	CC::Lock();
	//	std::cout << "Pressed 3 " << std::endl;
	//	CC::Unlock();
	//	});

	//iS->StartListen();
	
	while (true)
	{

	}
}