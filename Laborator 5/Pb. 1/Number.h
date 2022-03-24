#pragma once
class Number
{
	char *numar;
	int baza;

	public:

	Number(const char* number, int base); // where base is between 2 and 16
	~Number();
	Number(int number);
	Number(const char* number);

	Number(const Number& number); //copy constructor
	Number(const Number&& number);//move constructor

	//Operatori pentru asignare
	Number& operator=(Number& number);
	Number& operator=(int number);
	Number& operator=(const char* number);

	//Operatori binari
	friend Number& operator+(Number& number1, Number& number2);
	friend Number& operator-(Number& number1, Number& number2);
	Number& operator+=(Number& number);

	//Operatori relationari
	bool operator> (Number& number);
	bool operator< (Number& number);
	bool operator>= (Number& number);
	bool operator<= (Number& number);
	bool operator== (Number& number);


	//Operatori de prefixare si postfixare
	void operator--();//-numar
	void operator--(int a);//numar--

	//Operator de indexare
	char operator[](int index);

	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();     // returns the number of digits for the current number
	int GetBase();            // returns the current base
};

