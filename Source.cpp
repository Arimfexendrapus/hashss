

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <unordered_map>





/*

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
	string password("Hello"), passwordAttempt; int HashGuess;

	cout << ("Set your password. REMEMBER IT! IT IS NOT STORED: "); 
	cin >> password;

	hash<string> Pwordhash; 
	size_t HashedString = Pwordhash(password);

	cout << "\ntry to guess your hash you dweeb: "; 
	cin >> HashGuess;

	if (HashGuess == HashedString)
		cout << "by some miracle you guessed right\n";
	else
		cout << "WRONG\n";

	cout << ("Alright nerd, log in now: ");
	cin >> passwordAttempt;

	size_t HashedStringGuess = Pwordhash(passwordAttempt);

	if (HashedString == HashedStringGuess)
		cout << ("Yep, you got it\n");
	else
		cout << ("WRONG\n");

	cout << "here's the hash you should have guessed: " << HashedString << "\n";
}
*/

/*
Name : Tyler Felts
Date : 10/29/2020
Class : CSC 1710
Path : ~/csc1710/Program3/Felts_Hangman_Grade105.cpp
Description : hangman game



I am trying to abtain an A grade for this program, i have included all the requirements for an A level program and added also bonuses #1 and #3 for a total grade of 100% hopefully.

*/




using namespace std;
//the hangman game
int hangman();
//determine location of correct guess
int loc_of_correct(int w, char x, int y, string z);
//determine if the guess was correct
int correct_or_not(char x, int y, string z);
//body parts
string body_parts(int x);
//before we begin...
int main()
{
    //initailizing variables

    string ans;


    // asking the shall we play a game question and recieving an answer
    {
        cout << "SHALL WE PLAY A GAME?" << endl << "YES / NO" << endl;
        cin >> ans;
    }

    //input validation
    {
        while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
        {
            cout << "TRY AGAIN" << endl << "SHALL WE PLAY A GAME?" << endl << "YES / NO" << endl;
            cin >> ans;
        }
    }

    //converting uppercase yes and no to lowercase
    {
        if (ans.compare("YES") == 0)
        {
            ans = "yes";
        }
        else if (ans.compare("NO") == 0)
        {
            ans = "no";
        }
    }

    //if the user wants to play a game the program continues

    if (ans.compare("yes") == 0)

        // asks whether the user wants to play hangman
    {
        cout << "HOW ABOUT A NICE FRIENDLY GAME OF HANGMAN?" << endl << "YES / NO" << endl;
        cin >> ans;
        //input validation
        {
            while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
            {
                cout << "TRY AGAIN" << endl << "HOW ABOUT A NICE FRIENDLY GAME OF HANGMAN? THIS TIME, YOU'LL BE GUESSING A HASH" << endl << "YES / NO" << endl;
                cin >> ans;
            }
            //converting upercase yes and no to lowercase 
            if (ans.compare("YES") == 0)
            {
                ans = "yes";
            }
            else if (ans.compare("NO") == 0)
            {
                ans = "no";
            }
            //determing to play hangman or not
            if (ans.compare("yes") == 0)
            {
                cout << "WONDERFUL, LET US BEGIN." << endl << endl;
                hangman();
            }
            else if (ans.compare("no") == 0)
            {
                cout << "WHAT A SHAME; GOODBYE." << endl;
            }
        }
    }


    //if the user doesnt want to play a game the machine says goodbye and ends program

    else if (ans.compare("no") == 0)
    {
        cout << "VERY WELL; GOODBYE." << endl;
    }

    return 0;


}







