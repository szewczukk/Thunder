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

#include <vector>

#include <GL/glew.h>

namespace thunder
{
	/*!
		Represents OpenGL buffer, used in mesh.
	*/
	class Buffer
	{
	public:
		/*!
			Type of buffer
		*/
		enum Type
		{
			BUFFER_ARRAY,
			ELEMENT_ARRAY
		};
		/*!
			Generating buffer

			@param type Type of buffer
		*/
		Buffer(const Type & type);
		/*!
			Destroying buffer
		*/
		~Buffer();
		/*!
			Binding this buffer to state machine
		*/
		void bind();
		/*!
			Enabling attribute in shaders
			Example:
			`normalBuffer.enableAttrib(1, 3, GL_FLOAT);`

			@param index Index of Attribute in shaders
			@param size Size of attribute(if this is vec3, give 3, if this vec2, give 2)
			@param type Type like GL_FLOAT or GL_UNSIGNED_INT
		*/
		void enableAttrib(const int & index, const int & size, const GLenum & type);
		/*!
			Setting data to buffer
		
			@tparam T Type of vector of data
			@param data Vector of data
		*/
		template<typename T>
		inline void setData(const std::vector<T> & data)
		{
			bind();

			glBufferData(bufferType, sizeof(T) * data.size(), &data[0], GL_STATIC_DRAW);
		}
	private:
		GLuint buffer;
		GLenum bufferType;
	};
}