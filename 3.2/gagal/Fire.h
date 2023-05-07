#pragma once
#include <SFML/Graphics.hpp>

class Fire
{
private:
	bool isFiring;

public:
	float velocityX;
	void Shoot(sf::RectangleShape& object, float speed, float deltaTime);
};