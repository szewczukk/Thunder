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

#include <memory>
#include <string>
#include <unordered_map>

namespace thunder
{
	class Light;
	class Camera;
	class SceneNode;
	class ShaderProgram;
	/*!
		Managing main structures of Game like Root Node, Camera, ShaderProgram.
		You can get SceneManager with Device::getSceneManager method. Use this as
		`auto sceneManager = device.getSceneManager();`
	*/
	class SceneManager
		: public std::enable_shared_from_this<SceneManager>
	{
	public:
		/*!
			Creating Modern pointers to structures

			@param windowWidth Width of window
			@param windowHeight Height of window
		*/
		SceneManager(const int & windowWidth, const int & windowHeight);
		/*!
			Use as `auto root = sceneManager->getRootNode();`
			Returning modern pointer to main node, which should have other nodes as children

			@return Modern pointer to main (root) node. 
		*/
		std::shared_ptr<SceneNode> getRootNode();
		/*!
			Use as `auto camera = sceneManager->getCamera();`

			@return Modern pointer to Camera
		*/
		std::shared_ptr<Camera> getCamera();
		/*!
			Use as `auto shaderProgram = sceneManager->getShaderProgram();`
			@return Modern pointer to ShaderProgram
		*/
		std::shared_ptr<ShaderProgram> getShaderProgram();
		/*!
			Drawing root node. This method is drawing children nodes of root too
		*/
		void drawAll();
		/*!
			Adding light to container of light to process
		*/
		void registerLight(std::shared_ptr<Light> light);
	private:
		std::shared_ptr<SceneNode> rootNode;
		std::shared_ptr<Camera> camera;
		std::shared_ptr<ShaderProgram> shaderProgram;
		std::vector<std::shared_ptr<Light>> lights;
	};
}