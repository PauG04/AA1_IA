#pragma once
#include <vector>
#include "Scene.h"
#include "Agent.h"
#include "Entity.h"

class SceneAvoidance :
	public Scene
{
public:
	SceneAvoidance();
	~SceneAvoidance();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
private:
	std::vector<Agent*> agents;
	Vector2D target;
	Entity *entity;
};

