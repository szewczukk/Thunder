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

#include <SDL_events.h>

#include <vec2.hpp>

namespace thunder
{
	/*!
		Handling and managing events.
		You can get EventHandler with Device::getEventHandler method. Use this as
		`auto eventHandler = device.getEventHandler();`
	*/
	class EventHandler
	{
	public:
		/*!
			Polling events, returning is the new event appears
			@return 1 When event appears
		*/
		int pollEvents();
		/*!
			Checking the window quit state(clicking x button in left-up corner)
			@return True when window was closed
		*/
		bool windowState();
		/*!
			@param code ScanCode of key (SDL_SCANCODE_W for example)
			@return True when given key was pressed
		*/
		bool isKeyPressed(const int & code);
		/*!
			@return Mouse position relative to window
		*/
		glm::vec2 getMousePos();
	private:
		EventHandler();

		SDL_Event * ev;

		friend class Device;
	};
}