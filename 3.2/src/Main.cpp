#include "Header/Platform.h"
#include "Header/Player.h"
#include "Platform/Platform.hpp"
#include <iostream>
#include <vector>
using namespace std;

static const float VIEW_HEIGHT = 480.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view);

void ResizeBg(const sf::RenderWindow& window, sf::RectangleShape& background);

int main()
{
	//player variables
	float swicthTime = 0.1f;
	float speed = 350.0f;
	float jumpHeight = 200.0f;
	float bodySize = 70.0f;

	//renderWindow & view
	sf::RenderWindow window(sf::VideoMode(852, 480), "Percobaan 3.2", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	ResizeView(window, view);

	//texture
	sf::Texture playerTexture;
	playerTexture.loadFromFile("content/soldier.png");

	sf::Texture fire;
	fire.loadFromFile("content/fireballAnim.png");

	sf::Texture forest;
	forest.loadFromFile("content/bg.png");
	forest.setRepeated(true);

	sf::Texture stone;
	stone.loadFromFile("content/stone_tile.png");
	stone.setRepeated(true);

	//background Rectangleshape
	sf::RectangleShape background;
	background.setTexture(&forest);

	//player
	Player player(&playerTexture, sf::Vector2u(4, 2), swicthTime, speed, jumpHeight, bodySize);

	//objects
	sf::RectangleShape fireball(sf::Vector2f(64.0f, 40.0f));
	fireball.setTexture(&fire);

	//platformer
	vector<Platform> platforms;

	platforms.push_back(Platform(&stone, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(0.0f, 300.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 200.0f), sf::Vector2f(2200.0f, 300.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 100.0f), sf::Vector2f(0.0f, 1000.0f)));

	//time
	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Clock waktu;
	unsigned int menit = 0;

	while (window.isOpen())
	{
		sf::Event event;

		sf::Time waktuBerlalu = waktu.getElapsedTime();

		if (waktuBerlalu.asSeconds() >= 60.0f)
		{
			menit += 1;
			waktu.restart();
		}

		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
		{
			deltaTime = 1.0f / 60.0f;
		}

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					cout << "Anda telah bermain selama : " << endl;
					cout << menit << " menit " << waktuBerlalu.asSeconds() << " Detik" << endl;
					break;
				case sf::Event::Resized:
					ResizeView(window, view);
					break;
				default:
					break;
			}
		}

		player.Update(deltaTime);

		sf::Vector2f direction;
		for (Platform& platform : platforms)
		{
			if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
			{
				player.OnCollision(direction);
			}
		}

		ResizeBg(window, background);
		background.setOrigin(background.getSize().x / 2.0f, background.getSize().y / 2.0f);
		background.setPosition(view.getCenter());

		window.clear(sf::Color(123, 123, 123));

		view.setCenter(player.GetPosition());
		window.draw(background);
		window.setView(view);
		player.Draw(window);

		for (Platform& platform : platforms)
		{
			platform.Draw(window);
		}

		window.display();
	}

	return 0;
}

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void ResizeBg(const sf::RenderWindow& window, sf::RectangleShape& background)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	background.setSize(sf::Vector2f(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT));
}