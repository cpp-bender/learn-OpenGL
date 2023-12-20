#include <glad.h>
#include <glfw3.h>
#include <iostream>

int main()
{
	const unsigned int WIDTH = 500;
	const unsigned int HEIGHT = 500;

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


	//Create VAO(Vertex Array Object)
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Create VBO(Vertex Buffer Object) 
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Create EBO (Element Buffer Object)
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(window))
	{
		//Change color 
		glClearColor(0.7f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		//Swap front and back buffers
		glfwSwapBuffers(window);

		//Poll events so that it doesn't freeze
		glfwPollEvents();
	}

	//Clean VAO, VBO and shaderProgram
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}