int hangman()
{
the_beginning:
    //initializing starting variables
    string incorrectletters, ans, blanks, cword = "0";
    char letter;
    int incorrect = 0;


    //instructions
    cout << "THE GOAL IS TO GUESS THE RIGHT HASH, ONE NUMBER AT A TIME; YOU HAVE 10 INCORRECT GUESSES BEFORE YOU LOSE." << endl;

    cout << ("SET YOUR WORD TO BE HASHED: ");
    cin >> cword;

    hash<string> Pwordhash;
    size_t HashedString = Pwordhash(cword);

    cword = to_string(HashedString);


    //obtaining the word length and outputting blanks
    int word_length;
    word_length = cword.size();
    cout << "THE HASH IS " << word_length << " NUMBERS LONG" << endl;
    blanks.insert(0, word_length, '-');

    //showing where the spaces are
    if (correct_or_not(' ', word_length, cword) > 0)
    {

        int location = -1;
        for (int i = 0; i < correct_or_not(' ', word_length, cword); i++)
        {
            /*
            if (location>-1)
            {
                location++;
            }
            */
            location = loc_of_correct(location, ' ', word_length, cword);
            blanks.replace(location, 1, string(1, ' '));


        }

    }


    cout << blanks;
    //getting guesses and locations of correct ones 
correct:
    cout << endl << "GUESS YOUR LETTER." << endl;
    //the is where i add the option #4 in the B program
    cout << "YOU HAVE PREVIOUSLY GUESSED THESE INCORRECT LETTERS: " << incorrectletters << endl;
    cin >> letter;
    //adding option #2 
    if (correct_or_not(letter, word_length, cword) > 0)
    {
        cout << "YOU GUESSED CORRECTLY" << endl;
        int location = -1;
        for (int i = 0; i < correct_or_not(letter, word_length, cword); i++)
        {
            /*
            if (location>-1)
            {
                location=location+2;
            }
            */
            location = loc_of_correct(location, letter, word_length, cword);
            blanks.replace(location, 1, string(1, letter));


        }
        cout << blanks << endl;
        if (blanks.find("-") == -1)
        {
            goto guessed_word;
        }
        goto correct;
    }
    //subtracting from incorrect guesses remaining for incorrect guesses and then starting over with another guess
incorrect:
    if (correct_or_not(letter, word_length, cword) == 0)
    {
        //adding option #5
        if (incorrectletters.find(string(1, letter)) != -1)
        {
            cout << "YOU HAVE ALREAD GUESSED THIS LETTER; TRY AGAIN" << endl;
            goto correct;
        }
        incorrect++;
        if (incorrect < 11)
        {
            //this is where i add options #7 and #1
            cout << "YOU GUESSED INCORRECTLY" << endl << "YOU ADDED A " << body_parts((incorrect)) << endl << "YOU HAVE " << (10 - incorrect) << " INCORRECT GUESSES REMAINING." << endl << blanks << endl;
        }
        incorrectletters.append(1, letter);
        if (incorrect > 10)
        {
            //option #3
            cout << "YOU ADDED THE NOOSE & YOUR MAN HAS BEEN HANGED" << endl << "GAME OVER" << endl << "YOU LOSE" << endl << "THE WORD OR PHRASE THAT YOU WERE TRYING TO GUESS WAS " << cword << "." << endl;
            goto play_again;
        }
        goto correct;
    }

guessed_word:
    //option #3
    cout << endl << "YOU HAVE CORRECTLY GUESSED THE WORD OR PHRASE." << endl << "THE WORD OR PHRASE WAS " << blanks << "." << endl << endl << "CONGRADULATIONS." << endl << endl;
play_again:
    cout << "PLAY AGAIN?" << endl << "YES / NO" << endl;
    cin >> ans;

    {
        while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
        {
            cout << "TRY AGAIN" << endl << "SHALL WE PLAY A GAME?" << endl << "YES / NO" << endl;
            cin >> ans;
        }
    }

    {
        if (ans.compare("YES") == 0)
        {
            ans = "yes";
        }
        else if (ans.compare("NO") == 0)
        {
            ans = "no";
        }
    }

    //if the user wants to play a game the program continues

    if (ans.compare("yes") == 0)
    {
        goto the_beginning;
    }
    if (ans.compare("no") == 0)
    {
        cout << "VERY WELL; GOODBYE." << endl;
    }


    return 0;

}

int correct_or_not(char x, int y, string z)
{
    int correct = 0;
    for (int i = 0; i < y; i++)
    {
        string ch, a;
        a.insert(0, 1, x);

        ch = z.at(i);
        if (ch.compare(a) == 0)
        {
            correct++;
        }

    }
    return correct;
}

int loc_of_correct(int w, char x, int y, string z)
{
    int location = 0;
    if (w == 0)
    {
        w = 1;
    }
    for (int i = w + 1; i < y; i++)
    {
        string ch, a;
        a.insert(0, 1, x);

        ch = z.at(i);
        if (ch.compare(a) == 0)
        {
            location = i;
            break;
        }

    }
    return location;
}

string body_parts(int x)
{
    string part;
    if (x == 1)
    {
        part = "HEAD";
    }
    else if (x == 2)
    {
        part = "TORSO";
    }
    else if (x == 3)
    {
        part = "LEFT ARM";
    }
    else if (x == 4)
    {
        part = "RIGHT ARM";
    }
    else if (x == 5)
    {
        part = "LEFT LEG";
    }
    else if (x == 6)
    {
        part = "RIGHT LEG";
    }
    else if (x == 7)
    {
        part = "LEFT EYE";
    }
    else if (x == 8)
    {
        part = "RIGHT EYE";
    }
    else if (x == 9)
    {
        part = "NOSE";
    }
    else if (x == 10)
    {
        part = "FROWN";
    }
    return part;
}