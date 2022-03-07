#include "Canvas.h"
#include <iostream>
using namespace std;

int main()
{
	Canvas myCanvas(70, 90);

	myCanvas.DrawCircle(10, 10, 20, '*');
	myCanvas.Print();
	cout << endl;

	myCanvas.FillCircle(10, 10, 20, '#');
	myCanvas.Print();
	cout << endl;

	myCanvas.DrawRect(20, 10, 40, 30, '|');
	myCanvas.Print();
	cout << endl;

	myCanvas.FillRect(20, 10, 40, 30, '#');
	myCanvas.Print();
	cout << endl;

	myCanvas.SetPoint(40, 20, 'P');
	myCanvas.Print();
	cout << endl;

	myCanvas.DrawLine(10, 40, 40, 50, '_');
	myCanvas.Print();
	cout << endl;

	myCanvas.Clear();
	myCanvas.Print();

	return 0;
}