
            {
                if (word[count] == letter)
                {
                    wordWithMask[count] = word[count];
                }
            }

            attempts++;
        }
    }

    if (word == wordWithMask)
    {
        cout << "Congrats! You won.";