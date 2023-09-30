#include <glad.h>
#include <glfw3.h>
#include <iostream>

int main(void)
{
	//Exercise 1. Change the color of the window to a shade of Orange
	//Hint: colors have 4 numbers RGBA(Red, Green, Blue, Alpha) each between 0.0f and 1.0f

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(500, 500, "Hello OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window is null. Terminating" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 500, 500);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(1.0f, 0.37f, 0.07f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	return 0;
}