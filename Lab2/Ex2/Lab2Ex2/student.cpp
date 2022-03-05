#include "student.h"
#include <cstring>

void Student::setName(char* newName)
{
	strcpy(name, newName);
}

char* Student::getName()
{
	return name;
}

bool Student::setMathGrade(float value)
{
	if (value >= 1 && value <= 10) {
		mathGrade = value;
		return true;
	}
	return false;
}

bool Student::setHistoryGrade(float value)
{
	if (value >= 1 && value <= 10) {
		historyGrade = value;
		return true;
	}
	return false;
}

bool Student::setEnglishGrade(float value)
{
	if (value >= 1 && value <= 10) {
		englishGrade = value;
		return true;
	}
	return false;
}

float Student::getEnglishGrade()
{
	return englishGrade;
}

float Student::getHistoryGrade()
{
	return historyGrade;
}

float Student::getMathGrade()
{
	return mathGrade;
}

float Student::getAverageGrade()
{
	return (historyGrade + englishGrade + mathGrade) / 3;
}