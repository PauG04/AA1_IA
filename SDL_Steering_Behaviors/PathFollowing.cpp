#include "PathFollowing.h"

PathFollowing::PathFollowing()
{
	currentTarget = 0;
	minDistance = 10.f;
}

void PathFollowing::ApplySteeringForce(Agent* agent, float dtime)
{
	if(path.size() == 0 || agent->getTarget() != path[path.size()-1])
	{
		path.push_back(agent->getTarget());
	}

	if (currentTarget >= path.size()) {
		agent->setSteering_force(Vector2D(0, 0));
		return;
	}

	Vector2D desiredVelocity = path[currentTarget] - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	agent->setSteering_force(desiredVelocity - agent->getVelocity());
	agent->setSteering_force(agent->getSteering_force() / agent->getMaxVelocity());
	agent->setSteering_force(agent->getSteering_force() * agent->getMaxForce());

	float distance = desiredVelocity.Distance(agent->getPosition(), path[currentTarget]);
	if (distance <= minDistance)
	{
		currentTarget++;
	}
}