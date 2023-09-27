#include <glad.h>
#include <glfw3.h>
#include <iostream>

const unsigned int WIDTH = 500;
const unsigned int HEIGHT = 500;

int main()
{
	//Init GLFW
	glfwInit();

	//GLFW ctx settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Creating the window with glfw
	GLFWwindow* window;
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello OpenGL", NULL, NULL); // -> allocated on stack

	if (window == NULL)
	{
		std::cout << "Window is null. Terminating" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, WIDTH, HEIGHT);

	glClearColor(0.7f, 1.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
	
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	return 0;
}