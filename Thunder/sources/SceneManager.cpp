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

#include "../include/Thunder/SceneManager.hpp"

#include "../include/Thunder/SceneNode.hpp"
#include "../include/Thunder/ShaderProgram.hpp"
#include "../include/Thunder/Camera.hpp"
#include "../include/Thunder/Light.hpp"

#include <gtc/matrix_transform.hpp>
#include <glm.hpp>

namespace thunder
{
	SceneManager::SceneManager(const int & windowWidth, const int & windowHeight)
		: camera(std::shared_ptr<Camera>(new Camera(windowWidth, windowHeight))),
		shaderProgram(std::shared_ptr<ShaderProgram>(new ShaderProgram("res/vertexShader.glsl", "res/fragmentShader.glsl"))),
		rootNode(std::shared_ptr<SceneNode>(new SceneNode("root")))
	{
	}


	std::shared_ptr<SceneNode> SceneManager::getRootNode()
	{
		return rootNode;
	}


	std::shared_ptr<Camera> SceneManager::getCamera()
	{
		return camera;
	}


	std::shared_ptr<ShaderProgram> SceneManager::getShaderProgram()
	{
		return shaderProgram;
	}


	void SceneManager::drawAll()
	{
		shaderProgram->setUniformMatrix("uPerspective", camera->getMatrix());
		shaderProgram->setUniformVec3("uModelColor", { 1, 1, 1 });
		shaderProgram->setUniformVec3("uViewPosition", camera->getPosition());

		for (int i = 0; i < lights.size(); i++)
		{
			shaderProgram->setUniformVec3("uLight[" + std::to_string(i) +"].position", lights[i]->getParent()->getPosition());
			shaderProgram->setUniformVec3("uLight[" + std::to_string(i) + "].color", lights[i]->getColor());
			shaderProgram->setFloatUniform("uLight[" + std::to_string(i) +"].strength", lights[i]->getStrength());
		}

		rootNode->draw(shaderProgram);
	}


	void SceneManager::registerLight(std::shared_ptr<Light> light)
	{
		lights.push_back(light);
	}
}