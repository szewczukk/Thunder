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
#include <matrix.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/quaternion.hpp>

namespace thunder
{
	class Camera
	{
	public:
		/*!
			Setting attributes

			@param width Width of window
			@param height Height of window
		*/
		Camera(const int & width, const int & height);
		/*!
			Setting new position of Camera

			@param position New position of Camera
		*/
		void setPosition(const glm::vec3 & position);
		/*!
			Moving camera (current position + relative)

			@param relative Relative position to current
		*/
		void move(const glm::vec3 & relative);
		/*!
			@return Position of Camera
		*/
		glm::vec3 getPosition();
		/*!
			@return Matrix of Camera to use in shader
		*/
		glm::mat4 getMatrix();
		/*!
			Setting rotation of Transform

			@param axis Axis to rotate
			@param angle Angle to rotate in given axis
		*/
		void setRotation(const glm::vec3 & axis, const float & angle);
		/*!
			Rotating Transform

			@param axis Axis to rotate
			@param angle Angle of rotation
		*/
		void rotate(const glm::vec3 & axis, const float & angle);
	private:
		glm::vec2 size;

		glm::quat rotation;

		glm::vec3 position;
		glm::vec3 up;
	};
}