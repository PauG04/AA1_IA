#pragma once
#include "Scene.h"

class ScenePathFollowing :
	public Scene
{
public:
	ScenePathFollowing();
	~ScenePathFollowing();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
};
