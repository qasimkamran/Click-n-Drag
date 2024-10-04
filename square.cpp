#include "square.h"
#include "GLFW/glfw3.h"
#include <iostream>

Square::Square(float startX, float startY, float size)
	: x(startX), y(startY), size(size) {}

void Square::render()
{
	if (selected)
	{
		glColor3f(1.0f, 0.0f, 0.0f);
	}
	else
	{
		glColor3f(0.0f, 1.0f, 0.0f);
	}
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + size, y);
	glVertex2f(x + size, y - size);
	glVertex2f(x, y - size);
	glEnd();
}

bool Square::isMouseOver(float mouseX, float mouseY)
{
	std::cout << "Mouse Position: (" << mouseX << "," << mouseY << ")" << std::endl;
	std::cout << "Square Position: (" << x << "," << y << ")" << std::endl;
	return mouseX >= x && mouseX <= (x + size) && mouseY >= y && mouseY <= (y + size);
}

void Square::onClick(float mouseX, float mouseY)
{
	if (isMouseOver(mouseX, mouseY))
	{
		std::cout << "Selected" << std::endl;
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

}