#pragma once
#include "Scene.h"

class SceneFlocking :
    public Scene
{
public:
	SceneFlocking();
	~SceneFlocking();
	void update(float dtime, SDL_Event* event);
	void draw();
	const char* getTitle();
};

