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

#include "../include/Thunder/Transform.hpp"

#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <gtx/quaternion.hpp>

namespace thunder
{
	Transform::Transform(const glm::vec3 & position, const glm::quat & rotation, const glm::vec3 & scale)
		:position(position), rotation(rotation), scale(scale)
	{
	}


	void Transform::setScale(const glm::vec3 & scale)
	{
		this->scale = scale;
	}


	void Transform::setScale(const float & scale)
	{
		this->scale = glm::vec3(scale);
	}


	void Transform::setPosition(const glm::vec3 & position)
	{
		this->position = position;
	}


	void Transform::setRotation(const glm::vec3 & axis, const float & angle)
	{
		rotation = glm::rotate(angle, axis);
	}


	void Transform::move(const glm::vec3 & relative)
	{
		setPosition(position + relative);
	}


	void Transform::rotate(const glm::vec3 & axis, const float & angle)
	{
		rotation = glm::rotate(rotation, angle, axis);
	}


	glm::mat4 Transform::getMatrix()
	{
		return glm::translate(position) * glm::toMat4(rotation) * glm::scale(scale);
	}
}