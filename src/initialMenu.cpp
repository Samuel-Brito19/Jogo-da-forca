#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

void cleanScreen()
{
    system("CLS");
}

void initialMenu()
{
    int option = 0;
    while ((option < 1 || option > 3))
    {
        cleanScreen();
        cout << "Bem vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\n Escolha uma opção e tecle enter: ";
        cin >> option;
        switch (option)
        {
        case 1:
            /* code */
            cout << "Jogo iniciado";
            break;
        case 2:
            /* code */
            cout << "Informaçoes do jogo";
            break;
        case 3:
            /* code */
            cout << "Ate mais";
            break;
        }
    }
}

int main()
{

    initialMenu();
    return 0;
}