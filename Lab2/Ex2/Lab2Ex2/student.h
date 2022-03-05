#pragma once
#include <cstring>

class Student
{
private:
	char name[100];
	float mathGrade;
	float englishGrade;
	float historyGrade;
public:
	void setName(char* newName);
	char* getName();
	bool setMathGrade(float value);
	bool setEnglishGrade(float value);
	bool setHistoryGrade(float value);
	float getMathGrade();
	float getEnglishGrade();
	float getHistoryGrade();
	float getAverageGrade();
};