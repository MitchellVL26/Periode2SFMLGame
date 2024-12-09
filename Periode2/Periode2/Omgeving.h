#pragma once
#include <SFML/Graphics.hpp>
class Omgeving
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Blue Screen");


    window.setFramerateLimit(60);


    sf::RectangleShape greenRectangle(sf::Vector2f(800, 500));
    greenRectangle.setFillColor(sf::Color::Green);
    greenRectangle.setPosition(0, 200);

    sf::Color lightBlue(153, 176, 230);


    sf::CircleShape cloud1Part1(50); // Circle with radius 50
    cloud1Part1.setFillColor(sf::Color::White);
    cloud1Part1.setPosition(200, 60); // Position on the screen

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

    sf::RectangleShape treeTrunk1(sf::Vector2f(20, 300)); // Trunk width 20, height 100
    treeTrunk1.setFillColor(sf::Color(139, 69, 19)); // Brown color for the trunk
    treeTrunk1.setPosition(110, 400); // Position trunk at the bottom

    sf::CircleShape treeFoliage1(50); // Foliage with radius 50
    treeFoliage1.setFillColor(sf::Color(255, 192, 203));
    treeFoliage1.setPosition(75, 350); // Position foliage above the trunk


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


        window.display();
    }

    return 0;
};

