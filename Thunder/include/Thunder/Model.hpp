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

#include "NodeComponent.hpp"
#include "Mesh.hpp"

namespace thunder
{
	class TexturedModel;
	/*!
		Represents Model loaded from external file 
	*/
	class Model
		: public NodeComponent
	{
	public:
		/*!
			Loading Model
			@param path Path to model file
		*/
		Model(const std::string & path);
		/*!
			Converting untextured model to textured model
			@param texturePath Path to texture
			@return Converted model
		*/
		TexturedModel convertToTexturedModel(const std::string & texturePath);
		/*!
			Drawing model
		*/
		virtual void draw() override;
	private:
		Mesh * mesh;
		std::string modelPath;
	};
}