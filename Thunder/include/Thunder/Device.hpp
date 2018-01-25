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

#include <SDL.h>

#include <memory>

namespace thunder
{
	class EventHandler;
	class SceneManager;
	/*!
		Managing Window, subsystems and main structures
	*/
	class Device
	{
	public:
		/*!
			Initializating Window, OpenGL and subsystems.

			@param width Width of window
			@param height Height of Window
		*/
		Device(const int & width, const int & height);
		/*!
			Destroying instances
		*/
		~Device();
		/*!
			Use as `auto sceneManager = device.getSceneManager();`
			@return Modern Pointer to SceneManager
		*/
		std::shared_ptr<SceneManager> getSceneManager();
		/*!
			Use as `auto eventHandler = device.getEventHandler();`
			@return Modern Pointer to getEventHandler
		*/
		std::shared_ptr<EventHandler> getEventHandler();
		/*!
			Clearing back buffer with color given in arguments

			@param r Proportion of Red in backbuffer color (from 0.0f to 1.0f)
			@param g Proportion of Green in backbuffer color (from 0.0f to 1.0f)
			@param b Proportion of Blue in backbuffer color (from 0.0f to 1.0f)
		*/
		void clear(const float & r, const float & g, const float & b);
		/*!
			Swapping buffers, rendering all data
		*/
		void render();
	private:
		SDL_Window * window;
		SDL_GLContext context;

		std::shared_ptr<SceneManager> sceneManager;
		std::shared_ptr<EventHandler> eventHandler;
	};
}