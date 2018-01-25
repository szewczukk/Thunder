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

#include <vec3.hpp>
#include <memory>

#include "NodeComponent.hpp"

namespace thunder
{
	class SceneNode;
	/*!
		Represents Light in Scene, processed in SceneManager in drawAll() method
	*/
	class Light
		: public NodeComponent, public std::enable_shared_from_this<Light>
	{
	public:
		/*!
			Setting all attributes

			@param color Color of light in RGB
			@param strength Insensitivity of light
		*/
		Light(const glm::vec3 & color, const float & strength);
		/*!
			@return Color of ligth in RGB
		*/
		glm::vec3 getColor();
		/*!
			@return Insensitivity of light
		*/
		float getStrength();
		/*!
			@param color Color of light in RGB
		*/
		void setColor(const glm::vec3 & color);
		/*!
			@param strength Insensitivity of light
		*/
		void setStrength(const float & strength);
	private:
		glm::vec3 color;
		float strength;
	};
}