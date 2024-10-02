#include <GLFW/glfw3.h>
#include "renderable.h"
#include "square.h"
#include <iostream>
#include <list>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Click-n-Drag";

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
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

	glfwSwapInterval(1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);

	std::list<std::shared_ptr<Renderable>> renderables;

	std::shared_ptr<Square> square = std::make_shared<Square>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 30);

	renderables.push_back(square);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		for (auto &obj : renderables)
		{
			obj->render();
		}

		glfwSwapBuffers(window);
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}