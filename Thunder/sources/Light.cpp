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


#include "../include/Thunder/Light.hpp"

#include "../include/Thunder/SceneNode.hpp"
#include "../include/Thunder/SceneManager.hpp"

namespace thunder
{
	Light::Light(const glm::vec3 & color, const float & strength)
		:color(color), strength(strength)
	{
		
	}


	glm::vec3 Light::getColor()
	{
		return color;
	}


	float Light::getStrength()
	{
		return strength;
	}


	void Light::setColor(const glm::vec3 & color)
	{
		this->color = color;
	}


	void Light::setStrength(const float & strength)
	{
		this->strength = strength;
	}
}