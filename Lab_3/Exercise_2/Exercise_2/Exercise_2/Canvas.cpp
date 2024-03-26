#include <iostream>
#include "Canvas.h"
#include<cstring>
using namespace std;

Canvas::Canvas(int width, int height)
{
	this->height = height;
	this->width = width;
	this->mat = new char* [height];
	for (int i = 0; i < height; i++)
	{
		this->mat[i] = new char[width + 1];
		memset(this->mat[i], ' ', width);
		this->mat[i][width] = NULL;
	}
}

void DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i <= 2 * ray; ++i) {
		for (int j = 0; j <= 2 * ray; ++j) {
			int dx = i - ray;
			int dy = j - ray;
			if (std::abs(dx * dx + dy * dy - ray * ray) < ray) {
				std::cout << ch;
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if (x - ray > this->width || y - ray > this->height || x + ray < 0 || y + ray < 0)
		return;
	for (int i = x - ray; i <= x + ray; i++)
		for (int j = y - ray; j <= y + ray; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) < ray * ray - 1)
				this->mat[j][i] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left<0 || right>this->width || top<0 || bottom>this->height)
		return;
	for (int i = left; i <= right; i++)
		this->mat[top][i] = this->mat[bottom][i] = ch;

	for (int j = bottom; j <= top; j++)
		this->mat[j][left] = this->mat[j][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left<0 || right>this->width || top<0 || bottom>this->height)
		return;
	for (int i = left + 1; i < right; i++)
		for (int j = bottom + 1; j < top; j++)
			this->mat[j][i] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x > this->width || x<0 || y>this->height || y < 0)
		return;
	this->mat[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, sx, dy, sy;
	dx = abs(x2 - x1);
	sx = x1 < x2 ? 1 : -1;
	dy = -abs(y2 - y1);
	sy = y1 < y2 ? 1 : -1;
	int    e2, error = dx + dy;

	while (true)
	{
		this->mat[y1][x1] = ch;
		if (x1 == x2 && y1 == y2) break;
		e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2) break;
			error = error + dy;
			x1 = x1 + sx;
		}
		if (e2 <= dx)
		{
			if (y1 == y2) break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			cout << this->mat[i][j];
		cout << '\n';
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
			this->mat[j][i] = ' ';
}
