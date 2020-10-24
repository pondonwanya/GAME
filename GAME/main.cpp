#include <SFML\Graphics.hpp>
#include "player.h"
#include "entity.h"
#include "Projectile.h"
#include "enemy.h"
#include "random.h"

using namespace std;
#include <iostream>

int main()
{

	float playerMovementSpeed = 0.3;
	bool faceRight = 1;
	int counterRunning = 0;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	window.setFramerateLimit(25);
	//window.setPosition(sf::Vector2i(300, 300));
	//window.setSize(sf::Vector2u(300, 300));
	//window.setTitle("SFML Window");

	sf::Texture Sprite;
	Sprite.loadFromFile("png/Sprite.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(Sprite);
	playerSprite.setPosition(window.getSize().x/2,window.getSize().y/2);   
	playerSprite.setTextureRect(sf::IntRect(0, 1080, 641, 542));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x /8, playerSprite.getTexture()->getSize().y/2));

	sf::Texture Enemy;
	Enemy.loadFromFile("png/enemy.png");

	// class Object
	class player Player1;
	Player1.sprite.setTexture(Sprite);

	//Projectile Vector Arrey
	vector<projectile>::const_iterator(iter);
	vector<projectile> projectileArrey;

	//Projectile Object
	class projectile projectile1;

	//Enemy Vector Arrey
	vector<enemy>::const_iterator(iter4);
	vector<enemy> enemyArrey;

	//Enery Object
	class enemy enemy1;
	enemy1.sprite.setTexture(Enemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0,0,32,32));

	enemy1.rect.setPosition(600, 200);
	enemyArrey.push_back(enemy1);



	//Start the game loop
	while (window.isOpen())
	{
		//Process event
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Close window : exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			//Escape pressed : exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
		}

		//Clear screen
		window.clear();

		//Fires Missle (Space Bar)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			enemy1.rect.setPosition(generateRandom(window.getSize().x),generateRandom(window.getSize().y));
			enemyArrey.push_back(enemy1);
		}

		//Fires Missle (Space Bar)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x/-projectile1.rect.getSize().x/2,Player1.rect.getPosition().y + Player1.rect.getSize().y/2-projectile1.rect.getSize().y/2);
			//projectile1.rect.setPosition(Sprite.rect.getPosition().x/20-1000 , Player1.rect.getPosition().y );
			projectile1.rect.setPosition(Player1.rect.getPosition());
			projectile1.direction = Player1.direction;
			projectileArrey.push_back(projectile1);
		}

		//Draw Projectiles
		counter = 0;
		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
		{
			projectileArrey[counter].update();  // Update Projectile
			window.draw(projectileArrey[counter].rect);
			counter++;
		}

		//Draw Enemies
		counter = 0;
		for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
		{
			enemyArrey[counter].update(); 
			enemyArrey[counter].updateMovement();
			//window.draw(enemyArrey[counter].rect);
			window.draw(enemyArrey[counter].sprite);

			counter++;
		}

		//Update Player
		Player1.update();
		Player1.updateMovement();

		//Draw Player
		window.draw(Player1.sprite);
		//window.draw(Player1.rect);

		window.display();
	}

	return EXIT_SUCCESS;
}
