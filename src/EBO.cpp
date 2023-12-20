#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
	glGenBuffers(1, &ID);
}

void EBO::UnBind()
{
	glGenBuffers(1, 0);
}

void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}