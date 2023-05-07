#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Collider
{
private:
	sf::RectangleShape& body;

public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy)
	{
		body.move(dx, dy);
	}

	bool CheckCollision(Collider other, sf::Vector2f& direction, float push);
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}
	sf::Vector2f GetHalfSize()
	{
		return body.getSize() / 2.0f;
	}
};
//  sf::Vector2f direction,