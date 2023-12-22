#pragma once

#include <glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>


class Shader 
{
public:
	GLuint ID;
	Shader();
	void Activate();
	void Delete();
};