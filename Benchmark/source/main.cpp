#include <Thunder/Device.hpp>
#include <Thunder/EventHandler.hpp>
#include <Thunder/SceneManager.hpp>
#include <Thunder/SceneNode.hpp>
#include <Thunder/NodeComponent.hpp>
#include <Thunder/Mesh.hpp>
#include <Thunder/Model.hpp>
#include <Thunder/Camera.hpp>
#include <Thunder/ShaderProgram.hpp>
#include <Thunder/Light.hpp>
#include <Thunder/TexturedModel.hpp>

#undef main

using namespace thunder;

int main()
{
	Device device(800, 600);

	auto sceneManager = device.getSceneManager();
	auto eventHandler = device.getEventHandler();

	auto camera = sceneManager->getCamera();

	camera->setPosition({ 0, 0, 10 });

	auto monkey = sceneManager->getRootNode()->createChildNode("monkey");
	monkey->appendObject<TexturedModel>("res/monkey.obj", "res/texture.png");

	auto bunny = sceneManager->getRootNode()->createChildNode("bunny");
	bunny->appendObject<Model>("res/bunny.obj");

	auto light = sceneManager->getRootNode()->createChildNode("light");
	light->setPosition({ -2, -2, 2 });
	light->appendObject<Light>(glm::vec3(1, 1, 1), 0.001);

	monkey->setPosition({ 1, 0, 0 });
	bunny->setPosition({ -1, -2, -5 });

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
		
		if (eventHandler->isKeyPressed(SDL_SCANCODE_A))
			camera->rotate({ 0, 1, 0 }, delta / 100);
		if (eventHandler->isKeyPressed(SDL_SCANCODE_D))
			camera->rotate({ 0, 1, 0 }, -delta / 100);
		if (eventHandler->isKeyPressed(SDL_SCANCODE_W))
			camera->move({ 0, 0, -delta / 50 });
		if (eventHandler->isKeyPressed(SDL_SCANCODE_S))
			camera->move({ 0, 0, delta / 50 });

		if (eventHandler->isKeyPressed(SDL_SCANCODE_LEFT))
			monkey->move({ -delta / 50, 0, 0 });
		if (eventHandler->isKeyPressed(SDL_SCANCODE_RIGHT))
			monkey->move({ delta / 50, 0, 0 });

		device.clear(0.1f, 0.2f, 0.2f);

		sceneManager->drawAll();

		device.render();
	}

	return 0;
}