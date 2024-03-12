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

string returnRandomWord()
{
    string palavras[3] = {"Hearthstone", "Love", "Gangster"};

    int aleatoryIndex = rand() % 3;
    cout << palavras[aleatoryIndex];

    return palavras[aleatoryIndex];
}

void playAlone()
{
    string palavra = returnRandomWord();
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
            playAlone();
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
    srand((unsigned)time(NULL));

    initialMenu();
    return 0;
}