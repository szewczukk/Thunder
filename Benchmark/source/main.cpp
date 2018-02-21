#include <Thunder/Device.hpp>

#include <Thunder/Light.hpp>
#include <Thunder/Camera.hpp>
#include <Thunder/SceneNode.hpp>
#include <Thunder/TexturedModel.hpp>

#include <Thunder/SceneManager.hpp>
#include <Thunder/EventHandler.hpp>

#undef main

using namespace thunder;

typedef std::shared_ptr<SceneNode> SceneNodePtr;

class Game : public Device
{
public:
	Game(const int & width, const int & height)
		: Device(width, height), 
		monkey(sceneManager->getRootNode()->createChildNode("monkey")),
		bunny(sceneManager->getRootNode()->createChildNode("bunny")), 
		light(sceneManager->getRootNode()->createChildNode("light"))
	{
		monkey->appendObject<TexturedModel>("res/monkey.obj", "res/texture.png");
		bunny->appendObject<TexturedModel>("res/bunny.obj", "res/texture.png");
		light->appendObject<Light>(glm::vec3(1, 1, 1), 0.001);

		camera->setPosition({ 0, 0, 10 });
		light->setPosition({ -2, -2, 2 });
		monkey->setPosition({ 1, 0, 0 });
		bunny->setPosition({ -1, -2, -5 });
	};
	
	virtual void update(const float & deltaTime) override
	{
		if (eventHandler->isKeyPressed(SDL_SCANCODE_A))
			camera->rotate({ 0, 1, 0 }, deltaTime / 100);
		if (eventHandler->isKeyPressed(SDL_SCANCODE_D))
			camera->rotate({ 0, 1, 0 }, -deltaTime / 100);
		if (eventHandler->isKeyPressed(SDL_SCANCODE_W))
			camera->move({ 0, 0, -deltaTime / 50 });
		if (eventHandler->isKeyPressed(SDL_SCANCODE_S))
			camera->move({ 0, 0, deltaTime / 50 });

		if (eventHandler->isKeyPressed(SDL_SCANCODE_LEFT))
			monkey->move({ -deltaTime / 50, 0, 0 });
		if (eventHandler->isKeyPressed(SDL_SCANCODE_RIGHT))
			monkey->move({ deltaTime / 50, 0, 0 });
	}
protected:
	SceneNodePtr monkey;
	SceneNodePtr bunny;
	SceneNodePtr light;
};

int main()
{
	Game game(800, 600);
	return game.run();
}