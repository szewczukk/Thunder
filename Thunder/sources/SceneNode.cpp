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

#include "../include/Thunder/SceneNode.hpp"

#include "../include/Thunder/NodeComponent.hpp"
#include "../include/Thunder/ShaderProgram.hpp"

namespace thunder
{
	SceneNode::SceneNode(const std::string & name)
		:SceneNode(name, NULL)
	{
	}


	SceneNode::SceneNode(const std::string & name, std::shared_ptr<SceneNode> parent)
		:children(), objects(), parent(parent), name(name)
	{
	}


	std::shared_ptr<SceneNode> SceneNode::createChildNode(const std::string & name)
	{
		children[name] = std::shared_ptr<SceneNode>(new SceneNode(name, shared_from_this()));
		children[name]->setSceneManager(sceneManager);
		return children[name];
	}


	void SceneNode::destroyChildren(const std::string & name)
	{
		children.erase(name);
	}


	void SceneNode::draw(std::shared_ptr<ShaderProgram> shaderProgram)
	{
		shaderProgram->setUniformMatrix("mTransform", getMatrix());
		for (auto & obj : objects)
		{
			obj.second->draw();
		}
		for (auto & child : children)
		{
			child.second->draw(shaderProgram);
		}
	}


	void SceneNode::update(const float & deltaTime)
	{
		for (auto & obj : objects)
		{
			obj.second->update(deltaTime);
		}
		for (auto & child : children)
		{
			child.second->update(deltaTime);
		}
	}


	void SceneNode::setSceneManager(std::shared_ptr<SceneManager> sceneManager)
	{
		this->sceneManager = sceneManager;
	}


	std::shared_ptr<SceneNode> SceneNode::getParent()
	{
		return parent;
	}
}