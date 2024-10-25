#pragma once
#include "Scene.h"
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
};

