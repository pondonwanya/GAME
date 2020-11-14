#include <SFML\Graphics.hpp>
#include <fstream>
#include <stdio.h>
#include <string>
#include "player.h"
#include "entity.h"
#include "Projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "background.h"
#include "background2.h"
#include "background3.h"
#include "warp.h"
#include "MainMenu.h"

#include <iostream>
using namespace std;

int main()
{
	// random part
	srand(time(NULL));

	// Varible
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	float playerMovementSpeed = 1.5;
	bool faceRight = 1;
	int counterRunning = 0;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;

	bool mainmenu = true;
	bool state1=true;
	//sf::RenderWindow window(sf::VideoMode(1080, 720), "Main Menu");
	//MainMenu mainmenu(1080, 720);

	//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");

	window.setFramerateLimit(25);
	sf::Texture Sprite;
	Sprite.loadFromFile("png/Sprite.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(Sprite);
	playerSprite.setPosition(window.getSize().x/2,window.getSize().y/2);   
	playerSprite.setTextureRect(sf::IntRect(0, 1080, 641, 542));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x /8, playerSprite.getTexture()->getSize().y/2));

	sf::Texture Potion;
	Potion.loadFromFile("png/coin01.png");

	sf::Texture fireBall;
	fireBall.loadFromFile("png/bullet.png");

	sf::Texture Enemy;
	Enemy.loadFromFile("png/EnemySprite.png");

	sf::Texture doorwarp;
	doorwarp.loadFromFile("png/door2.png");

	sf::Texture bg1;
	bg1.loadFromFile("png/bg2.png");

	sf::Texture bg2;
	bg2.loadFromFile("png/bg1.png");

	sf::Texture bg3;
	bg3.loadFromFile("png/bg3.png");

	sf::Texture background_main;
	background_main.loadFromFile("png/bgMainmenu.png");
	sf::Sprite bgButton;
	bgButton.setTexture(background_main);
	bgButton.setScale(0.5,0.5);

	
	// Cteate a graphical text to display
	sf::Font font;
	font.loadFromFile("karmatic/ka1.ttf");

	sf::Text text("BULLET   DESTROYER", font, 25);
	text.setCharacterSize(20);
	text.setPosition(0, 0);


	sf::Font font2;
	font2.loadFromFile("chrusty-rock-font/ChrustyRock-ORLA.ttf");
	sf::Text text2("BULLET   DESTROYER", font2, 50);
	text2.setCharacterSize(65);
	text2.setFillColor(sf::Color::Cyan);
	text2.setPosition(50, 10);

	sf::Text text1("Gill", font, 25);
	text1.setCharacterSize(20);
	text1.setPosition(0, 20);

	sf::Text texteiei;

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

	enemy1.rect.setPosition(810, 610);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(-1, 620);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(820, -1);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(-5, 640);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(815, -3);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(805, -4);
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
	pickUp1.rect.setSize(sf::Vector2f(63.5, 64));
	pickUpArrey.push_back(pickUp1);

	pickUp1.rect.setPosition(600, 300);
	pickUpArrey.push_back(pickUp1);

	// background
	class background background1;
	background1.sprite.setTexture(&bg1);

	// background
	class background2 background2;
	background2.sprite.setTexture(&bg2);

	// background
	class background3 background3;
	background3.sprite.setTexture(&bg3);
	
	//doorwarp Vector Arrey
	vector<warp>::const_iterator iter2;
	vector<warp> warpArrey;

	//Potion Object
	class warp warp1;
	warp1.sprite.setTexture(&doorwarp);
	warp1.rect.setPosition(750, 250);
	warp1.rect.setSize(sf::Vector2f(96, 54));
	warpArrey.push_back(warp1);


	//

	class MainMenu mainaaaaa(0 ,0);

	sf::Text mainMenu1;
	sf::Text mainMenu2;
	sf::Text mainMenu3;

	sf::Font font1;
	font1.loadFromFile("arial/arial.ttf");
	printf("Yoooooooooooooooooooooooo");
	//Play
	mainMenu1.setFont(font1);
	mainMenu1.setFillColor(sf::Color::Black);
	mainMenu1.setString("PLAY");
	mainMenu1.setCharacterSize(40);
	mainMenu1.setPosition(200, 150);

	//Score
	mainMenu2.setFont(font1);
	mainMenu2.setFillColor(sf::Color::Black);
	mainMenu2.setString("SCORE");
	mainMenu2.setCharacterSize(40);
	mainMenu2.setPosition(200, 220);

	//Play
	mainMenu3.setFont(font1);
	mainMenu3.setFillColor(sf::Color::Black);
	mainMenu3.setString("QUIT");
	mainMenu3.setCharacterSize(40);
	mainMenu3.setPosition(200, 290);

	int select = 0;

	int eieieieieieie = 0;

	//

	//bool mainmenu = true;
	//Start the game loop
	/*sf::RenderWindow window(sf::VideoMode(800, 600), "Main Menu");
	window.setFramerateLimit(25);*/


	while (window.isOpen())
	{
		//Process event
		sf::Event event;
		while (window.pollEvent(event))
		{
			while (mainmenu)
			{
				printf("%d\n", eieieieieieie);
				eieieieieieie++;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && select == 0) {
					mainmenu = false;

				}
				if (event.type == sf::Event::Closed) {
					window.close();
				}

				if (eieieieieieie > 3) {
					

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
						if (select > 0) {
							select--;
						}
						eieieieieieie = 0;

					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
						if (select < 2) {
							select++;
						}
						eieieieieieie = 0;

					}
				}

				mainMenu1.setFillColor(sf::Color::Black);
				mainMenu2.setFillColor(sf::Color::Black);
				mainMenu3.setFillColor(sf::Color::Black);

				if (select == 0) {
					mainMenu1.setFillColor(sf::Color::White);
				}
				if (select == 1) {
					mainMenu2.setFillColor(sf::Color::White);
				}
				if (select == 2) {
					mainMenu3.setFillColor(sf::Color::White);
				}
				//mainaaaaa.draw(window);
				
				//window.draw(mainaaaaa.mainMenu[1]);
				//window.draw(mainaaaaa.mainMenu[2]);
				sf::Mouse mouse;

				
				
				window.draw(bgButton);
				window.draw(text2);
				window.draw(mainMenu1);
				window.draw(mainMenu3);
				window.draw(mainMenu2);
				window.display();
				window.clear();
			}

			while (state1)
			{
				// random part
				int randomTime, r;
				srand(time(NULL));

				r = rand() % 4;

				cout  << "r = " <<r << endl;
				// Clock
				sf::Time elapsed1 = clock.getElapsedTime();
				sf::Time elapsed2 = clock.getElapsedTime();
				sf::Time elapsed3 = clock.getElapsedTime();

				//Player collides with Pickup Item

				//Player1.updateHpBar();
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
						Player1.updateHpBar();
					}

					counter++;
				}


				//Player collides with door
				counter = 0;
				if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
				{
					warpArrey[counter].isDoor = true;
					background2.rect.setPosition(sf::Vector2f(1000, 2000));
					background2.sprite.setPosition(sf::Vector2f(1000, 2000));
					Player1.rect.setPosition(sf::Vector2f(100, 280));
				}
				counter++;

				counter = 0;
				if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
				{
					warpArrey[counter].isDoor2 = true;
					background3.rect.setPosition(sf::Vector2f(1000, 2000));
					background3.sprite.setPosition(sf::Vector2f(1000, 2000));
					Player1.rect.setPosition(sf::Vector2f(100, 280));
				}
				counter++;

				if (elapsed2.asSeconds() >= 0.1)
				//if (true)
				{
					printf("Eieiei\n");
					clock2.restart();

					//Enemy Collides with Player (Player takes damage)
					counter = 0;
					for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
					{
						if (Player1.rect.getGlobalBounds().intersects(enemyArrey[counter].rect.getGlobalBounds()))
						{
							//Text Display
							printf("Attack\n");
							textDisplay1.text.setString(to_string(enemyArrey[counter].attactDamage));
							textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
							textDisplayArrey.push_back(textDisplay1);

							Player1.hp -= enemyArrey[counter].attactDamage;
							Player1.updateHpBar();
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

							enemyArrey[counter2].hp -= projectileArrey[counter].attactDamage;
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
					if (pickUpArrey[counter].destroy == true)
					{
						cout << "Chon" << endl;
						pickUpArrey.erase(iter11);
						break;
					}
					counter++;
				}



				////Spawn Enemies (Y-Key)
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
				//{
				//	enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
				//	enemyArrey.push_back(enemy1);
				//}

				//Fires Missle (Space Bar)
				if (elapsed1.asSeconds() >= 0.1)
				//if (true)
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
				window.draw(background3.sprite);
				background3.update();
				window.draw(background1.sprite);
				//window.draw(background1.rect);
				background1.update();
				window.draw(background2.sprite);
				background2.update();



				//Draw Pickup Items
				counter = 0;
				for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
				{
					pickUpArrey[counter].update();
					pickUpArrey[counter].updateMovement();
					//window.draw(pickUpArrey[counter].rect);
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
					int counterRunning = 0;
					if (enemyArrey[counter].rect.getPosition().x > Player1.rect.getPosition().x)   // Left
					{
						enemyArrey[counter].rect.move(-playerMovementSpeed, 0);
					}
					if (enemyArrey[counter].rect.getPosition().x < Player1.rect.getPosition().x)    // Right
					{
						enemyArrey[counter].rect.move(playerMovementSpeed, 0);
					}
					if (enemyArrey[counter].rect.getPosition().y > Player1.rect.getPosition().y)    // Up
					{
						enemyArrey[counter].rect.move(0, -playerMovementSpeed);
					}
					if (enemyArrey[counter].rect.getPosition().y < Player1.rect.getPosition().y)    // Down
					{
						enemyArrey[counter].rect.move(0, playerMovementSpeed);
					}

					enemyArrey[counter].update();
					enemyArrey[counter].updateMovement();
					enemyArrey[counter].updateHpBar();
					window.draw(enemyArrey[counter].rectHp);
					//window.draw(enemyArrey[counter].rect);
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
				//window.draw(Player1.rect);
				window.draw(Player1.sprite);
				window.draw(Player1.rectHp);


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

			window.clear();

			if (event.type == sf::Event::Closed) {
				window.close();
			}

	//		// Clock
	//		sf::Time elapsed1 = clock.getElapsedTime();
	//		sf::Time elapsed2 = clock.getElapsedTime();
	//		sf::Time elapsed3 = clock.getElapsedTime();

	//		//Player collides with Pickup Item
	//		counter = 0;
	//		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
	//		{
	//			if (Player1.rect.getGlobalBounds().intersects(pickUpArrey[counter].rect.getGlobalBounds()))
	//			{
	//				if (pickUpArrey[counter].isPotion == true)
	//				{
	//					Player1.gil += pickUpArrey[counter].potionValue;
	//				}
	//				pickUpArrey[counter].destroy = true;
	//			}

	//			counter++;
	//		}


	//		//Player collides with door
	//		counter = 0;
	//		if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
	//		{
	//			warpArrey[counter].isDoor = true;
	//			background2.rect.setPosition(sf::Vector2f(1000, 2000));
	//			background2.sprite.setPosition(sf::Vector2f(1000, 2000));
	//			Player1.rect.setPosition(sf::Vector2f(100, 280));

	//			//// Custom Room
	//			//int roomSize = generateRandom(10) + 3;
	//			//int verticalDoorLocation = generateRandom(4);
	//			//int roomStartX = 0;
	//			//int roomStartY = 0;

	//			//enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	//			//enemyArrey.push_back(enemy1);
	//			//enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	//			//enemyArrey.push_back(enemy1);
	//			//enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	//			//enemyArrey.push_back(enemy1);
	//			//enemy1.rect.setPosition((roomSize * 50), (roomSize * 50));
	//			//enemyArrey.push_back(enemy1);
	//		}
	//		counter++;


	//		if (elapsed2.asSeconds() >= 0.1)
	//		{
	//			clock2.restart();

	//			//Enemy Collides with Player (Player takes damage)
	//			counter = 0;
	//			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
	//			{
	//				if (Player1.rect.getGlobalBounds().intersects(enemyArrey[counter].rect.getGlobalBounds()))
	//				{
	//					//Text Display
	//					textDisplay1.text.setString(to_string(enemyArrey[counter].attactDamage));
	//					textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
	//					textDisplayArrey.push_back(textDisplay1);

	//					Player1.hp -= enemyArrey[counter].attactDamage;
	//					Player1.updateHpBar();
	//				}
	//				counter++;
	//			}
	//		}

	//		cout << Player1.hp << endl;

	//		//Projectile Collides with Enemy
	//		counter = 0;
	//		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
	//		{
	//			counter2 = 0;
	//			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
	//			{
	//				if (projectileArrey[counter].rect.getGlobalBounds().intersects(enemyArrey[counter2].rect.getGlobalBounds()))
	//				{
	//					//cout << "Collision" << endl;
	//					projectileArrey[counter].destroy = true;
	//					Player1.gil1 += enemyArrey[counter].enemyValue;  // ยิงแล้วคะแนนเพิ่ม

	//					//Text Display
	//					textDisplay1.text.setString(to_string(projectileArrey[counter].attactDamage));
	//					textDisplay1.text.setPosition(enemyArrey[counter2].rect.getPosition().x, enemyArrey[counter2].rect.getPosition().y);
	//					textDisplayArrey.push_back(textDisplay1);

	//					enemyArrey[counter2].hp -= projectileArrey[counter].attactDamage;
	//					if (enemyArrey[counter2].hp <= 0)
	//					{
	//						enemyArrey[counter2].alive = false;
	//					}
	//				}

	//				counter2++;
	//			}
	//			counter++;
	//		}

	//		//Delete Dead Enemy
	//		counter = 0;
	//		for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
	//		{
	//			if (enemyArrey[counter].alive == false)
	//			{
	//				cout << "Dead" << endl;

	//				// Drop Potion
	//				if (generateRandom(4) == 1)
	//				{
	//					pickUp1.rect.setPosition(enemyArrey[counter].rect.getPosition());
	//					pickUpArrey.push_back(pickUp1);
	//				}

	//				enemyArrey.erase(iter4);
	//				break;
	//			}
	//			counter++;
	//		}

	//		//Delete Projectile
	//		counter = 0;
	//		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
	//		{
	//			if (projectileArrey[counter].destroy == true)
	//			{
	//				//cout << "proDead" << endl;
	//				projectileArrey.erase(iter);
	//				break;
	//			}
	//			counter++;
	//		}

	//		// Delete Text Display
	//		counter = 0;
	//		for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
	//		{
	//			if (textDisplayArrey[counter].destroy == true)
	//			{
	//				textDisplayArrey.erase(iter8);
	//				break;
	//			}
	//			counter++;
	//		}

	//		//Delete Pickup Items
	//		counter = 0;
	//		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
	//		{
	//			if (pickUpArrey[counter].destroy == true)
	//			{
	//				cout << "Chon" << endl;
	//				pickUpArrey.erase(iter11);
	//				break;
	//			}
	//			counter++;
	//		}

	//		//Spawn Enemies (Y-Key)
	//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	//		{
	//			enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
	//			enemyArrey.push_back(enemy1);
	//		}

	//		//Fires Missle (Space Bar)
	//		if (elapsed1.asSeconds() >= 0.1)
	//		{
	//			clock.restart();

	//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//			{
	//				projectile1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / -projectile1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectile1.rect.getSize().y / 2);
	//				//projectile1.rect.setPosition(Sprite.rect.getPosition().x/20-1000 , Player1.rect.getPosition().y );
	//				projectile1.rect.setPosition(Player1.rect.getPosition());
	//				projectile1.direction = Player1.direction;
	//				projectileArrey.push_back(projectile1);
	//			}
	//		}

	//		//Draw background
	//		window.draw(background1.sprite);
	//		//window.draw(background1.rect);
	//		background1.update();


	//		window.draw(background2.sprite);
	//		background2.update();


	//		//Draw Pickup Items
	//		counter = 0;
	//		for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
	//		{
	//			pickUpArrey[counter].update();
	//			//window.draw(pickUpArrey[counter].rect);
	//			window.draw(pickUpArrey[counter].sprite);

	//			counter++;
	//		}

	//		//Draw Projectiles
	//		counter = 0;
	//		for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
	//		{
	//			projectileArrey[counter].update();  // Update Projectile
	//			window.draw(projectileArrey[counter].rect);
	//			window.draw(projectileArrey[counter].sprite);
	//			counter++;
	//		}

	//		//Draw Enemies
	//		counter = 0;
	//		for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
	//		{

	//			if (enemyArrey[counter].rect.getPosition().x > Player1.rect.getPosition().x)
	//			{
	//				enemyArrey[counter].rect.move(-1, 0);
	//			}
	//			if (enemyArrey[counter].rect.getPosition().x < Player1.rect.getPosition().x)
	//			{
	//				enemyArrey[counter].rect.move(1, 0);
	//			}
	//			if (enemyArrey[counter].rect.getPosition().y > Player1.rect.getPosition().y)
	//			{
	//				enemyArrey[counter].rect.move(0, -1);
	//			}
	//			if (enemyArrey[counter].rect.getPosition().y < Player1.rect.getPosition().y)
	//			{
	//				enemyArrey[counter].rect.move(0, 1);
	//			}

	//			enemyArrey[counter].update();
	//			enemyArrey[counter].updateHpBar();
	//			window.draw(enemyArrey[counter].rectHp);
	//			//window.draw(enemyArrey[counter].rect);
	//			window.draw(enemyArrey[counter].sprite);

	//			counter++;
	//		}

	//		//Update doorwarp
	//		warp1.update();

	//		//Draw doorwarp
	//		window.draw(warp1.rect);
	//		window.draw(warp1.sprite);

	//		//Update Player
	//		Player1.update();
	//		Player1.updateMovement();

	//		//Draw Player
	//		//window.draw(Player1.rect);
	//		window.draw(Player1.sprite);
	//		window.draw(Player1.rectHp);


	//		//Draw Text
	//		counter = 0;
	//		for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
	//		{
	//			textDisplayArrey[counter].update();
	//			window.draw(textDisplayArrey[counter].text);
	//			counter++;
	//		}

	//		// Draw Gil (1)
	//		text.setString("Coin   " + to_string(Player1.gil));
	//		window.draw(text);

	//		// Draw Gil (2)
	//		text1.setString("Score   " + to_string(Player1.gil1));
	//		window.draw(text1);

	//		// Update the window
	//		window.display();
	//		
		}
	}

	return EXIT_SUCCESS;
}
