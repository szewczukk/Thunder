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
#include <unordered_map>

#include <vec3.hpp>

#include "Transform.hpp"

namespace thunder
{
	class ShaderProgram;
	class NodeComponent;
	class SceneManager;
	/*!
		SceneNode can representing all objects in Game like Camera, Model and others.
		To create new Node you have to add children of root node in SceneManager class.
		(SceneManager::getRootNode and SceneNode::createChildNode) 
		`auto playerNode = sceneManager->getRootNode()->createChildNode("player");`
	*/
	class SceneNode
		: public std::enable_shared_from_this<SceneNode>, public Transform
	{
	public:
		/*!
			Setting name of Node and parent of this node (in this contructor there is no parent)

			@param name Name of Node
		*/
		SceneNode(const std::string & name);
		/*!
			Setting name of Node and parent of this node

			@param name Name of Node
			@param parent Parent Node of this Node
		*/
		SceneNode(const std::string & name, std::shared_ptr<SceneNode> parent);
		/*!
			Creating child of this node. Children are updating and drawing with parent node. 
			Moving and rotating parent node is moving and rotating childern too

			@param name Name of Node to create as child
			@returns Modern pointer to created child
		*/
		std::shared_ptr<SceneNode> createChildNode(const std::string & name);
		/*!
			Deleting child with given name

			@param name Name of Node to destroy
		*/
		void destroyChildren(const std::string & name);
		/*!
			Adding object with given type as Component of this Node
			Use this as `node->appendObject<Mesh>(vertices, elements);`.
			Parametres given is variadic template and will used in creating of Component as parametres

			@tparam T Type of Component to add. Node will differentiate Component with given type
			@tparam _Types Parametres of Component to create
		*/
		template<class T, class... _Types>
		inline void appendObject(_Types&&...args)
		{
			auto object = std::make_shared<T>(args...);
			object->setParent(shared_from_this());
			objects[typeid(T).name()] = object;

			//It's here, because i can't call this method in constructor(nullptr in modern pointer in SceneManager)
			if (typeid(T).name() == typeid(Light).name())
				sceneManager->registerLight(getObject<Light>());
		}
		/*!
			Returns casted pointer from NodeComponent type.
			Node will differentiate Component with type given in appendObject method.
			You have to give same type in template as type given in appendObject to get same Component

			@tparam T Type to cast NodeComponent. This will be also indificate Component to return
			@returns Modern pointer to Component with type given in template
		*/
		template<class T>
		inline std::shared_ptr<T> getObject()
		{
			return std::dynamic_pointer_cast<T>(objects[typeid(T).name()]);
		}
		/*!
			Destroying Component with given type of Component.
			Node will differentiate Component with type given in appendObject method.

			@tparam T Type of Component to add. Node will differentiate Component with given type
		*/
		template<class T>
		inline void destroyObject()
		{
			objects.erase(typeid(T).name());
		}
		/*!
			Drawing Components and children with given shader program

			@param shaderProgram Modern pointer to shader program to set matrices
		*/
		void draw(std::shared_ptr<ShaderProgram> shaderProgram);
		/*!
			Updaing Components and children with given deltatime

			@param deltaTime Time between rendering this and previous time
		*/
		void update(const float & deltaTime);
		/*!
			@return Pointer to scene manager
		*/
		std::shared_ptr<SceneManager> getSceneManager() { return sceneManager; };
		/*!
			@param sceneManager pointer to sceneManager
		*/
		void setSceneManager(std::shared_ptr<SceneManager> sceneManager);
		/*!
			@return Parent node
		*/
		std::shared_ptr<SceneNode> getParent();
	private:
		std::unordered_map<std::string, std::shared_ptr<SceneNode>> children;
		std::unordered_map<std::string, std::shared_ptr<NodeComponent>> objects;
		std::shared_ptr<SceneNode> parent;
		std::shared_ptr<SceneManager> sceneManager;
		std::string name;
	};
}