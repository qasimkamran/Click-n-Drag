#include "square.h"
#include "GLFW/glfw3.h"
#include <iostream>

Square::Square(float startX, float startY, float size)
	: x(startX), y(startY), size(size) {}

void Square::render()
{
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x + size, y);
		glVertex2f(x + size, y + size);
		glVertex2f(x, y + size);
	glEnd();
}

bool Square::isMouseOver(float mouseX, float mouseY)
{
	return mouseX >= x && mouseX <= (x + size) && mouseY >= y && mouseY <= (y + size);
}

void Square::onClick(float mouseX, float mouseY)
{
	if (isMouseOver(mouseX, mouseY))
	{
		selected = true;
	}
}

void Square::onDrag(float deltaX, float deltaY)
{
	if (selected)
	{
		x += deltaX;
		y += deltaY;
	}
}

void Square::onRelease()
{
	selected = false;
}

void Square::update(float deltaTime)
{
	if (selected)
	{
		r = 1.0f, g = 0.0f, b = 0.0f;
	}
	else
	{
		r = 0.0f, g = 1.0f, b = 0.0f;
	}
}