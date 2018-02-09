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

#include "../include/Thunder/ShaderProgram.hpp"

#include <gtc/type_ptr.hpp>

#include <iostream>

namespace thunder
{
	ShaderProgram::ShaderProgram(const std::string & vertexShaderFilePath, const std::string & fragmentShaderFilePath)
	{
		shaders.push_back(std::make_shared<Shader>(vertexShaderFilePath, Shader::Type::VERTEX));
		shaders.push_back(std::make_shared<Shader>(fragmentShaderFilePath, Shader::Type::FRAGMENT));

		program = glCreateProgram();

		for (auto & shader : shaders)
		{
			glAttachShader(program, shader->shader);
		}

		glLinkProgram(program);

		for (auto & shader : shaders)
		{
			glDetachShader(program, shader->shader);
		}

		shaders.clear();
	}


	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(program);
	}


	void ShaderProgram::use()
	{
		glUseProgram(program);
	}


	void ShaderProgram::setUniformMatrix(const std::string & name, const glm::mat4 & matrix)
	{
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
	}


	void ShaderProgram::setUniformVec3(const std::string & name, const glm::vec3 & vector)
	{
		glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
	}


	void ShaderProgram::setFloatUniform(const std::string & name, const float & value)
	{
		glUniform1f(getUniformLocation(name), value);
	}


	void ShaderProgram::setIntegerUniform(const std::string & name, const int & value)
	{
		glUniform1i(getUniformLocation(name), value);
	}


	GLuint ShaderProgram::getUniformLocation(const std::string & uniform)
	{
		GLuint location = glGetUniformLocation(program, uniform.data());

		if(location < 0)
		{
			std::cout << uniform + " uniform can't be founded" << std::endl;
			//TODO: Error handling
		}
		return location;
	}
}