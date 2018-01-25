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

#include <string>

#include <GL/glew.h>

namespace thunder
{
	/*
		Storing GL instance of shader with specified type
	*/
	class Shader
	{
	public:
		/*!
			Specify type of Shader
		*/
		enum Type
		{
			VERTEX,
			FRAGMENT,
			GEOMETRY
		};
		/*!
			Initializing Shader
			@param path Relative path to shader file
			@param type Type of Shader
		*/
		Shader(const std::string & path, const Type & type);
		/*!
			Destroying shader
		*/
		~Shader();
	private:
		GLuint shader;

		friend class ShaderProgram;
	};
}