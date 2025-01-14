#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ui.h"
#include "Enemy.h"


int main()
{
    if (UI() != 0) {
        return 1; 
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Blue Screen");

    
    window.setFramerateLimit(60);

    Player player(200, 430);

    float enemyRadius = 20.0f;
    Enemy enemy(enemyRadius, 700, 400, 5.0f);
    Enemy enemy2(enemyRadius, 700, 200, 3.0f);
    Enemy enemy3(enemyRadius, 700, 100, 4.0f);

    sf::RectangleShape greenRectangle(sf::Vector2f(800, 500)); 
    greenRectangle.setFillColor(sf::Color::Green);
    greenRectangle.setPosition(0, 200); 

    sf::RectangleShape groundRectangle(sf::Vector2f(800, 400));
    groundRectangle.setFillColor(sf::Color::Black);
    groundRectangle.setPosition(0, 560);

    sf::Color lightBlue(153, 176, 230);
 

    sf::CircleShape cloud1Part1(50); 
    cloud1Part1.setFillColor(sf::Color::White);
    cloud1Part1.setPosition(200, 60); 

    sf::CircleShape cloud1Part2(40);
    cloud1Part2.setFillColor(sf::Color::White);
    cloud1Part2.setPosition(250, 80);

    sf::CircleShape cloud1Part3(45);
    cloud1Part3.setFillColor(sf::Color::White);
    cloud1Part3.setPosition(180, 90);

    // Create another cloud
    sf::CircleShape cloud2Part1(60);
    cloud2Part1.setFillColor(sf::Color::White);
    cloud2Part1.setPosition(500, 50);

    sf::CircleShape cloud2Part2(50);
    cloud2Part2.setFillColor(sf::Color::White);
    cloud2Part2.setPosition(550, 70);

    sf::CircleShape cloud2Part3(55);
    cloud2Part3.setFillColor(sf::Color::White);
    cloud2Part3.setPosition(480, 80);

    sf::RectangleShape treeTrunk1(sf::Vector2f(20, 300)); 
    treeTrunk1.setFillColor(sf::Color(139, 69, 19)); 
    treeTrunk1.setPosition(110, 400); 

    sf::CircleShape treeFoliage1(50); 
    treeFoliage1.setFillColor(sf::Color(255, 192, 203));
    treeFoliage1.setPosition(75, 350); 



    sf::RectangleShape treeTrunk3(sf::Vector2f(20, 300));
    treeTrunk3.setFillColor(sf::Color(139, 69, 19));
    treeTrunk3.setPosition(510, 400);

    sf::CircleShape treeFoliage3(50);
    treeFoliage3.setFillColor(sf::Color(255, 192, 203));
    treeFoliage3.setPosition(475, 350);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
     
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update();
        enemy.update();
        enemy2.update();
        enemy3.update();
        if (player.getBounds().intersects(enemy.getShape().getGlobalBounds()) ||
            player.getBounds().intersects(enemy2.getShape().getGlobalBounds()) ||
            player.getBounds().intersects(enemy3.getShape().getGlobalBounds()))
        {
            
            
            if (UI() != 0)
            {
                return 1;
            }

            
            player.reset(200, 430);
            enemy.reset(700, 400);
            enemy2.reset(700, 200);
            enemy3.reset(700, 100);
        }

        window.clear(lightBlue);

        window.draw(greenRectangle);
      

        window.draw(cloud1Part1);
        window.draw(cloud1Part2);
        window.draw(cloud1Part3);
        window.draw(cloud2Part1);
        window.draw(cloud2Part2);
        window.draw(cloud2Part3);

        window.draw(treeTrunk1);
        window.draw(treeFoliage1);
        window.draw(treeTrunk3);
        window.draw(treeFoliage3);
        window.draw(groundRectangle);

        player.draw(window);
        enemy.draw(window);
        enemy2.draw(window);
        enemy3.draw(window);


        
        window.display();
    }

    return 0;
}
