#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);

	void Update(int row, float deltaTime, bool faceRight);

public:
	IntRect uvRect;
	Vector2u currentImage;

private:
	Vector2u imageCount;

	float totalTime;
	float switchTime;
};