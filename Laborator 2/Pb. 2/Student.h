#ifndef Student_HEADER
#define Student_HEADER

class Student
{
	char Name[20];
	float Math;
	float English;
	float History;
	float Average;

	public:
		void SetName(char* nume);
		char* GetName();
		void SetMath(float n);
		float GetMath();
		void SetEnglish(float n);
		float GetEnglish();
		void SetHistory(float n);
		float GetHistory();
		float GetAverage();

};
#endif
