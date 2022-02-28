#include "Student.h"
#include "Global.h"
#include <stdio.h>
using namespace std;

int main()
{
	printf("Primul student:\n");
	Student s1;
	s1.SetName((char*)"Jon");
	printf("Numele este: %s \n", s1.GetName());

	s1.SetMath(9);
	printf("Nota la mate: %f \n", s1.GetMath());

	s1.SetEnglish(10);
	printf("Nota la engleza: %f \n", s1.GetEnglish());

	s1.SetHistory(8);
	printf("Nota la istorie: %f \n", s1.GetHistory());

	printf("Media: %f \n", s1.GetAverage());


	printf("\nAl doilea student:\n");
	Student s2;
	s2.SetName((char*)"Thomas");
	printf("Numele este: %s \n", s2.GetName());

	s2.SetMath(7);
	printf("Nota la mate: %f \n", s2.GetMath());

	s2.SetEnglish(10);
	printf("Nota la engleza: %f \n", s2.GetEnglish());

	s2.SetHistory(9);
	printf("Nota la istorie: %f \n", s2.GetHistory());

	printf("Media: %f \n", s2.GetAverage());

	printf("\nRezultatele comparatiilor celor doi studenti sunt: \n");
	printf("Comparare dupa nume: %d \n", Name_Compare(&s1, &s2));
	printf("Comparare dupa nota la mate: %d \n", Math_Compare(&s1, &s2));
	printf("Comparare dupa nota la engleza: %d \n", English_Compare(&s1, &s2));
	printf("Comparare dupa nota la istorie: %d \n", History_Compare(&s1, &s2));
	printf("Comparare dupa media: %d \n", Average_Compare(&s1, &s2));
}