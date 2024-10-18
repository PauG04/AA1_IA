#include "Avoidance.h"

Avoidance::Avoidance()
{
	fleeBehaviour = new Flee();
}

Vector2D Avoidance::ApplySteeringForce(Agent* agent, float dtime)
{
	float shortestDistance = 1000;
	Entity* nearestEntity = nullptr;
	bool collisionDetected = false;

	for (Entity* entity : agent->GetEntities())
	{
		if (Vector2DUtils::IsInsideCone(
			entity->GetPosition(), 
			agent->getPosition(), 
			agent->getVelocity().Normalize(),
			10.f
			))
		{
			float currentDistance = Vector2D().Distance(agent->getPosition(), entity->GetPosition());
			if (currentDistance < shortestDistance) 
			{
				nearestEntity = entity;
				shortestDistance = currentDistance;
				collisionDetected = true;
			}

		}
	}

	if (collisionDetected)
	{
		agent->setTarget(nearestEntity->GetPosition());
		agent->setVelocity(0);
		return fleeBehaviour->ApplySteeringForce(agent, dtime);
	}

	return Vector2D();
}
