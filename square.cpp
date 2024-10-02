#include "square.h"
#include "GLFW/glfw3.h"

Square::Square(float startX, float startY, float size)
	: x(startX), y(startY), size(size) {}

void Square::render()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + size, y);
	glVertex2f(x + size, y + size);
	glVertex2f(x, y + size);
	glEnd();
}

void Square::update(float deltaTime)
{

}