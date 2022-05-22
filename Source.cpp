#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

TString::TString() //по умолчанию
{
	str = nullptr;
	length = 0;
}

TString::TString(const char* str)//инициализатор
{

	length = strlen(str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = str[i];
	}

	this->str[length] = '\0';
}

TString::TString(const TString& other)//копирование
{
	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';
}

TString::~TString()// деструктор
{
	delete[] this->str;
}



int TString::GetLength()
{
	return length;
}

char* TString::GetStr()
{
	return str;
}



TString TString::operator+(const TString& other)
{
	TString newStr;

	int thisLength = strlen(this->str);
	int otherLength = strlen(other.str);

	newStr.length = thisLength + otherLength;

	newStr.str = new char[thisLength + otherLength + 1];

	int i = 0;
	for (; i < thisLength; i++)
	{
		newStr.str[i] = this->str[i];
	}

	for (int j = 0; j < otherLength; j++, i++)
	{
		newStr.str[i] = other.str[j];
	}

	newStr.str[thisLength + otherLength] = '\0';

	return newStr;
}

TString& TString::operator=(const TString& other)
{
	if (this->str != nullptr)
	{
		delete[] str;
	}

	length = strlen(other.str);
	this->str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		this->str[i] = other.str[i];
	}

	this->str[length] = '\0';

	return *this;

}

TString& TString::operator=(const char* other)
{
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other[i];
		}

		this->str[length] = '\0';

		return *this;

	}
}

bool TString::operator==(const TString& other)
{
	if (this->length != other.length)
	{
		return false;
	}

	for (int i = 0; i < this->length; i++)
	{
		if (this->str[i] != other.str[i])
		{
			return false;
		}
	}
	return true;
}

char TString::operator[](int i)
{
	return this->str[i];
}

bool TString::operator>(const TString& s)
{
	if (*this == s)
	{
		return false;
	}
	int i = 0;
	while (i <= min(length, s.length))
	{
		if (int(str[i]) > int(s.str[i]))
		{
			return true;
		}
		i++;
	}
	return length > s.length;
}

bool TString::operator<(const TString& s)
{
	if (*this == s)
	{
		return false;
	}
	int i = 0;
	while (i <= min(length, s.length))
	{
		if (int(str[i]) < int(s.str[i]))
		{
			return true;
		}
		i++;
	}
	return length < s.length;
}

ostream& operator<<(ostream& ostr, const TString& s)
{
	ostr << s.str;
	return ostr;
}

istream& operator>>(istream& istr, TString& s)
{
	if (s.str != nullptr)
	{
		delete[] s.str;
		s.str = nullptr;
	}
	char* res = new char[1000];
	istr >> res;
	TString st(res);
	s = st;
	delete[] res;
	return istr;
}


int TString::NumChar(char c)
{
	int n = -1;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			n = i;
			break;
		}
	}
	return n;
}

int TString::NumPos(const char* s)
{
	int n = -1;
	int l;
	l = strlen(s);
	int i = 0;
	bool f;
	while (i <= length - l)
	{
		f = true;
		for (int j = i; j < i + l; j++)
		{
			if (str[j] != s[j - i])
			{
				f = false;
				break;
			}
		}
		if (f == true)
		{
			n = i;
			break;
		}
		else
		{
			i++;
		}
	}
	return n;
}

int TString::Split(char**& arr, const char a)const {
	char* s = new char[2];
	s[0] = a;
	int flags = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == s[0]) {
			flags++;
		}
	}
	if (str[0] == s[0]) {
		flags--;
	}
	if (str[strlen(str) - 1] == s[0]) {
		flags--;
	}
	arr = new char* [flags + 1];
	for (int i = 0; i <= flags; i++) {
		arr[i] = new char[strlen(str) + 1];
	}
	char* str1 = str;
	str1 = strtok(str1, s);
	int i = 0;
	for (int i = 0; i < flags; i++) {
		arr[i] = str1;
		str1 = strtok(NULL, s);
	}
	arr[flags] = str1;
	return flags + 1;
}
