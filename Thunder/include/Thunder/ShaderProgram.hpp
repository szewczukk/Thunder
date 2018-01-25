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

#pragma once

#include "Shader.hpp"

#include <vector>
#include <memory>

#include <mat4x4.hpp>

namespace thunder
{
	/*!
		Storages Vertex and Fragment shader and operates on them
	*/
	class ShaderProgram
	{
	public:
		/*!
			Initializing Vertex and Fragment shader, creating GL program, then shaders will be destroyed, but shader program will be correct.
			@param vertexShaderFilePath Relative path to vertex shader file
			@param fragmentShaderFilePath Relative path to fragment shader file
		*/
		ShaderProgram(const std::string & vertexShaderFilePath, 
			const std::string & fragmentShaderFilePath);
		/*!
			Destroying shader program
		*/
		~ShaderProgram();
		/*!
			Using this shader as current. Now all uniforms will be added, and everything objects will be rendered with this shader.
		*/
		void use();
		/*!
			Setting matrix uniform at shader program

			@param name Name of uniform variable in shader
			@param matrix Value of uniform variable
		*/
		void setUniformMatrix(const std::string & name, const glm::mat4 & matrix);
		/*!
			Setting vector uniform at shader program

			@param name Name of uniform variable in shader
			@param matrix Value of uniform variable
		*/
		void setUniformVec3(const std::string & name, const glm::vec3 & vector);
		/*!
			Setting floating variable uniform at shader program

			@param name Name of uniform variable in shader
			@param matrix Value of uniform variable
		*/
		void setFloatUniform(const std::string & name, const float & value);
		/*!
			Setting integer variable uniform at shader program

			@param name Name of uniform variable in shader
			@param matrix Value of uniform variable
		*/
		void setIntegerUniform(const std::string & name, const int & value);
	private:
		GLuint getUniformLocation(const std::string & uniform);
	private:
		GLuint program;
		std::vector<std::shared_ptr<Shader>> shaders;
	};
}