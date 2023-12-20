#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "WindowOptions.h"
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main()
{
	//Init GLFW
	glfwInit();

	//GLFW ctx settings
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Creating the window with glfw
	GLFWwindow* window;// -> allocated on stack
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Window is null. Terminating" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, WIDTH, HEIGHT);

	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6,0.0f,
		0.5f / 2, 0.5f * float(sqrt(3)) / 6,0.0f,
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,
	};

	GLuint indices[] =
	{
		0 , 3 , 5,
		3 , 2 , 4,
		5 , 4 ,1
	};

	Shader shader("default.vert", "default.frag");

	VAO vao1;
	vao1.Bind();
	
	VBO vbo1(vertices, sizeof(vertices));

	EBO ebo1(indices, sizeof(indices));

	vao1.LinkVBO(vbo1, 0);
	vao1.UnBind();
	vbo1.UnBind();
	ebo1.UnBind();


	while (!glfwWindowShouldClose(window))
	{
		//Change color 
		glClearColor(0.7f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Activate();
		vao1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		//Swap front and back buffers
		glfwSwapBuffers(window);

		//Poll events so that it doesn't freeze
		glfwPollEvents();
	}

	vao1.Delete();
	vbo1.Delete();
	ebo1.Delete();
	shader.Delete();
}