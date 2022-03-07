#include "Canvas.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Canvas::Canvas(int width, int height)
{
	this->lines = height;
	this->columns = width;
	matrix = (char**)(malloc(this->lines * sizeof(char*)));

	for (int i = 0; i < this->lines; i++)
		matrix[i] = (char*)(malloc(this->columns * sizeof(char)));

	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			matrix[i][j] = ' ';
}


void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int nr;
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			nr = (i - x) * (i - x) + (j - y) * (j - y);
			if (nr >= ray * (ray - 1) && nr <= ray * (ray + 1))
				matrix[i][j] = ch;
			else
				matrix[i][j] = ' ';

		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int nr;
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			nr = (i - x) * (i - x) + (j - y) * (j - y);
			if (nr <= ray * ray)
				matrix[i][j] = ch;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		matrix[i][left] = matrix[i][right] = ch;

	for (int j = left; j <= right; j++)
		matrix[top][j] = matrix[bottom][j] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top + 1; i < bottom; i++)
		for (int j = left + 1; j < right ; j++)
			matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2 * dx - dy;
	int y = y1;

	for (int i = x1; i <= x2; i++)
	{
		matrix[i][y] = ch;
		if (D > 0)
		{
			y++;
			D = D - 2 + dx;
		}
		D = D + 2 * dy;
	}
}

void Canvas::Print()
{
	for (int i = 0;i < this->lines;i++)
	{
		for (int j = 0;j < this->columns;j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->lines; i++)
		for (int j = 0; j < this->columns; j++)
			matrix[i][j] = ' ';

}