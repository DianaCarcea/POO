#include "Student.h"
#include <cstring>

//se returneaza -1, 1, 0

int Name_Compare(Student* student1, Student* student2)
{
	if (strcmp(student1->GetName(), student2->GetName()) < 0)
		return -1;
	if (strcmp(student1->GetName(), student2->GetName()) == 0)
		return 0;
	if (strcmp(student1->GetName(), student2->GetName()) > 0)
		return 1;
}

int Math_Compare(Student* student1, Student* student2)
{
	if (student1->GetMath()< student2->GetMath())
		return -1;
	if (student1->GetMath() == student2->GetMath())
		return 0;
	if (student1->GetMath() > student2->GetMath())
		return 1;
}

int English_Compare(Student* student1, Student* student2)
{
	if (student1->GetEnglish() < student2->GetEnglish())
		return -1;
	if (student1->GetEnglish() == student2->GetEnglish())
		return 0;
	if (student1->GetEnglish() > student2->GetEnglish())
		return 1;
}

int History_Compare(Student* student1, Student* student2)
{
	if (student1->GetHistory() < student2->GetHistory())
		return -1;
	if (student1->GetHistory() == student2->GetHistory())
		return 0;
	if (student1->GetHistory() > student2->GetHistory())
		return 1;
}

int Average_Compare(Student* student1, Student* student2)
{
	if (student1->GetAverage() < student2->GetAverage())
		return -1;
	if (student1->GetAverage() == student2->GetAverage())
		return 0;
	if (student1->GetAverage() > student2->GetAverage())
		return 1;
}