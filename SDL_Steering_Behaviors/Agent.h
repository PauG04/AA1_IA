#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"
#include "SteeringBehavior.h"
#include "Entity.h"

class Agent
{
	friend class SteeringBehavior;

private:
	SteeringBehavior *steering_behavior;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;
	Vector2D steering_force;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;
	float avoidanceLookAhead;

	SDL_Color color;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;
	std::vector<Agent*> neighbours;
	float neighbourRadius;

	std::vector<Entity*> entities;

public:
	Agent(SteeringBehavior *steering_behavior);
	~Agent();
	SteeringBehavior *Behavior();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	Vector2D getSteering_force();
	float getMaxVelocity();
	float getMaxForce();
	float GetAvoidanceLookAhead();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setSteering_force(Vector2D steering_force);
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);
	void SearchNeighbours(std::vector<Agent*> agents);
	std::vector<Agent*> GetNeighbours();
	inline void AddEntites(std::vector<Entity*> _entities) { entities = _entities; }
	inline std::vector<Entity*> GetEntities() { return entities; }
	 
};
