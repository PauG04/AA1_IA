#include "SceneAvoidance.h"

using namespace std;

SceneAvoidance::SceneAvoidance()
{
	//Agent* agent = new Agent(new Flee);
	//agent->setPosition(Vector2D(640, 360));
	//agent->setTarget(Vector2D(640, 360));
	////agent->loadSpriteTexture("../res/soldier.png", 4);
	//agents.push_back(agent);
	target = Vector2D(640, 360);
	Vector2D obstaclePos = Vector2D(100, 300);
	entity = new Entity(obstaclePos, 20);
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
			//agents[0]->setTarget(target);
		}
		break;
	default:
		break;
	}
	entity->Update();
	//agents[0]->update(dtime, event);
}

void SceneAvoidance::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	//agents[0]->draw();
}

const char* SceneAvoidance::getTitle()
{
	return "SDL Steering Behaviors :: Flee Demo";
}