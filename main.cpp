#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "Header.h"
#include <locale.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	TString word1("aBcdeFfedCba");
	TString word2("vwxyzZyxWvutT");
	TString word3("");
	TString word4(word2);

	cout << "Слово №1: " << word1 << endl << "Слово №2: " << word2 << "\n" << endl;
	word3 = word1 + word2;

	cout << "Слово №3 = Слово №1 + Слово №2" << endl << "Слово №3: " << word3 << "\n" << endl;
	word4 = word3;

	cout << "Слово №4 = Слово №3" << endl << "Слово №4: " << word4 << "\n" << endl;

	if (word4 == word3) {
		cout << "Слово №3 == Слово №4" << endl;
	}
	else {
		cout << "Слово №3 != Слово №4" << endl;
	}

	if (word2 > word1) {
		cout << "Слово №2 > Слово №1" << endl;
	}
	else {
		cout << "Слово №2 <= Слово №1" << endl;
	}

	cout << "Первое вхождение символа в слове №1 \"b\": " << word1.NumChar('b') << endl;
	cout << "Первое вхождение строки в слове №1 \"cd\": " << word1.NumPos("cd") << endl;

	char** arr;
	int check;  
	check = word2.Split(arr, 'z');

	cout << "Разделение на подслова слова №2 по символу \"z\": \n";
	for (int i = 0; i < check; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
