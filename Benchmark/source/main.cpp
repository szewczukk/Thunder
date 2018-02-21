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

		camera->setPosition({ 0, 0, 10 });
	
		light->setPosition({ -2, -2, 2 });
		light->appendObject<Light>(glm::vec3(1, 1, 1), 0.001);

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
	std::shared_ptr<SceneNode> monkey;
	std::shared_ptr<SceneNode> bunny;
	std::shared_ptr<SceneNode> light;
};

int main()
{
	Game game(800, 600);
	return game.run();
}