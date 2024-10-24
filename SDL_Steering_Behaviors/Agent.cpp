#include "Agent.h"
#include "Seek.h"
#include "Flee.h"
#include "PathFollowing.h"
#include "Flocking.h"
#include "CompositeWeightedSum.h"

using namespace std;

Agent::Agent(SteeringBehavior *_steering_behavior) : sprite_texture(0),
                 position(Vector2D(100, 100)),
	             target(Vector2D(1000, 100)),
	             velocity(Vector2D(0,0)),
	             mass(0.3f),
	             max_force(50),
	             max_velocity(200),
	             orientation(0),
	             color({ 255,255,255,255 }),
				 sprite_num_frames(0),
	             sprite_w(0),
	             sprite_h(0),
	             draw_sprite(false),
				 neighbourRadius(200),
				 avoidanceLookAhead(150)
{
	steering_behavior = _steering_behavior;
}

Agent::~Agent()
{
	if (sprite_texture)
		SDL_DestroyTexture(sprite_texture);
	if (steering_behavior)
		delete (steering_behavior);
}

SteeringBehavior * Agent::Behavior()
{
	return steering_behavior;
}

Vector2D Agent::getPosition()
{
	return position;
}

Vector2D Agent::getTarget()
{
	return target;
}

Vector2D Agent::getVelocity()
{
	return velocity;
}

Vector2D Agent::getSteering_force()
{
	return steering_force;
}

float Agent::getMaxVelocity()
{
	return max_velocity;
}

float Agent::getMaxForce()
{
	return max_force;
}

float Agent::GetAvoidanceLookAhead()
{
	return avoidanceLookAhead;
}

void Agent::setPosition(Vector2D _position)
{
	position = _position;
}

void Agent::setTarget(Vector2D _target)
{
	target = _target;
}

void Agent::setVelocity(Vector2D _velocity)
{
	velocity = _velocity;
}

void Agent::setSteering_force(Vector2D _steering_force)
{
	steering_force = _steering_force;
}

void Agent::setMass(float _mass)
{
	mass = _mass;
}

void Agent::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	color = { r, g, b, a };
}

void Agent::update(float dtime, SDL_Event *event)
{
	//cout << "agent update:" << endl;

	switch (event->type) {
		/* Keyboard & Mouse events */
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_sprite = !draw_sprite;
		else if (event->key.keysym.scancode == SDL_SCANCODE_A)
			steering_behavior = new Seek();
		else if (event->key.keysym.scancode == SDL_SCANCODE_S)
			steering_behavior = new PathFollowing();
		else if (event->key.keysym.scancode == SDL_SCANCODE_D)
			steering_behavior = new Flee();
		else if (event->key.keysym.scancode == SDL_SCANCODE_G)
			steering_behavior = new Flocking();
		else if (event->key.keysym.scancode == SDL_SCANCODE_H)
			steering_behavior = new CompositeWeightedSum();
		break;
	default:
		break;
	}

	if (Behavior() != nullptr)
		steering_force = Behavior()->ApplySteeringForce(this, dtime);

	Vector2D acceleration = steering_force / mass;
	velocity = velocity + acceleration * dtime;
	velocity = velocity.Truncate(max_velocity);

	position = position + velocity * dtime;
	// Update orientation
	orientation = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);

	// Trim position values to window size
	if (position.x < 0) position.x = TheApp::Instance()->getWinSize().x;
	if (position.y < 0) position.y = TheApp::Instance()->getWinSize().y;
	if (position.x > TheApp::Instance()->getWinSize().x) position.x = 0;
	if (position.y > TheApp::Instance()->getWinSize().y) position.y = 0;
}

void Agent::draw()
{
	if (draw_sprite)
	{
		Uint32 sprite;
		
		if (velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1*velocity.Length() + 250)) % sprite_num_frames;
		
		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation+90, &center, SDL_FLIP_NONE);
	}
	else 
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x+15*cos(orientation*DEG2RAD)), (int)(position.y+15*sin(orientation*DEG2RAD)));
	}
}

bool Agent::loadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	sprite_num_frames = _num_frames;
	sprite_w = image->w / sprite_num_frames;
	sprite_h = image->h;
	draw_sprite = true;

	if (image)
		SDL_FreeSurface(image);

	return true;
}

void Agent::SearchNeighbours(std::vector<Agent*> agents)
{
	for (Agent* currentAgent : agents)
	{
		if (Vector2D().Distance(currentAgent->getPosition(), getPosition()) < neighbourRadius)
		{
			neighbours.push_back(currentAgent);
		}
	}
}

std::vector<Agent*> Agent::GetNeighbours()
{
	return neighbours;
}
