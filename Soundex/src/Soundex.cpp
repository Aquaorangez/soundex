//============================================================================
// Name        : Soundex.cpp
// Author      : Mick Campittelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string convert(char c);
bool vowelCheck(char c);
string duplicate(string name);
string separated(string name);
string set4Digits(string name);

int main() {
	string name, soundex, test;

	cout << "Input a last name:" << endl;
	cin >> name;

	name = duplicate(name);
	name = separated(name);

	soundex = name[0];
	//convert letters to Soundex code
	for (size_t i = 1; i < name.size(); i++) {
		soundex = soundex + convert(name[i]);
	}
	soundex = set4Digits(soundex);
	cout << soundex << endl;
}

// check and remove duplicate adjacent letters
string duplicate(string name) {

	for (size_t i = 1; i < name.size(); i++) {
		if (convert(name[i - 1]) == convert(name[i])) {
			name.erase(i, 1);
		}
	}
	return name;
}

//adds "0"s if is less than 4 digits, cuts off digits if greater.
string set4Digits(string name) {
	while (name.size() < 4)
		name += "0";
	if (name.size() > 4)
		name.erase(4, name.size());

	return name;
}

string separated(string name) {
	for (size_t i = 1; i < name.size(); i++) {
		char a = name[i - 1];
		char b = name[i];
		char c = name[i + 1];
		//if characters are the same and separated by 'h' or 'w', remove 1 of them
		if (convert(a) == convert(c) && (b == 'h' || b == 'w')) {
			name.erase(i - 1, i);
			cout << "H and W check: " << name << endl;
			continue;
		}
		//if characters are the same and separated by a vowel, keep both
		if (convert(a) == convert(c) && (vowelCheck(b))) {
			name.erase(i, i);
			continue;
		}
	}
	return name;
}

bool vowelCheck(char c) {
	switch (c) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
		return true;
	default:
		return false;
	}
}

string convert(char c) {
	switch (c) {
	case 'b':
	case 'f':
	case 'p':
	case 'v':
		return "1";
	case 'c':
	case 'g':
	case 'j':
	case 'k':
	case 'q':
	case 's':
	case 'x':
	case 'z':
		return "2";
	case 'd':
	case 't':
		return "3";
	case 'l':
		return "4";
	case 'm':
	case 'n':
		return "5";
	case 'r':
		return "6";
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'y':
	case 'h':
	case 'w':
		return "";
	default:
		return "0";
	}

}
