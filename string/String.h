#pragma once
#include <iostream>
using namespace std;

class TString
{
public:

	TString();
	TString(int l, char c);
	TString(const TString& p);
	TString(const char* s);
	~TString();

	int GetLen();
	char* GetStr();

	TString operator+(const TString& s);
	TString operator=(const TString& s);

	char operator[](int j);
	bool operator==(const TString& s);
	bool operator<(const TString& s);
	bool operator>(const TString& s);

	friend ostream& operator<<(ostream& ostr, const TString& s);
	friend istream& operator>>(istream& istr, TString& s);

	int* CharPositions(const char* s, int& k);

private:
	int len;
	char* str;
};
int StrLen(const char* s);