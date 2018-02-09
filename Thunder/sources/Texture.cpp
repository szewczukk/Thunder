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

#include "..\include\Thunder\Texture.hpp"

#include <FreeImage.h>

namespace thunder
{
	Texture::Texture(const std::string & path)
	{
		//Loading
		FreeImage_Initialise();
		FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(path.data()), path.data());
		FIBITMAP* bitmap32 = FreeImage_ConvertTo32Bits(bitmap);

		FreeImage_Unload(bitmap);

		//Creating
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FreeImage_GetWidth(bitmap32), FreeImage_GetHeight(bitmap32), 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)FreeImage_GetBits(bitmap32));

		FreeImage_Unload(bitmap32);
		FreeImage_DeInitialise();
	}


	Texture::~Texture()
	{
		glDeleteTextures(1, &texture);
	}


	void Texture::bind()
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
}