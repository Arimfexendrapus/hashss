#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	string password("Hello"), passwordAttempt; int HashGuess;

	cout << ("Set your password. REMEMBER IT! IT IS NOT STORED: "); 
	cin >> password;

	hash<string> Pwordhash; size_t HashedString = Pwordhash(password);

	cout << "\ntry to guess your hash you dweeb: "; 
	cin >> HashGuess;

	if (HashGuess == HashedString)
		cout << "by some miracle you guessed right\n";
	else
		cout << "WRONG\n";

	cout << ("Alright nerd, log in now: ");
	cin >> passwordAttempt;

	size_t HashedStringguess = Pwordhash(passwordAttempt);

	if (HashedString == HashedStringguess)
		cout << ("Yep, you got it\n");
	else
		cout << ("WRONG\n");

	cout << "heres the hash you shoulduv guessed: " << HashedString << "\n";
}
