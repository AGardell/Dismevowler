//Very simple program that removes vowels from a string and provides both the reformatted string and the list of vowels.

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <iterator>

std::queue<char> letters;
std::queue<char> vowels;

bool ifVowel(char ch) {
	switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

void removeVowels(std::string& word) {
	char ch;
	
	for (auto it = word.begin(); it != word.end(); ++it) {
		ch = tolower(*it);

		if (ifVowel(ch)) {
			vowels.push(ch);
		}
		else {
			letters.push(ch);
		}
	}
}

int main() {
	std::stringstream ss;
	std::string str;
	std::string word;
	
	std::cout << "Please enter a sentence:\n\n";
	std::getline(std::cin, str);
	ss << str;

	while (ss >> word) {
		removeVowels(word);
	}

	while (!letters.empty()) {
		std::cout << letters.front();
		letters.pop();
	}

	std::cout << std::endl;

	while (!vowels.empty()) {
		std::cout << vowels.front();
		vowels.pop();
	}

	std::cout << std::endl;

	return 0;
}