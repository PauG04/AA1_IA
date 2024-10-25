#include "Avoidance.h"

Avoidance::Avoidance()
{
	fleeBehaviour = new Flee();
}

Vector2D Avoidance::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D force = 0;

	for (Entity* entity : agent->GetEntities())
	{
		float externalRadius = entity->GetRadius()+20;
		if (Vector2D().Distance(entity->GetPosition(), agent->getPosition()) < externalRadius)
		{
			agent->setTarget(entity->GetPosition());
			return fleeBehaviour->ApplySteeringForce(agent, dtime)*2;
		}
	}

	return force;
}
