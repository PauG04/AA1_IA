#include "Avoidance.h"

Avoidance::Avoidance()
{
	fleeBehaviour = new Flee();
}

Vector2D Avoidance::ApplySteeringForce(Agent* agent, float dtime)
{
	/*Vector2D raycast = agent->getPosition();
	raycast += agent->getVelocity().Normalize() * agent->GetAvoidanceLookAhead();

	Vector2D entityToAgent, intersectionPoint;
	bool isColliding = false;

	for (Entity* entity : agent->GetEntities())
	{
		entityToAgent = entity->GetPosition() - agent->getPosition();

		isColliding = Vector2DUtils::SegmentSegmentIntersection(
			agent->getPosition(),
			raycast,
			entity->GetPosition(),
			entity->GetPosition() + entityToAgent.Normalize() * entity->GetRadius(),
			true,
			&intersectionPoint);

		if (isColliding)
			break;
	}

	if (isColliding)
	{
		Vector2D avoidTarget = intersectionPoint;
		avoidTarget +=
	}*/

	/*float shortestDistance = 1000;
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
	}*/

	return Vector2D();
}
