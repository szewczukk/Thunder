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

#include "VertexArray.hpp"
#include "Buffer.hpp"

#include "NodeComponent.hpp"

namespace thunder
{
	/*!
		Represent indexed Mesh with vertices, normals, indices and uvs.
	*/
	class Mesh
		: public NodeComponent
	{
	public:
		/*!
			Creating buffers, pushing data to them

			@param vertices Verticies of Mesh
			@param normals Normals of Mesh
			@param indices The way to connect vertices to draw one single triangle
		*/
		Mesh(const std::vector<glm::vec3> & vertices, const std::vector<glm::vec3> & normals,
			 const std::vector<glm::vec2> & uvs, const std::vector<unsigned int> & indices);
		/*!
			Drawing Mesh
		*/
		void draw() override;
	private:
		Buffer vertexBuffer;
		Buffer elementBuffer;
		Buffer normalBuffer;
		Buffer uvBuffer;
		VertexArray vertexArray;

		int verticesCount;
	};
}