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
	/*!
		Represents GL texture
	*/
	class Texture
	{
	public:
		/*!
			Loading & creating GL texture
			
			@param path Path to texture relative to executable
		*/
		Texture(const std::string & path);
		/*!
			Destroying GL texture
		*/
		~Texture();
		/*!
			Binding current texture to state machine
		*/
		void bind();
	private:
		GLuint texture;
	};
}