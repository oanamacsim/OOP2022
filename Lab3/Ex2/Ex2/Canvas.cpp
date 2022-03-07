#include "Canvas.h"
#include <iostream>

using namespace std;

Canvas::Canvas(int width, int height) {

	this->width = width;
	this->height = height;
	//building the matrix
	matrix = new char* [height];
	for (int i = 0; i < height; i++)
		matrix[i] = new char [width];
	//making all the pixels in the matrix empty
	//a pixel is considered empty if it contains the space (value 32) character
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

	int precision = (20 / (float)100 * height); //we use a 20% precision
	for (int i = x - ray; i <= x + ray; i++)
	{
		for (int j = y - ray; j <= y + ray; j++)
		{
			if (abs((i - x) * (i - x) + (j - y) * (j - y) - ray * ray) <= precision)
			{
				matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	int precision = (20 / (float)100 * height); //we use a 20% precision
	for (int i = x - ray; i <= x + ray; i++)
	{
		for (int j = y - ray; j <= y + ray; j++)
		{
			if (abs((i - x) * (i - x) + (j - y) * (j - y) - precision) <= ray * ray)
			{
				matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {

	for (int i = left; i <= right; i++)
		matrix[i][top] = matrix[i][bottom] = ch;

	for (int i = top; i <= bottom; i++)
	{
		matrix[right][i] = matrix[left][i] = ch;
	}

}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {

	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {

	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

	int m_new = 2 * (x2 - x1);
	int slopeErrorNew = m_new - (y2 - y1);
	for (int x = y1, y = x1; x <= y2; x++)
	{
		matrix[x][y] = ch;
		slopeErrorNew += m_new;

		if (slopeErrorNew >= 0)
		{
			y++;
			slopeErrorNew -= 2 * (y2 - y1);
		}
	}
}

//printing the canvas
void Canvas::Print() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

//clearing the canvas
void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			matrix[i][j] = ' ';
}
