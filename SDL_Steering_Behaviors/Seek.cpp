#include "Seek.h"

void Seek::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D desiredVelocity = agent->getTarget() - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	agent->setSteering_force(desiredVelocity - agent->getVelocity());
	agent->setSteering_force(agent->getSteering_force() / agent->getMaxVelocity());
	agent->setSteering_force(agent->getSteering_force() * agent->getMaxForce());
	
}
