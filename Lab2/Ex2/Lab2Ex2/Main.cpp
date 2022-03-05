#include "student.h"
#include "globalStudent.h"
#include <iostream>

using namespace std;

int main()
{
	Student student1;
	Student student2;
	char name1[] = "Mihai";
	char name2[] = "George";
	student1.setEnglishGrade(10);
	student1.setHistoryGrade(9);
	student1.setMathGrade(6);
	student1.setName(name1);

	student2.setEnglishGrade(9);
	student2.setHistoryGrade(10);
	student2.setMathGrade(7);
	student2.setName(name2);

	cout << student1.getName() << ' ' << student2.getName() << '\n';
	cout << '\n';
	cout << "MEDII " << student1.getName() << '\n';

	cout << student1.getMathGrade() << '\n';
	cout << student1.getEnglishGrade() << '\n';
	cout << student1.getHistoryGrade() << '\n';
	cout << student1.getAverageGrade() << '\n';
	cout << '\n';
	cout << "MEDII " << student2.getName() << '\n';
	cout << student2.getMathGrade() << '\n';
	cout << student2.getEnglishGrade() << '\n';
	cout << student2.getHistoryGrade() << '\n';
	cout << student2.getAverageGrade() << '\n';

	cout << '\n';

	cout << "Comparatii: \n";
	cout << "Avarage: " << student1.getAverageGrade() << ' ' << student2.getAverageGrade() << ' ' << compare2StudentByAverageGrade(student1, student2) << '\n';
	cout << "English: " << student1.getEnglishGrade() << ' ' << student2.getEnglishGrade() << ' ' << compare2StudentByEnglishGrade(student1, student2) << '\n';
	cout << "History: " << student1.getHistoryGrade() << ' ' << student2.getHistoryGrade() << ' ' << compare2StudentByHistoryGrade(student1, student2) << '\n';
	cout << "Math: " << student1.getMathGrade() << ' ' << student2.getMathGrade() << ' ' << compare2StudentByMathGrade(student1, student2) << '\n';
	cout << "Name: " << student1.getName() << ' ' << student2.getName() << ' ' << compare2StudentsByName(student1, student2) << '\n';
}