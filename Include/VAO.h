#pragma once

#include <glad.h>
#include "VBO.h"

class VAO 
{
public:
	GLuint ID;
	VAO();

	void LinkVBO(VBO vbo, GLuint layout);
	void Bind();
	void UnBind();
	void Delete();
};
