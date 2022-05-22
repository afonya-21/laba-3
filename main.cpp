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

	cout << "����� �1: " << word1 << endl << "����� �2: " << word2 << "\n" << endl;
	word3 = word1 + word2;

	cout << "����� �3 = ����� �1 + ����� �2" << endl << "����� �3: " << word3 << "\n" << endl;
	word4 = word3;

	cout << "����� �4 = ����� �3" << endl << "����� �4: " << word4 << "\n" << endl;

	if (word4 == word3) {
		cout << "����� �3 == ����� �4" << endl;
	}
	else {
		cout << "����� �3 != ����� �4" << endl;
	}

	if (word2 > word1) {
		cout << "����� �2 > ����� �1" << endl;
	}
	else {
		cout << "����� �2 <= ����� �1" << endl;
	}

	cout << "������ ��������� ������� � ����� �1 \"b\": " << word1.NumChar('b') << endl;
	cout << "������ ��������� ������ � ����� �1 \"cd\": " << word1.NumPos("cd") << endl;

	char** arr;
	int check;  
	check = word2.Split(arr, 'z');

	cout << "���������� �� �������� ����� �2 �� ������� \"z\": \n";
	for (int i = 0; i < check; i++) {
		cout << arr[i] << endl;
	}
	return 0;
}
