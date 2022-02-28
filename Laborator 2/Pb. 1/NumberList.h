class NumberList
{
	int numbers[10];
	int count;

public:
	void Init();// count va fi 0
	bool Add(int x);//adauga x la lista de numere si creste numarul de membri de date
					//daca numarul este mai mare sau egal cu 10, functia va returna false

	void Sort();//va sorta vectorul de numere
	void Print();//va printa vectorul curent
};