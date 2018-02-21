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

#include "../include/Thunder/Device.hpp"

#include "../include/Thunder/SceneNode.hpp"
#include "../include/Thunder/EventHandler.hpp"
#include "../include/Thunder/SceneManager.hpp"
#include "../include/Thunder/ShaderProgram.hpp"

#include <GL/glew.h>
#include <assert.h>

namespace thunder
{
	Device::Device(const int & width, const int & height)
		:eventHandler(std::shared_ptr<EventHandler>(new EventHandler))
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		window = SDL_CreateWindow("Render Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_OPENGL);
		assert(window != NULL);

		context = SDL_GL_CreateContext(window);
		assert(context != NULL);

		glewExperimental = true;
		assert(glewInit() == GLEW_OK);

		//It here, because if it was on initializing list, then initializing shader program isn't working
		sceneManager = std::shared_ptr<SceneManager>(new SceneManager(width, height));
		sceneManager->getRootNode()->setSceneManager(sceneManager);

		camera = sceneManager->getCamera();

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}


	Device::~Device()
	{
		SDL_GL_DeleteContext(context);
		SDL_DestroyWindow(window);
	}


	std::shared_ptr<SceneManager> Device::getSceneManager()
	{
		return sceneManager;
	}


	std::shared_ptr<EventHandler> Device::getEventHandler()
	{
		return eventHandler;
	}


	void Device::clear(const float & r, const float & g, const float & b)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(r, g, b, 0.0f);

		sceneManager->getShaderProgram()->use();
	}


	void Device::render()
	{
		SDL_GL_SwapWindow(window);
	}


	int Device::run()
	{
		float now = 0, last = 0, delta = 0;

		bool quit = false;
		while (!quit)
		{
			now = SDL_GetTicks();
			delta = now - last;
			last = now;

			while (eventHandler->pollEvents())
			{
				if (eventHandler->windowState())
					quit = true;
			}

			update(delta);

			clear(0.1f, 0.2f, 0.2f);

			sceneManager->drawAll();

			render();
		}

		return 0;
	}
}