#include <iostream>
#include <string>
#include <cctype> // tolower()
#include <map>
#include <limits>

std::string findLeet(std::string& input, std::map<char, const char*>& leet);

int main() {
	std::string user_input;
	std::map<char, const char*> leet{ {'a',"4"}, { 'b',"13",},{'c',"("},{'d',"[)"},{'e',"3"},{'f',"|="},{'g',"6"},{'h',"|-|"},
		{ 'i',"|"},{'j',"_|"},{'k',"|<"}, {'l',"1"},{'m',"|Y|"},{'n',"/\\/"},{'o',"0"},{'p', "|>"},{'q',"0,"},{'r',"|2"},
		{'s',"5"},{'t',"7"},{'u',"[_]"},{'v',"\\/"},{'w',"|^|"},{'x',"><"},{'y',"'/"},{'z',"2"} };
	bool quit{ false };
	char choice{};
	do{
		std::cout << "\nEnter text to convert: ";
		std::getline(std::cin, user_input);

		user_input = findLeet(user_input, leet);
		std::cout << "\nYour text in leet is: " << user_input << std::endl;

		std::cout << "\nDo you wish to convert more text? [Y/N]: ";
		std::cin.clear();
		std::cin >> choice;
		choice = toupper(choice);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (choice != 'N');


	std::cout << "\nExiting program..." << std::endl;
	return 0;
}

std::string findLeet(std::string& input, std::map<char, const char*>& leet) {
	std::string output;
	for (auto& letter : input) {
		if (isalpha(letter)) {
			letter = tolower(letter);
			output.append(leet[letter]);
		}
		else output.push_back(letter);
	}
	return output;
}