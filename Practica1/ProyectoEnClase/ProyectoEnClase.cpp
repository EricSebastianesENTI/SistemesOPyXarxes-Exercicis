#include <iostream>

#include "Utils/ConsoleControl.h"
#include "2InputSystem/InputSystem.h"

void CuandoPresionan1()
{
    CC::Lock();
    std::cout << "Pessed 1" << std::endl;
    CC::Unlock();
}

int main()
{
    InputSystem* iS = new InputSystem();

    /*InputSystem::KeyBinding* kb1 = iS->AddListener(K_1, []() {
        CC::Lock();
        std::cout << "Pessed 1" << std::endl;
        CC::Unlock();
        });*/

    InputSystem::KeyBinding* kb1 = iS->AddListener(K_1, CuandoPresionan1);

    InputSystem::KeyBinding* kb2 = iS->AddListener(K_2, [iS]() {
        CC::Lock();
        std::cout << "Pessed 2" << std::endl;
        CC::Unlock();

            InputSystem::KeyBinding* kb3 = iS->AddListener(K_3, []() {
            CC::Lock();
            std::cout << "Pessed 3" << std::endl;
            CC::Unlock();
            });

        });

    

    iS->StartListen();


    while (true)
    {

    }
}