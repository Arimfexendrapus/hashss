

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
        cout << "SHALL WE PLAY A GAME?\n"<< "YES / NO\n";
        cin >> ans;
    }
    //input validation
    {
        while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
        {
            cout << "TRY AGAIN\n" << "SHALL WE PLAY A GAME?\n" << "YES / NO\n";
            cin >> ans;
        }
    }
    //converting uppercase yes and no to lowercase
    {
        if (ans.compare("YES") == 0)
            ans = "yes";
        else if (ans.compare("NO") == 0)
            ans = "no";
    }
    //if the user wants to play a game the program continues
    if (ans.compare("yes") == 0)
    // asks whether the user wants to play hangman
    {
        cout << "HOW ABOUT A NICE FRIENDLY GAME OF HANGMAN?\n" << "YES / NO\n";
        cin >> ans;
        //input validation
        {
            while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
            {
                cout << "TRY AGAIN\n" << "HOW ABOUT A NICE FRIENDLY GAME OF HANGMAN? THIS TIME, YOU'LL BE GUESSING A HASH\n" << "YES / NO\n";
                cin >> ans;
            }
            //converting upercase yes and no to lowercase 
            if (ans.compare("YES") == 0)
                ans = "yes";
            else if (ans.compare("NO") == 0)
                ans = "no";
            //determing to play hangman or not
            if (ans.compare("yes") == 0)
            {
                cout << "WONDERFUL, LET US BEGIN.\n\n";
                hangman();
            }
            else if (ans.compare("no") == 0)
                cout << "WHAT A SHAME; GOODBYE.\n";
        }
    }
    //if the user doesnt want to play a game the machine says goodbye and ends program
    else if (ans.compare("no") == 0)
        cout << "VERY WELL; GOODBYE.\n";
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
    cout << "THE GOAL IS TO GUESS THE RIGHT HASH, ONE NUMBER AT A TIME; YOU HAVE 10 INCORRECT GUESSES BEFORE YOU LOSE.\n";
    cout << ("\nSET YOUR WORD TO BE HASHED: ");
    cin >> cword;
    hash<string> Pwordhash;
    size_t HashedString = Pwordhash(cword);
    cword = to_string(HashedString);
    //obtaining the word length and outputting blanks
    int word_length;
    word_length = cword.size();
    cout << "THE HASH IS " << word_length << " NUMBERS LONG\n";
    blanks.insert(0, word_length, '-');
    //showing where the spaces are
    if (correct_or_not(' ', word_length, cword) > 0)
    {
        int location = -1;
        for (int i = 0; i < correct_or_not(' ', word_length, cword); i++)
        {
            location = loc_of_correct(location, ' ', word_length, cword);
            blanks.replace(location, 1, string(1, ' '));
        }
    }
    cout << blanks;
    //getting guesses and locations of correct ones 
correct:
    if (incorrectletters != "")
        cout << "\nYOU HAVE PREVIOUSLY GUESSED THESE INCORRECT NUMBERS: " << incorrectletters << endl;
    cout << "\nGUESS YOUR NUMBER: ";
    cin >> letter;
    if (correct_or_not(letter, word_length, cword) > 0)
    {
        cout << "YOU GUESSED CORRECTLY\n";
        int location = -1;
        for (int i = 0; i < correct_or_not(letter, word_length, cword); i++)
        {
            location = loc_of_correct(location, letter, word_length, cword);
            blanks.replace(location, 1, string(1, letter));
        }
        cout << blanks << endl;
        if (blanks.find("-") == -1)
            goto guessed_word;

        goto correct;
    }
    //subtracting from incorrect guesses remaining for incorrect guesses and then starting over with another guess
incorrect:
    if (correct_or_not(letter, word_length, cword) == 0)
    {
        if (incorrectletters.find(string(1, letter)) != -1)
        {
            cout << "YOU HAVE ALREAD GUESSED THIS NUMBER; TRY AGAIN\n";
            goto correct;
        }
        incorrect++;
        if (incorrect < 11)
            cout << "YOU GUESSED INCORRECTLY\n" << "YOU ADDED A " << body_parts((incorrect)) <<  "\nYOU HAVE " << (10 - incorrect) << " INCORRECT GUESSES REMAINING.\n" << blanks << endl;
        incorrectletters.append(1, letter);
        if (incorrect > 10)
        {
            cout << "YOU ADDED THE NOOSE & YOUR MAN HAS BEEN HANGED\n" << "GAME OVER\n" << "YOU LOSE\n" << "THE WORD OR PHRASE THAT YOU WERE TRYING TO GUESS WAS " << cword << ".\n";
            goto play_again;
        }
        goto correct;
    }
guessed_word:
    //option #3
    cout << "\nYOU HAVE CORRECTLY GUESSED THE HASH.\n" << "THE HASH WAS " << blanks << ".\n\n" << "CONGRADULATIONS.\n\n";
play_again:
    cout << "PLAY AGAIN?\n" << "YES / NO\n";
    cin >> ans;
    while (ans.compare("yes") != 0 && ans.compare("no") != 0 && ans.compare("YES") != 0 && ans.compare("NO") != 0)
    {
        cout << "TRY AGAIN\n" << "SHALL WE PLAY A GAME?\n" << "YES / NO\n";
        cin >> ans;
    }
    if (ans.compare("YES") == 0)
        ans = "yes";
    else if (ans.compare("NO") == 0)
        ans = "no";
    //if the user wants to play a game the program continues
    if (ans.compare("yes") == 0)
        goto the_beginning;
    if (ans.compare("no") == 0)
        cout << "VERY WELL; GOODBYE.\n";
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
            correct++;
    }
    return correct;
}

int loc_of_correct(int w, char x, int y, string z)
{
    int location = 0;
    if (w == 0)
        w = 1;
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
    string parts[] = {"HEAD", "TORSO", "LEFT ARM", "RIGHT ARM", "LEFT LEG", "RIGHT LEG", "LEFT EYE", "RIGHT EYE", "NOSE", "FROWN"};
    string part = parts[x-1];
    return part;
}