#include <SFML\Graphics.hpp>
#include "player.h"
#include "entity.h"
#include "Projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "background.h"
#include "background2.h"
#include "warp.h"

using namespace std;
#include <iostream>

int main()
{
	// Varible
	srand(time(NULL));
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
	Potion.loadFromFile("png/coin.gif");

	sf::Texture fireBall;
	fireBall.loadFromFile("png/bullet.png");

	sf::Texture Enemy;
	Enemy.loadFromFile("png/enemy.png");

	sf::Texture doorwarp;
	doorwarp.loadFromFile("png/doorwarp.png");

	sf::Texture bg1;
	bg1.loadFromFile("png/background.png");
	//sf::RectangleShape bg1(sf::Vector2f(4000, 1000));

	sf::Texture bg2;
	bg2.loadFromFile("png/background2.png");
	/*sf::RectangleShape bg2(sf::Vector2f(4000, 1000));
	bg2.setPosition(sf::Vector2f(-800, -2200));
	bg2.setTexture(&background2);*/

	
	// Cteate a graphical text to display
	sf::Font font;
	font.loadFromFile("karmatic/ka1.ttf");

	sf::Text text("Gill", font, 25);
	text.setCharacterSize(20);
	text.setPosition(0, 0);

	sf::Text text1("Gill", font, 25);
	text1.setCharacterSize(20);
	text1.setPosition(0, 20);


	// class Object
	class player Player1;
	Player1.sprite.setTexture(&Sprite);

	//Projectile Vector Arrey
	vector<projectile>::const_iterator(iter);
	vector<projectile> projectileArrey;

	//Projectile Object
	class projectile projectile1;
	projectile1.sprite.setTexture(&fireBall);

	//Enemy Vector Arrey
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArrey;

	//Enery Object
	class enemy enemy1;
	enemy1.sprite.setTexture(&Enemy);
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
	pickUp1.sprite.setTexture(&Potion);
	pickUp1.rect.setPosition(500, 500);
	pickUp1.rect.setSize(sf::Vector2f(25, 35));
	pickUpArrey.push_back(pickUp1);

	pickUp1.rect.setPosition(600, 300);
	pickUpArrey.push_back(pickUp1);

	// background
	class background background1;
	background1.sprite.setTexture(&bg1);

	// background
	class background2 background2;
	background2.sprite.setTexture(&bg2);
	

	// Custom Room
	int roomSize = generateRandom(10) + 3;
	int verticalDoorLocation = generateRandom(4);
	int roomStartX = 0;
	int roomStartY = 0;

	enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	enemyArrey.push_back(enemy1);
	
	//doorwarp Vector Arrey
	vector<warp>::const_iterator iter2;
	vector<warp> warpArrey;

	//Potion Object
	class warp warp1;
	warp1.sprite.setTexture(&doorwarp);
	warp1.rect.setPosition(780, 250);
	warp1.rect.setSize(sf::Vector2f(50, 120));
	warpArrey.push_back(warp1);


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

		//Player collides with Pickup Item
		counter = 0;
		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
		{
			if (Player1.rect.getGlobalBounds().intersects(pickUpArrey[counter].rect.getGlobalBounds()))
			{
				if (pickUpArrey[counter].isPotion == true) 
				{
					Player1.gil += pickUpArrey[counter].potionValue;
				}
				pickUpArrey[counter].destroy = true;
			}

			counter++;
		}

		//Player collides with door
		counter = 0;
			if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
			{
					warpArrey[counter].isDoor = true;
					Player1.rect.setPosition(sf::Vector2f(100,280));
			}
			counter++;
		

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
					Player1.gil1 += enemyArrey[counter].enemyValue;  // ยิงแล้วคะแนนเพิ่ม
					
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

				// Drop Potion
				if (generateRandom(4) == 1)
				{
					pickUp1.rect.setPosition(enemyArrey[counter].rect.getPosition());
					pickUpArrey.push_back(pickUp1);
				}

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

		//Delete Pickup Items
		counter = 0;
		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
		{
			if (pickUpArrey[counter].destroy ==true)
			{
				cout << "Chon" << endl;
				pickUpArrey.erase(iter11);
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

		//Draw background
		window.draw(background1.sprite);
		//window.draw(background1.rect);
		background1.update();


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
			window.draw(projectileArrey[counter].sprite);
			counter++;
		}

		//Draw Enemies
		counter = 0;
		for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
		{
			enemyArrey[counter].update(); 
			enemyArrey[counter].updateMovement();
			window.draw(enemyArrey[counter].rect);
			window.draw(enemyArrey[counter].sprite);

			counter++;
		}

		//Update doorwarp
		warp1.update();

		//Draw doorwarp
		window.draw(warp1.rect);
		window.draw(warp1.sprite);

		//Update Player
		Player1.update();
		Player1.updateMovement();

		//Draw Player
		window.draw(Player1.rect);
		window.draw(Player1.sprite);

		//Draw Text
		counter = 0;
		for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
		{
			textDisplayArrey[counter].update();
			window.draw(textDisplayArrey[counter].text);
			counter++;
		}

		// Draw Gil (1)
		text.setString("Coin   " + to_string(Player1.gil));
		window.draw(text);

		// Draw Gil (2)
		text1.setString("Score   " + to_string(Player1.gil1));
		window.draw(text1);

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
}
