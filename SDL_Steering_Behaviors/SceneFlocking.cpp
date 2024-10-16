#include "SceneFlocking.h"
#include "Flocking.h"

SceneFlocking::SceneFlocking()
{
	
	for (int i = 0; i < 10; i++)
	{
		Agent* agent = new Agent(new Flocking);
		agent->setPosition(Vector2D(640, 360));
		agent->setTarget(Vector2D(640, 360));
		//agent->loadSpriteTexture("../res/soldier.png", 4);
		AGENT_MANAGER.Instance().AddAgent(agent);
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
			for (Agent* agent : AGENT_MANAGER.Instance().GetAgents())
			{
				agent->setTarget(target);
			}
		}
		break;
	default:
		break;
	}

	for (Agent* agent : AGENT_MANAGER.Instance().GetAgents())
	{
		
		agent->update(dtime, event);
	}
}

void SceneFlocking::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)target.x, (int)target.y, 15, 255, 0, 0, 255);
	AGENT_MANAGER.Instance().GetAgents()[0]->draw();
}

const char* SceneFlocking::getTitle()
{
	return "SDL Steering Behaviors :: PathFollowing Demo";
}
