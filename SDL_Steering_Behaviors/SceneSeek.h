#pragma once
#include "Scene.h"

class SceneSeek :
	public Scene
{
public:
	SceneSeek();
	~SceneSeek();
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
};

