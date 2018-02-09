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
#include <iostream>

namespace thunder
{
	class ShaderProgram;
	class SceneNode;
	/*!
		Functionality that is adding to SceneNode. For example Model Component adding rendering Model functionality
		Node you can add using SceneNode::appendObject method. Use this as:
		`node->appendObject<Model>("model.obj");`
	*/
	class NodeComponent
	{
	public:
		/*!
			Setting parent of this Object. This method is usually called from SceneNode class in appendObject method
			@param node Modern pointer to parent node
		*/
		void setParent(const std::shared_ptr<SceneNode> & node);
		/*!
			Drawing Component
		*/
		virtual void draw() {};
		/*!
			@return The SceneNode where NodeComponent is
		*/
		std::shared_ptr<SceneNode> getParent();
	private:
		std::shared_ptr<SceneNode> node;
	};
}