#include <iostream>
#include <string>
#include <fstream>
#include <json/json.h>

#include "utils/ConsoleControler.h"

class Player
{
public:
	int life = 0;
	std::string name = "Test Player";
	unsigned int coin = 0;

	Player() {}
	~Player() {}

	void Decode(Json::Value json)
	{
		life = json["life"].asInt();
		coin = json["coins"].asUInt();
		name = json["name"].asString();
	}

	Json::Value Encode()
	{
		Json::Value json;

		json["life"] = life;
		json["name"] = name;
		json["coin"] = coin; 

		return json;
	}

};

int main()
{
	Player* player = new Player();
	player->coin = 5;
	player->life = 50;
	player->name = "Mariano Rajoy";

	Json::Value newJson;
	newJson["Player"] = player->Encode();

	//std::ofstream jsonWriteFile = new std::ofstream("PlayerParseTest.json", std::if)


	//CC::SetColor(CC::WHITE, CC::CYAN);
	//ThreadTutorialTest();
}