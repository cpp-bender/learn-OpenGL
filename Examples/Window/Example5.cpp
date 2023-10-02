#include <glad.h>
#include <glfw3.h>
#include <iostream>

int main(void)
{
	//Exercise 1. Make the window nicely fluctuate between a variety of colors
	//using glfwGetTime() (this function returns the number of seconds that have
	//passed since the beginning of the program as a double)
	//Hint: make an if statement that becomes True periodically, and inside of it change the
	//value of the variable that controls the colors; do not forget to transform the doubles into floats

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(400, 400, "Hello OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window is null. Terminating" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 400, 400);

	GLclampf r, g, b, a;
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
	a = 0.0f;

	float prev_time = (float)glfwGetTime();
	float angle = 0.0f;
	float speed = 0.5f;

	while (!glfwWindowShouldClose(window))
	{
		GLfloat passed_time = (GLfloat)glfwGetTime();

		if (passed_time - prev_time >= 0.1f)
		{
			angle += .1f * speed;
			std::cout << angle << std::endl;
			prev_time = passed_time;
		}

		glClearColor((float)sin(angle), (float)cos(angle), (float)tan(angle), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	return 0;
}