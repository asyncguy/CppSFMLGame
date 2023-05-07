#pragma once
#include "Collider.h"
#include <SFML/Graphics.hpp>

class Platform
{
private:
	sf::RectangleShape body;

public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);

	void Draw(sf::RenderWindow& window);
	Collider GetCollider()
	{
		return Collider(body);
	}
};
