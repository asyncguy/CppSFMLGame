#include "Header/Fire.h"
using namespace std;

void Fire::Shoot(sf::RectangleShape& object, float speed, float deltaTime)
{
	bool isDisappear = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		isFiring = true;
	}
	if (isFiring && isDisappear != false)
	{
		object.move(sf::Vector2f(speed * deltaTime, 0));
	}
}