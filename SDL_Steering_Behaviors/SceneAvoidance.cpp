#include "SceneAvoidance.h"
#include "FlockingAvoidance.h"
using namespace std;

SceneAvoidance::SceneAvoidance()
{
	
	std::vector<Entity*> entities;
	for (int i = 0; i < 2; i++)
	{
		Vector2D obstaclePos = Vector2D(100 + (200 * i), 300);
		entities.push_back(new Entity(obstaclePos, 50));
	}

	for (int i = 0; i < 10; i++)
	{
		Agent* agent = new Agent(new FlockingAvoidance);
		float n = 300 + i * 100;
		agent->setPosition(Vector2D(n, 360));
		agent->setTarget(Vector2D(640, 360));
		agent->AddEntites(entities);
		//agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
	}

	target = Vector2D(640, 360);

	

}

SceneAvoidance::~SceneAvoidance()
{
	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneAvoidance::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (Agent* agent : agents)
				agent->setTarget(target);
		}
		break;
	default:
		break;
	}

	for (Agent* agent : agents)
		agent->update(dtime, event);

	for (Entity* entity : agents[0]->GetEntities())
		entity->Update();

}

void SceneAvoidance::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);

	for (Agent* agent : agents)
		agent->draw();
}

const char* SceneAvoidance::getTitle()
{
	return "SDL Steering Behaviors :: Avoidance Demo";
}