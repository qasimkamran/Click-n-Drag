#include <GLFW/glfw3.h>
#include "renderable.h"
#include "square.h"
#include <iostream>
#include <list>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Click-n-Drag";

std::list<Square*> squares;
Square* activeObject = nullptr;

double mouseX, mouseY;

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	glfwGetCursorPos(window, &mouseX, &mouseY);

	for (auto &obj : squares)
	{
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		{
			mouseY = SCREEN_HEIGHT - mouseY;
			obj->onClick(mouseX, mouseY);
			activeObject = obj;
			break;
		}

		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
		{
			if (activeObject != nullptr)
			{
				activeObject->onRelease();
				activeObject = nullptr;
			}
		}
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (activeObject != nullptr)
	{
		float deltaX = xpos - mouseX;
		float deltaY = (SCREEN_HEIGHT - ypos) - mouseY;

		activeObject->onDrag(deltaX, deltaY);
		
		mouseX = xpos;
		mouseY = SCREEN_HEIGHT - ypos;
	}
}

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW");
		return -1;
	}

	glfwSetErrorCallback(error_callback);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
	if (!window)
	{
		fprintf(stderr, "Failed to create GLFWwindow");
		return -1;
	}
	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);

	glfwSwapInterval(1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);

	Square square = Square(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30);

	squares.push_back(&square);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		
		for (auto &obj : squares)
		{
			obj->update(0);
			obj->render();
		}

		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}