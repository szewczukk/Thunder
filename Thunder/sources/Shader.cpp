/*
	Copyright (C) 2018 Dmitro Szewczuk

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
	Also add information on how to contact you by electronic and paper mail.
*/

#include "../include/Thunder/Shader.hpp"

#include <fstream>
#include <assert.h>

#include <iostream>

namespace thunder
{
	Shader::Shader(const std::string & path, const Type & type)
	{
		std::ifstream file(path);
		assert(file.good());

		std::string line;
		std::string fileContent = "";
		while (std::getline(file, line))
		{
			fileContent += line + "\n";
		}

		file.close();
		
		GLenum shaderType;
		if (type == Shader::Type::VERTEX)
			shaderType = GL_VERTEX_SHADER;
		else if (type == Shader::Type::FRAGMENT)
			shaderType = GL_FRAGMENT_SHADER;
		else if (type == Shader::Type::GEOMETRY)
			shaderType = GL_GEOMETRY_SHADER;

		shader = glCreateShader(shaderType);

		const char * fileContentCString = fileContent.data();
		glShaderSource(shader, 1, &fileContentCString, nullptr);
		glCompileShader(shader);
	}


	Shader::~Shader()
	{
		glDeleteShader(shader);
	}
}