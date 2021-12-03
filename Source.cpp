#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
	string password("Hello"), passwordAttempt;

	cout << ("Set your password. REMEMBER IT! IT IS NOT STORED: ");
	cin >> password;
	cout << ("\n");
	std::size_t HashedString = std::hash<std::string>{}(password), HashGuess;
	//cout << ("Hashed string: ") << HashedString;
	cout << ("\n");
	cout << "try to guess your hash you dweeb: \n";
	cin >> HashGuess;
	if (HashGuess == HashedString)
	{
		cout << "by some miracle you guessed right\n";
	}
	else
	{
		cout << "WRONG\n";
	}
	cout << ("Alright nerd, log in now: ");
	cin >> passwordAttempt;
	cout << ("\n");
	std::size_t HashedPasswordAttempt = std::hash<std::string>{}(passwordAttempt);
	cout << "heres the hash you shoulduv guessed: " << HashedPasswordAttempt;
	cout << ("\n");

	if (HashedString == HashedPasswordAttempt)
	{
		cout << ("Yep, you got it\n");
	}
	else
	{
		cout << ("WRONG\n");
	}

}
