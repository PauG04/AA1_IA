#include "FlockingAvoidance.h"
#include "Flocking.h"
#include "Avoidance.h"

FlockingAvoidance::FlockingAvoidance()
{
	priorityList = new PriorityList;
	priorityList->AddSteeringBehavior(new Avoidance);
	priorityList->AddSteeringBehavior(new Flocking);
}

Vector2D FlockingAvoidance::ApplySteeringForce(Agent* agent, float dtime)
{
	return priorityList->ApplySteeringForce(agent, dtime);
}
