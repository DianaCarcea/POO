#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "Number.h"
#include <iostream>
#include <cstring>


Number::Number(const char* nr, int base)
{
    numar = (char*)(malloc(strlen(nr) * sizeof(char)));
    baza = (int)(malloc(sizeof(int)));
    strcpy(numar, nr);
    baza = base;
}

Number::~Number()
{
    numar = nullptr;
    baza = NULL;
}

Number::Number(int nr)
{
    int copy,  c, i;
    copy = nr;
    c = 0;
    while (copy > 0)
    {
        c++;
        copy = copy / 10;
    }

    baza = (int)(malloc(sizeof(int)));
    numar = (char*)(malloc(c * sizeof(char)));

    for (i = c - 1; i >= 0; i--)
    {
        this->numar[i] = nr % 10 + '0';
        nr = nr / 10;
    }
    this->numar[c] = '\0';

    this->baza = 10;
}

Number::Number(const char* nr)
{
    baza = (int)(malloc(sizeof(int)));
    numar = (char*)(malloc(strlen(nr) * sizeof(char)));
    strcpy(this->numar, nr);
}

Number::Number(const Number& nr)
{
    printf("Copy constructor\n");
    strcpy(numar, nr.numar);
    baza = nr.baza;
}

Number::Number(const Number&& nr)
{
    printf("Move constructor\n");
    strcpy(numar, nr.numar);
    baza = nr.baza;
}

void Number::SwitchBase(int newBase)
{
    int l, p, nr, i;

    l = strlen(numar);
    p = 1;
    nr=0;

    for (i = l - 1; i >= 0; i--)
    {
        if (numar[i] >= '0' && numar[i] <= '9')
            nr = nr + ((int)numar[i] - '0') * p;
        else
            nr = nr + ((int)numar[i] - 'A' + 10) * p;
        p = p * baza;
    }
    i = 0;
    while (nr > 0)
    {
        int x;
        x = nr % newBase;
        if (x >= 0 && x <= 9)
            numar[i++] = (char)(x + '0');
        else
            numar[i++] = (char)(x - 10 + 'A');
        nr= nr / newBase;
    }
    numar[i] = '\0';

    l = strlen(numar);

    for (i = 0; i < l / 2; i++)
    {
        char temp = numar[i];
        numar[i] = numar[l - i - 1];
        numar[l - i - 1] = temp;
    }
    this->baza = newBase;
}

void Number::Print()
{
    printf("%s\n", numar);
}

int  Number::GetDigitsCount()
{
    return strlen(numar);
}

int  Number::GetBase()
{
    return baza;
}

Number& operator+(Number& nr1, Number& nr2)
{
    printf("Operatorul: + a fost apelat ca functie friend!\n");

    int final_base;
    if (nr1.baza > nr2.baza)
        final_base = nr1.baza;
    else
        final_base = nr2.baza;

    nr1.SwitchBase(10);
    nr2.SwitchBase(10);

    int i, x, y, p;

    x = 0;
    y = 0;
    p = 1;

    for (i = strlen(nr1.numar) - 1; i >= 0; i--)
    {
        x = x + (nr1.numar[i] - '0') * p;
        p = p * 10;
    }

    p = 1;
    for (i = strlen(nr2.numar) - 1; i >= 0; i--)
    {
        y = y + (nr2.numar[i] - '0') * p;
        p = p * 10;
    }

    int z;
    z = x + y;

    int copy, k;

    copy = z;
    k = 0;

    while (copy > 0)
    {
        k++;
        copy = copy / 10;
    }

    for (i = k - 1; i >= 0; i--)
    {
        nr1.numar[i] = z % 10 + '0';
        z = z / 10;
    }

    nr1.numar[k] = '\0';
    nr1.baza = 10;
    nr1.SwitchBase(final_base);
    nr1.baza = final_base;

    return nr1;
}

Number& operator-(Number& nr1, Number& nr2)
{
    printf("Operatorul: - a fost apelat ca functie friend!\n");

    int final_base;
    if (nr1.baza > nr2.baza)
        final_base = nr1.baza;
    else
        final_base = nr2.baza;

    nr1.SwitchBase(10);
    nr2.SwitchBase(10);

    int i, x, y, p;

    x = 0;
    y = 0;
    p = 1;

    for (i = strlen(nr1.numar) - 1; i >= 0; i--)
    {
        x = x + (nr1.numar[i] - '0') * p;
        p = p * 10;
    }

    p = 1;
    for (i = strlen(nr2.numar) - 1; i >= 0; i--)
    {
        y = y + (nr2.numar[i] - '0') * p;
        p = p * 10;
    }

    int z;
    z = x - y;

    if (x > y)
        z = x - y;
    else
        z = y - x;

    int copy, k ;
    copy = z;
    k = 0;

    while (copy > 0)
    {
        k++;
        copy = copy / 10;
    }

    for (i = k - 1; i >= 0; i--)
    {
        nr1.numar[i] = z % 10 + '0';
        z = z / 10;
    }

    nr1.numar[k] = '\0';
    nr1.baza = 10;
    nr1.SwitchBase(final_base);
    nr1.baza = final_base;

    return nr1;
}

