#include "PathFollowing.h"

PathFollowing::PathFollowing()
{
	currentTarget = 0;
	minDistance = 0.1f;
}

void PathFollowing::ApplySteeringForce(Agent* agent, float dtime)
{
	if (currentTarget >= path.size())
		return;

	if (path[currentTarget] == agent->getTarget())
		return;

	path.push_back(agent->getTarget());

	Vector2D desiredVelocity = agent->getTarget() - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	agent->setSteering_force(desiredVelocity - agent->getVelocity());
	agent->setSteering_force(agent->getSteering_force() / agent->getMaxVelocity());
	agent->setSteering_force(agent->getSteering_force() * agent->getMaxForce());

	float distance = desiredVelocity.Distance(agent->getPosition(), path[currentTarget]);
	if (distance < minDistance)
	{
		currentTarget++;
	}
}