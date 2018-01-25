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

#include "../include/Thunder/Model.hpp"

#include <assert.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/mesh.h>

#include <vec2.hpp>

namespace thunder
{
	struct Face
	{
		int vertex;
		int normal;
		int uv;
	};

	Model::Model(const std::string & path)
	{
		/*
			std::vector<glm::vec3> temp_vertices;
		std::vector<glm::vec3> temp_normals;
		std::vector<glm::vec2> temp_uvs;
		std::vector<Face> faces;

		std::ifstream file(path);
		assert(file.good());

		std::string line;

		while (std::getline(file, line))
		{
			std::istringstream stream(line.substr(2));
			if (line.substr(0, 2) == "# ") continue;
			if (line.substr(0, 2) == "v ")
			{
				glm::vec3 vector;
				stream >> vector.x;
				stream >> vector.y;
				stream >> vector.z;

				temp_vertices.push_back(vector);
			}
			else if (line.substr(0, 2) == "vt")
			{
				glm::vec2 vector;
				stream >> vector.x;
				stream >> vector.y;

				temp_uvs.push_back(vector);
			}
			else if (line.substr(0, 2) == "vn")
			{
				glm::vec3 vector;
				stream >> vector.x;
				stream >> vector.y;
				stream >> vector.z;

				temp_normals.push_back(vector);
			}
			else if (line.substr(0, 2) == "f ")
			{
				std::replace(line.begin(), line.end(), '/', ' ');
				stream = std::istringstream(line.substr(2));
				for (int i = 0; i < 3; i++)
				{
					Face face;
					stream >> face.vertex >> face.normal >> face.uv;
					face.vertex--;
					face.normal--;
					face.uv--;
					faces.push_back(face);
				}
			}
		}

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		std::vector<unsigned int> indices;

		for (int i = 0; i < faces.size(); i++)
		{
			Face face = faces[i];
			vertices.push_back(temp_vertices[face.vertex]);
			normals.push_back(temp_normals[face.normal]);
			uvs.push_back(temp_uvs[face.uv]);
		}

		temp_normals.clear();
		temp_uvs.clear();
		temp_vertices.clear();
		faces.clear();

#ifdef _DEBUG
		std::cout << " ---------------------------------------- " << std::endl;
		std::cout << " -- " << path << " model loding" << std::endl;
		std::cout << " -- " << vertices.size() << " vertices" << std::endl;
		std::cout << " -- " << normals.size() << " normals" << std::endl;
		std::cout << " -- " << uvs.size() << " uvs" << std::endl;
		std::cout << " -- " << faces.size() << " faces" << std::endl;
#endif

		mesh = new Mesh(vertices, indices);

		vertices.clear();
		indices.clear();
		normals.clear();
		uvs.clear();
		*/

		/*std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		std::vector<unsigned int> verticesIndex;
		std::vector<Face> indices;

		std::ifstream file(path);
		assert(file.good());

		std::string line;

		while (std::getline(file, line))
		{
			std::istringstream stream(line.substr(2));
			if (line.substr(0, 2) == "# ") continue;
			if (line.substr(0, 2) == "v ")
			{
				glm::vec3 vector;
				stream >> vector.x;
				stream >> vector.y;
				stream >> vector.z;

				vertices.push_back(vector);
			}
			else if (line.substr(0, 2) == "vt")
			{
				glm::vec2 vector;
				stream >> vector.x;
				stream >> vector.y;

				uvs.push_back(vector);
			}
			else if (line.substr(0, 2) == "vn")
			{
				glm::vec3 vector;
				stream >> vector.x;
				stream >> vector.y;
				stream >> vector.z;

				normals.push_back(vector);
			}
			else if (line.substr(0, 2) == "f ")
			{
				std::replace(line.begin(), line.end(), '/', ' ');
				stream = std::istringstream(line.substr(2));
				for (int i = 0; i < 3; i++)
				{
					Face face;
					stream >> face.vertex >> face.normal >> face.uv;
					face.vertex--;
					indices.push_back(face);
					verticesIndex.push_back(face.vertex);
				}
			}
		}

#ifdef _DEBUG
		std::cout << " ---------------------------------------- " << std::endl;
		std::cout << " -- " << path << " model loding" << std::endl;
		std::cout << " -- " << vertices.size() << " vertices" << std::endl;
		std::cout << " -- " << normals.size() << " normals" << std::endl;
		std::cout << " -- " << uvs.size() << " uvs" << std::endl;
		std::cout << " -- " << verticesIndex.size() / 3 << " faces" << std::endl;
#endif

		mesh = new Mesh(vertices, normals, verticesIndex);

		uvs.clear();
		normals.clear();
		indices.clear();
		vertices.clear();
		verticesIndex.clear();*/

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec3> normals;
		std::vector<glm::vec2> uvs;
		std::vector<unsigned int> indices;

		Assimp::Importer importer;
		const aiScene * scene = importer.ReadFile(path, 0);
		const aiMesh * aMesh = scene->mMeshes[0];

		for (int i = 0; i < aMesh->mNumVertices; i++)
		{
			vertices.push_back(glm::vec3(aMesh->mVertices[i].x, aMesh->mVertices[i].y, aMesh->mVertices[i].z));
		}

		for (int i = 0; i < aMesh->mNumVertices; i++)
		{
			normals.push_back(glm::vec3(aMesh->mNormals[i].x, aMesh->mNormals[i].y, aMesh->mNormals[i].z));
		}

		for (int i = 0; i < aMesh->mNumVertices; i++)
		{
			uvs.push_back(glm::vec2(aMesh->mTextureCoords[0][i].x, aMesh->mTextureCoords[0][i].y));
		}

		for (int i = 0; i < aMesh->mNumFaces; i++)
		{
			indices.push_back(aMesh->mFaces[i].mIndices[0]);
			indices.push_back(aMesh->mFaces[i].mIndices[1]);
			indices.push_back(aMesh->mFaces[i].mIndices[2]);
		}

		mesh = new Mesh(vertices, normals, indices);

		vertices.clear();
		normals.clear();
		indices.clear();
	}


	void Model::draw()
	{
		mesh->draw();
	}
}