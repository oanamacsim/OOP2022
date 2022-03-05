#pragma once
#include <cstring>

int compare2StudentsByName(Student s1, Student s2)
{
	return strcmp(s1.getName(), s2.getName());
}

int compare2StudentByAverageGrade(Student s1, Student s2)
{
	float s1Grade = s1.getAverageGrade(), s2Grade = s2.getAverageGrade();
	if (s1Grade == s2Grade)
		return 0;
	if (s1Grade > s2Grade)
		return 1;
	return -1;
}

int compare2StudentByMathGrade(Student s1, Student s2)
{
	float s1Grade = s1.getMathGrade(), s2Grade = s2.getMathGrade();
	if (s1Grade == s2Grade)
		return 0;
	if (s1Grade > s2Grade)
		return 1;
	return -1;
}

int compare2StudentByHistoryGrade(Student s1, Student s2)
{
	float s1Grade = s1.getHistoryGrade(), s2Grade = s2.getHistoryGrade();
	if (s1Grade == s2Grade)
		return 0;
	if (s1Grade > s2Grade)
		return 1;
	return -1;
}

int compare2StudentByEnglishGrade(Student s1, Student s2)
{
	float s1Grade = s1.getEnglishGrade(), s2Grade = s2.getEnglishGrade();
	if (s1Grade == s2Grade)
		return 0;
	if (s1Grade > s2Grade)
		return 1;
	return -1;
}