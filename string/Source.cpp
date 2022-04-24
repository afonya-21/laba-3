#include "String.h"
#include <string.h>
TString::TString()
{
    len = 0;
    str = new char[len + 1];
    str[0] = 0;
}

TString::TString(int l, char c)
{
    len = l;
    str = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        str[i] = c;
    }
    str[len] = 0;
}

TString::TString(const TString& p)
{
    len = p.len;
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = p.str[i];
    }
}

TString::TString(const char* s)
{
    if (s != nullptr)
    {
        len = StrLen(s);
        str = new char[len + 1];
        for (int i = 0; i <= len; i++)
        {
            str[i] = s[i];
        }
    }
    else
    {
        len = 0;
        str = new char[len + 1];
        str[0] = 0;
    }
}

TString::~TString()
{
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
}

int TString::GetLen()
{
    return len;
}

char* TString::GetStr()
{
    return str;
}

TString TString::operator+(const TString& s)
{
    int l = len + s.len;
    TString res(l, 0);
    for (int i = 0; i < len; i++)
    {
        res.str[i] = str[i];
    }
    for (int j = len; j < l; j++)
    {
        res.str[j] = s.str[j - len];
    }
    str[l] = 0;
    return res;
}

TString TString::operator=(const TString& s)
{
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = s.str[i];
    }
    return *this;
}

char TString::operator[](int j)
{
    if (j >= 0 && j <= len)
    {
        return str[j];
    }
    else
    {
        throw out_of_range("out of range");
    }
}

bool TString::operator==(const TString& s)
{
    if (len != s.len)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] != s.str[i])
        {
            return false;
        }
    }
    return true;
}

bool TString::operator>(const TString& s)
{
    if (*this == s)
    {
        return false;
    }
    int i = 0;
    while (i <= min(len, s.len))
    {
        if (int(str[i]) > int(s.str[i]))
        {
            return true;
        }
        i++;
    }
    return len > s.len;
}

bool TString::operator<(const TString& s)
{
    if (*this == s)
    {
        return false;
    }
    return !(len > s.len);
}

int* TString::CharPositions(const char* s, int& k)
{
    int n = -1;
    int* mas;
    int l;
    l = StrLen(s);
    int i = 0;
    bool f;
    while (i <= len - l)
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
            n++;
        }
        i++;
    }
    n++;
    mas = new int[n];
    i = 0;
    n = 0;
    while (i <= len - l)
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
            mas[n] = i;
            n++;
            k++;
            i++;
        }
        else
        {
            i++;
        }
    }
    return mas;
}

ostream& operator<<(ostream& ostr, const TString& s)
{
    ostr << "Len=" << s.len << ":\t" << s.str;
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

int StrLen(const char* s)
{
    int length = 0;
    while (s[length] != 0)
    {
        length++;
    }
    return length;
}