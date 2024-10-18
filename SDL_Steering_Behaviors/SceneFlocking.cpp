#include "SceneFlocking.h"
#include "Flocking.h"

SceneFlocking::SceneFlocking()
{
	for (int i = 0; i < 10; i++)
	{
		Agent* agent = new Agent(new Flocking);
		float n = 300 + i * 100;
		agent->setPosition(Vector2D(n, 360));
		agent->setTarget(Vector2D(640, 360));
		//agent->loadSpriteTexture("../res/soldier.png", 4);
		agents.push_back(agent);
	}

	target = Vector2D(640, 360);
}

SceneFlocking::~SceneFlocking()
{

}

void SceneFlocking::update(float dtime, SDL_Event* event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			target = Vector2D((float)(event->button.x), (float)(event->button.y));
			for (Agent* agent : agents)
			{
				agent->setTarget(target);
			}
		}
		break;
	default:
		break;
	}

	for (Agent* agent : agents)
	{
		agent->SearchNeighbours(agents);
		agent->update(dtime, event);
	}
}

void SceneFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	for (Agent* agent : agents)
	{
		agent->draw();
	}
}

const char* SceneFlocking::getTitle()
{
	return "SDL Steering Behaviors :: Flocking Demo";
}
