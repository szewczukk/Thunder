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

#include <mat4x4.hpp>
#include <vec3.hpp>
#include <gtc/quaternion.hpp>

namespace thunder
{
	/*!
		Class represents objects that can moving, rotating etc.
		SceneNode or Camera is Transform objects too.
	*/
	class Transform
	{
	public:
		/*!
			Setting position and scale as (0, 0, 0) and (1, 1, 1)
		*/
		Transform()
			:position(0), scale(1)
		{};
		/*!
			Setting all properties

			@param position Poisition of Transfrom
			@param rotation Rotation of Transform
			@param scale Scale of Transform
		*/
		Transform(const glm::vec3 & position, const glm::quat & rotation, const glm::vec3 & scale);
		/*!
			Setting scale of Transform

			@param scale Scale of Transform
		*/
		void setScale(const glm::vec3 & scale);
		/*!
			Setting scale of Transform

			@param scale Scale of Transform
		*/
		void setScale(const float & scale);
		/*!
			Setting position of Transform

			@param position Position of Transform
		*/
		void setPosition(const glm::vec3 & position);
		/*!
			Setting rotation of Transform

			@param axis Axis to rotate
			@param angle Angle to rotate in given axis
		*/
		void setRotation(const glm::vec3 & axis, const float & angle);
		/*!
			Moving Transform (curent position + relative position)

			@param relative Relative position to move
		*/
		void move(const glm::vec3 & relative);
		/*!
			Rotating Transform

			@param axis Axis to rotate
			@param angle Angle of rotation
		*/
		void rotate(const glm::vec3 & axis, const float & angle);
		/*!
			@return Scale of Transform
		*/
		glm::vec3 getScale() { return scale; };
		/*!
			@return Position of Transform
		*/
		glm::vec3 getPosition() { return position; };
		/*!
			@return Rotation of Transform
		*/
		glm::quat getRotation() { return rotation; };
		/*!
			@return Multiplied matrices of position, rotation and scale
		*/
		glm::mat4 getMatrix();
	private:
		glm::vec3 scale;
		glm::vec3 position;
		glm::quat rotation;
	};
}