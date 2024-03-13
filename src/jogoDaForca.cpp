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
    string words[3] = {"hearthstone", "love", "gangster"};

    int aleatoryIndex = rand() % 3;
    // cout << words[aleatoryIndex];
    return words[aleatoryIndex];
}

string returnMaskedWord(string word, int wordSize)
{
    int count = 0;

    string wordWithMask;

    while (count < wordSize)
    {
        wordWithMask += "_";
        count++;
    }

    return wordWithMask;
}

void showStatus(string wordWithMask, int wordSize, int attemptsLeft, string attemptedLetters, string message)
{
    cout << message;
    cout << "\nWord: " << wordWithMask << "(Size: " << wordSize << ")";
    cout << "\nAttempts left: " << attemptsLeft;

    int count;
    cout << "\nAttemptedLetters: ";
    for (count = 0; count < attemptedLetters.size(); count++)
    {
        cout << attemptedLetters[count] << ", ";
    }
}

void playAlone()
{
    string word = returnRandomWord();

    int wordSize = word.size();

    string wordWithMask = returnMaskedWord(word, wordSize);

    int attempts = 0, maxAttempts = 10;
    int count = 0;
    char letter;
    string attemptedLetters;
    string message;
    bool alreadyTyped = false, guessedLetter;

    while (word != wordWithMask && maxAttempts - attempts > 0)
    {
        // cout << "The secret word is " << word << "The size of the word is" << wordSize;
        showStatus(wordWithMask, wordSize, maxAttempts - attempts, attemptedLetters, message);
        cout << "\nType a letter: ";
        cin >> letter;

        for (count = 0; count < attempts; count++)
        {
            if (attemptedLetters[count] == letter)
            {
                message = "This letter has been typed already";
                alreadyTyped = true;
            }
        }

        if (alreadyTyped == false)
        {
            attemptedLetters += letter;

            for (count = 0; count < wordSize; count++)
            {
                if (word[count] == letter)
                {
                    wordWithMask[count] = word[count];
                    guessedLetter = true;
                }
            }
            if (guessedLetter = false)
            {
                message = "You got it wrong";
            }
            else
            {
                message = "You got it right";
                guessedLetter = false;
            }

            attempts++;
        }
        alreadyTyped = false;
        guessedLetter = false;
    }

    if (word == wordWithMask)
    {
        cout << "Congrats! You won.";
    }
    else
    {
        cout << "Too bad :( You lost.";
    }
}

void initialMenu()
{
    int option = 0;
    while ((option < 1 || option > 3))
    {
        cleanScreen();
        cout << "Welcome to the game!";
        cout << "\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - Exit";
        cout << "\n Choose an option and press enter: ";
        cin >> option;
        switch (option)
        {
        case 1:
            /* code */
            playAlone();
            break;
        case 2:
            /* code */
            cout << "Informations about the game";
            break;
        case 3:
            /* code */
            cout << "Until next time!";
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