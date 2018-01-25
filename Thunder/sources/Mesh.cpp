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

#include "../include/Thunder/Mesh.hpp"

namespace thunder
{
	Mesh::Mesh(const std::vector<glm::vec3> & vertices, const std::vector<glm::vec3> & normals,
		const std::vector<unsigned int> & indices)
		: verticesCount(indices.size()), vertexBuffer(Buffer::Type::BUFFER_ARRAY),
		normalBuffer(Buffer::Type::BUFFER_ARRAY),
		elementBuffer(Buffer::Type::ELEMENT_ARRAY), vertexArray()
	{
		if (indices.size() > 0)
		{
			vertexArray.bind();

			vertexBuffer.bind();
			vertexBuffer.setData(vertices);
			vertexBuffer.enableAttrib(0, 3, GL_FLOAT);

			normalBuffer.bind();
			normalBuffer.setData(normals);
			normalBuffer.enableAttrib(1, 3, GL_FLOAT);

			elementBuffer.bind();
			elementBuffer.setData(indices);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

			glBindVertexArray(0);
		}
	}


	void Mesh::draw()
	{
		vertexArray.bind();
		elementBuffer.bind();
		glDrawElements(GL_TRIANGLES, verticesCount, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);
	}
}