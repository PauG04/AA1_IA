#pragma once
#include "SteeringBehavior.h"
#include <vector>

class Flocking : public SteeringBehavior
{
private:
	Vector2D separationDirection, cohesionDirection, allignmentDirection;
	int neighbourCount;

public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
	void Flee(Agent* agent, float dtime, std::vector<Agent*> agents);
	void Seek(Agent* agent, float dtime, std::vector<Agent*> agents);
	void Alignment(Agent* agent, float dtime, std::vector<Agent*> agents);
};

