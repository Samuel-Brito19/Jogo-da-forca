#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;

void cleanScreen()
{
    system("clear");
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

int play(int numberOfPlayers)
{

    string word;
    if (numberOfPlayers == 1)
    {
        word = returnRandomWord();
    }
    else
    {
        cout << "\nType a word: ";
        cin >> word;
    }

    int wordSize = word.size();

    string wordWithMask = returnMaskedWord(word, wordSize);

    int attempts = 0, maxAttempts = 10;
    int count = 0;
    char letter;
    int option;
    string attemptedLetters;
    string message = "Welcome to the game";
    string attemptedWord;
    bool alreadyTyped = false, guessedLetter;

    while (word != wordWithMask && maxAttempts - attempts > 0)
    {
        cleanScreen();
        // cout << "The secret word is " << word << "The size of the word is" << wordSize;
        showStatus(wordWithMask, wordSize, maxAttempts - attempts, attemptedLetters, message);
        cout << "\nType a letter (Or type 1 if you want to spell the entire word): ";
        cin >> letter;

        if (letter == '1')
        {
            cin >> attemptedWord;
            if (attemptedWord == word)
            {
                wordWithMask = attemptedWord;
            }
            else
            {
                attempts = maxAttempts;
            }
        }

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
            attemptedLetters += tolower(letter);

            for (count = 0; count < wordSize; count++)
            {
                if (word[count] == tolower(letter))
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
        cleanScreen();
        cout << "Congrats! You won.";
        cout << "\nWants to play again?";
        cout << "\n1 - Yes";
        cout << "\n2 - No";
        cin >> option;
        return option;
    }
    else
    {
        cleanScreen();
        cout << "Too bad :( You lost.";
        cout << "\nWants to play again?";
        cout << "\n1 - Yes";
        cout << "\n2 - No";
        cin >> option;
        return option;
    }
}

void initialMenu()
{
    int option = 0;
    while ((option < 1 || option > 3))
    {
        cleanScreen();
        cout << "Welcome to the game!";
        cout << "\n1 - Play alone";
        cout << "\n2 - Play with a friend";
        cout << "\n3 - About";
        cout << "\n4 - Exit";
        cout << "\n Choose an option and press enter: ";
        cin >> option;
        switch (option)
        {
        case 1:
            /* code */
            if (play(1))
            {
                initialMenu();
            }
            break;
        case 2:
            /* code */
            if (play(2))
            {
                initialMenu();
            }
            break;
        case 3:
            /* code */
            cout << "Game informations";
            cleanScreen();
            cout << "Game developed by Samuel in 2024";
            cout << "\n1 - Back";
            cout << "\n2 - Exit";
            cin >> option;
            if (option == 1)
            {
                initialMenu();
            }
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