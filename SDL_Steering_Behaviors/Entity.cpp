#include "Entity.h"
#include "utils.h"
#include "SDL_SimpleApp.h"

Entity::Entity(Vector2D _position, float _radius)
{ 
	position = _position;
	radius = _radius;

	Draw();
}

void Entity::Draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, radius, 0, 255, 255, 100);
	SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(100), (int)(100));
}

void Entity::Update()
{
	Draw();
}
