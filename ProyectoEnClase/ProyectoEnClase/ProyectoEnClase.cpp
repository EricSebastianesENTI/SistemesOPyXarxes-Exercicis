#include <iostream>
#include <functional>
#include <string>
#include "utils/ConsoleControler.h"
#include "inputSystem/InputSystem.h"


int main()
{
	InputSystem* iS = new InputSystem();

	InputSystem::KeyBinding* kb = iS->AddListener(K_1, []()
		{ 
		CC::Lock(); 
		std::cout << "Pressed 1" << std::endl; 
		CC::Unlock(); 
		});
	iS->StartListen();


	while (true)
	{

	}
}
/*
//----------------------------Clase de prueba de funciones lambda-----------------------------
	 //Función lambda
typedef std::function<int(int, int)> SumaFunction;

void TestlambdasMolonas(SumaFunction funcionMolona)
{
	std::cout << "Voy a ejecutar una funcion que estaba en una variable" << std::endl;

	int number = funcionMolona(5,7);

	std::cout << "ya la he ejecutado jijija" << std::endl;
}

	int main()
	{
	std::string name = "Pepe";
	//ThreadTutorialTest(); //Ejercicio 1
	//CC::SetColor(CC::WHITE, CC::CYAN); //Ejercicio 2

	//std::function<int(int, int)> funcionQuehaceCosasPeroEsUnaVariable = [name](int a, int b) {

	SumaFunction funcionQuehaceCosasPeroEsUnaVariable = [name](int a, int b) {
		std::cout << "Esto no se como pero funciona y dice un nombre --> " << name << std::endl;
		return a + b;
	};

	TestlambdasMolonas(funcionQuehaceCosasPeroEsUnaVariable);
	}
*/