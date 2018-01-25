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

#include "../include/Thunder/Camera.hpp"

#include <gtc/matrix_transform.hpp>
#include <gtx/transform.hpp>
#include <gtx/quaternion.hpp>

namespace thunder
{
	Camera::Camera(const int & width, const int & height)
		: size(width, height), position(0, 0, 1), up(0, 1, 0)
	{
	}


	void Camera::setPosition(const glm::vec3 & position)
	{
		this->position = position;
	}


	void Camera::move(const glm::vec3 & relative)
	{
		position += relative;
	}


	glm::vec3 Camera::getPosition()
	{
		return position;
	}


	glm::mat4 Camera::getMatrix()
	{
		return glm::perspective(glm::radians(45.f), float(size.x / size.y), 0.1f, 100.f) * 
			(glm::lookAt(position, glm::vec3(0, 0, 0), up) * glm::toMat4(rotation));
	}


	void Camera::setRotation(const glm::vec3 & axis, const float & angle)
	{
		rotation = glm::rotate(angle, axis);
	}


	void Camera::rotate(const glm::vec3 & axis, const float & angle)
	{
		rotation = glm::rotate(rotation, angle, axis);
	}
}