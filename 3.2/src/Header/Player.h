#pragma once
#include "Animation.h"
#include "Collider.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	float bodySize;

	sf::Vector2f velocity;

	float jumpHeight;

public:
	bool canJump;
	Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight, float bodySize);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	};
	Collider GetCollider()
	{
		return Collider(body);
	}
};
