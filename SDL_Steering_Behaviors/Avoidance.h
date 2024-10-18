#pragma once
#include "SteeringBehavior.h"
#include "Entity.h"
#include "Flee.h"
class Avoidance : public SteeringBehavior
{
private:
	Flee* fleeBehaviour;
public:
	Avoidance();
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