Number& Number::operator+=(Number& nr)
{
    printf("Operatorul: += a fost apelat!\n");

    int final_base;

    if (this->baza > nr.baza)
        final_base = this->baza;
    else
        final_base = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    int i, x , y , p ;

    x = 0;
    y = 0;
    p = 1;

    for (i = strlen(this->numar) - 1; i >= 0; i--)
    {
        x = x + (this->numar[i] - '0') * p;
        p = p * 10;
    }

    p = 1;
    for (i = strlen(nr.numar) - 1; i >= 0; i--)
    {
        y = y + (nr.numar[i] - '0') * p;
        p = p * 10;
    }

    int z = x + y;

    int copy, k;

    copy = z;
    k = 0;

    while (copy > 0)
    {
        k++;
        copy = copy / 10;
    }
    for (i = k - 1; i >= 0; i--)
    {
        this->numar[i] = z % 10 + '0';
        z = z / 10;
    }

    this->numar[k] = '\0';
    SwitchBase(final_base);
    nr.baza = final_base;

    return *this;
}

char Number::operator[](int index) {
    printf("Operatorul de indexare a fost apelat!\n");
    return numar[index];
}

Number& Number::operator=(Number& nr)
{
    printf("Operatorul de asignare: = a fost apelat!\n");
    strcpy(this->numar, nr.numar);
    baza = nr.baza;
    return *this;
}

Number& Number::operator=(int nr)
{
    printf("Operatorul de asignare: = a fost apelat!\n");
    int copy, c, i, temp;

    copy = nr;
    c = 0;

    while (copy > 0)
    {
        c++;
        copy = copy / 10;
    }

    for (i = c - 1; i >= 0; i--)
    {
        this->numar[i] = nr % 10 + '0';
        nr = nr / 10;
    }
    this->numar[c] = '\0';

    temp = this->baza;

    this->baza = 10;
    SwitchBase(temp);
    this->baza = temp;

    return *this;
}

Number& Number::operator=(const char* nr)
{
    printf("Operatorul de asignare: = a fost apelat!\n");

    strcpy(this->numar, nr);
    int sec = this->baza;
    this->baza = 10;

    SwitchBase(sec);
    this->baza = sec;

    return *this;
}

bool Number::operator> (Number& nr)
{
    printf("Operatorul: > a fost apelat!\n");

    int temp1 = this->baza;
    int temp2 = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    if (strcmp(this->numar, nr.numar) > 0)
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return true;
    }
    else
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return false;
    }
}

bool Number::operator< (Number& nr)
{
    printf("Operatorul: < a fost apelat!\n");

    int temp1 = this->baza;
    int temp2 = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    if (strcmp(this->numar, nr.numar) < 0)
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return true;
    }
    else
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return false;
    }

}

bool Number::operator>= (Number& nr)
{
    printf("Operatorul: >= a fost apelat!\n");

    int temp1 = this->baza;
    int temp2 = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    if (strcmp(this->numar, nr.numar) >= 0)
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return true;
    }
    else
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return false;
    }
}

bool Number::operator<= (Number& nr)
{
    printf("Operatorul: <= a fost apelat!\n");

    int temp1 = this->baza;
    int temp2 = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    if (strcmp(this->numar, nr.numar) <= 0)
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return true;
    }
    else
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return false;
    }
}

bool Number::operator== (Number& nr)
{
    printf("Operatorul: == a fost apelat!\n");

    int temp1 = this->baza;
    int temp2 = nr.baza;

    SwitchBase(10);
    nr.SwitchBase(10);

    if (strcmp(this->numar, nr.numar) == 0)
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return true;
    }
    else
    {
        SwitchBase(temp1);
        nr.SwitchBase(temp2);
        return false;
    }
}

void Number::operator--()
{
    printf("Operatorul: -- a fost apelat ca operator--()!\n");

    int i;
    for (i = 0; i < strlen(this->numar) - 1; i++)
        this->numar[i] = this->numar[i + 1];

    this->numar[strlen(this->numar) - 1] = ' \0';
}

void Number::operator--(int a)
{
    printf("Operatorul: -- a fost apelat ca operator--(int a)!\n");
    this->numar[strlen(this->numar) - 1] = ' \0';
}