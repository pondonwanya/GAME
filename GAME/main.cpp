#include <SFML\Graphics.hpp>
#include "player.h"
#include "entity.h"
#include "Projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "wall.h"

using namespace std;
#include <iostream>

int main()
{
	// Varible
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
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

	sf::Texture Potion;
	Potion.loadFromFile("png/Potion1.png");

	sf::Texture Enemy;
	Enemy.loadFromFile("png/enemy.png");
	
	// Cteate a graphical text to display
	sf::Font font;
	font.loadFromFile("arial/arial.ttf");

	sf::Text text("Game", font, 25);
	text.setCharacterSize(50);
	text.setPosition(300, 300);

	// class Object
	class player Player1;
	Player1.sprite.setTexture(Sprite);

	//Projectile Vector Arrey
	vector<projectile>::const_iterator(iter);
	vector<projectile> projectileArrey;

	//Projectile Object
	class projectile projectile1;

	//Enemy Vector Arrey
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArrey;

	//Enery Object
	class enemy enemy1;
	enemy1.sprite.setTexture(Enemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0,0,32,32));

	enemy1.rect.setPosition(600, 200);
	enemyArrey.push_back(enemy1);

	//Text Vector Arrey
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArrey;

	//Text Display Object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);

	//Pickup Vector Arrey
	vector<pickUp>::const_iterator iter11;
	vector<pickUp> pickUpArrey;

	//Potion Object
	class pickUp pickUp1;
	pickUp1.sprite.setTexture(Potion);
	pickUp1.rect.setPosition(500, 500);
	pickUp1.rect.setSize(sf::Vector2f(25, 32));
	pickUpArrey.push_back(pickUp1);

	pickUp1.rect.setPosition(700, 500);
	pickUpArrey.push_back(pickUp1);

	//Wall Vector Arrey
	vector<wall>::const_iterator iter15;
	vector<wall> wallArrey;

	class wall wall1;
	//enemy1.sprite.setTexture(Enemy);

	wall1.rect.setPosition(500, 500);
	wallArrey.push_back(wall1);

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

		// Clock
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock.getElapsedTime();
		sf::Time elapsed3 = clock.getElapsedTime();


		if (elapsed2.asSeconds() >= 0.1)
		{
			clock2.restart();

			//Enemy Collides with Player (Player takes damage)
			counter = 0;
			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
			{
				if (Player1.rect.getGlobalBounds().intersects(enemyArrey[counter].rect.getGlobalBounds()))
				{
					/*//Text Display
					textDisplay1.text.setString(to_string(enemyArrey[counter].attactDamage));
					textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
					textDisplayArrey.push_back(textDisplay1);*/

					Player1.hp -= enemyArrey[counter].attactDamage;
				}
				counter++;
			}
		}

		cout << Player1.hp << endl;

		//Projectile Collides with Enemy
		counter = 0;
		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
			{
				if (projectileArrey[counter].rect.getGlobalBounds().intersects(enemyArrey[counter2].rect.getGlobalBounds()))
				{
					//cout << "Collision" << endl;
					projectileArrey[counter].destroy = true;
					
					//Text Display
					textDisplay1.text.setString(to_string(projectileArrey[counter].attactDamage));
					textDisplay1.text.setPosition(enemyArrey[counter2].rect.getPosition().x, enemyArrey[counter2].rect.getPosition().y);
					textDisplayArrey.push_back(textDisplay1);
					
					enemyArrey[counter2].hp-=projectileArrey[counter].attactDamage;
					if (enemyArrey[counter2].hp <= 0)
					{
						enemyArrey[counter2].alive = false;
					}
				} 

					counter2++;
			}
			counter++;
		} 

		//Delete Dead Enemy
		counter = 0;
		for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
		{
			if (enemyArrey[counter].alive == false)
			{
				cout << "Dead" << endl;
				enemyArrey.erase(iter4);
				break;
			}
			counter++;
		}

		//Delete Projectile
		counter = 0;
		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
		{
			if (projectileArrey[counter].destroy == true)
			{
				//cout << "proDead" << endl;
				projectileArrey.erase(iter);
				break;
			}
			counter++;
		}

		// Delete Text Display
		counter = 0;
		for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
		{
			if (textDisplayArrey[counter].destroy == true)
			{
				textDisplayArrey.erase(iter8);
				break;
			}
			counter++;
		}

		//Spawn Enemies (Y-Key)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			enemy1.rect.setPosition(generateRandom(window.getSize().x),generateRandom(window.getSize().y));
			enemyArrey.push_back(enemy1);
		}

		//Fires Missle (Space Bar)
		if (elapsed1.asSeconds() >= 0.1)
		{
			clock.restart();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / -projectile1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectile1.rect.getSize().y / 2);
				//projectile1.rect.setPosition(Sprite.rect.getPosition().x/20-1000 , Player1.rect.getPosition().y );
				projectile1.rect.setPosition(Player1.rect.getPosition());
				projectile1.direction = Player1.direction;
				projectileArrey.push_back(projectile1);
			}
		}

		//Draw Pickup Items
		counter = 0;
		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
		{
			pickUpArrey[counter].update();
			window.draw(pickUpArrey[counter].rect);
			window.draw(pickUpArrey[counter].sprite);

			counter++;
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

		//Draw Text
		counter = 0;
		for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
		{
			textDisplayArrey[counter].update();
			window.draw(textDisplayArrey[counter].text);
			counter++;
		}

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}
