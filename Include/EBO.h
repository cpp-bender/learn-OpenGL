#pragma once

#include <glad.h>
#include <VBO.h>


class EBO 
{
public:
	GLuint ID;
	EBO(GLuint* indices, GLsizeiptr size);

	void Bind();
	void UnBind();
	void Delete();
};
