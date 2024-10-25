#pragma once
#include <iostream>
#include <SDL.h>
#include "Agent.h"

class Scene
{
protected:
	std::vector<Agent*> agents;
	Vector2D target;

public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };
};

