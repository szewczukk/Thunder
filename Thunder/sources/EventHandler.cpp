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

#include "../include/Thunder/EventHandler.hpp"

namespace thunder
{
	EventHandler::EventHandler()
		:ev(new SDL_Event())
	{
	}


	int EventHandler::pollEvents()
	{
		return SDL_PollEvent(ev);
	}


	bool EventHandler::windowState()
	{
		return ev->type == SDL_QUIT;
	}


	bool EventHandler::isKeyPressed(const int & code)
	{
		return SDL_GetKeyboardState(NULL)[code] != 0;;
	}


	glm::vec2 EventHandler::getMousePos()
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		return glm::vec2(x, y);
	}
}