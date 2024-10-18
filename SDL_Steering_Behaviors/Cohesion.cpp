#include "Cohesion.h"

Vector2D Cohesion::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D averagePosition = 0;
	for (Agent* currentAgent : agent->GetNeighbours())
	{
		averagePosition += currentAgent->getPosition();
	}

	if (agent->GetNeighbours().size() > 0)
		averagePosition /= agent->GetNeighbours().size();
	averagePosition -= agent->getPosition();
	return averagePosition.Normalize();
}
