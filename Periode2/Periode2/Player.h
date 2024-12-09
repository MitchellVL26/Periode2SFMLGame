#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::RectangleShape torso;
    sf::RectangleShape leftArm;
    sf::RectangleShape rightArm;
    sf::RectangleShape leftLeg;
    sf::RectangleShape rightLeg;
    sf::CircleShape head;


    float speed;
    float jumpVelocity;
    float gravity;
    bool isGrounded;
    sf::Vector2f velocity;
        

public:
    Player(float x, float y)
        : speed(5.0f), jumpVelocity(-15.0f), gravity(0.5f), isGrounded(true), velocity(0, 0)
    {
       
        torso.setSize(sf::Vector2f(50, 100)); 
        torso.setFillColor(sf::Color::Yellow);
        torso.setPosition(x, y);

        
        head.setRadius(25); 
        head.setFillColor(sf::Color::Yellow);
        head.setPosition(x + .5f, y - 50); 

        
        leftArm.setSize(sf::Vector2f(15, 75)); 
        leftArm.setFillColor(sf::Color::Yellow);
        leftArm.setPosition(x - 20, y); 

        
        rightArm.setSize(sf::Vector2f(15, 75)); 
        rightArm.setFillColor(sf::Color::Yellow);
        rightArm.setPosition(x + 55, y); 

        
        leftLeg.setSize(sf::Vector2f(15, 75)); 
        leftLeg.setFillColor(sf::Color::Yellow);
        leftLeg.setPosition(x + 5, y + 100); 

        
        rightLeg.setSize(sf::Vector2f(15, 75)); 
        rightLeg.setFillColor(sf::Color::Yellow);
        rightLeg.setPosition(x + 30, y + 100); 
    }
    void update()
    {
        handleMovement();
        applyGravity();
        
    }

    void handleMovement()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGrounded)
        {
            velocity.y = jumpVelocity; 
            isGrounded = false;
        }
    }

    void applyGravity()
    {
        velocity.y += gravity;
        move(0, velocity.y);

      
        if (torso.getPosition().y + torso.getSize().y >= 500) 
        {
            velocity.y = 0;
            isGrounded = true;
            float correctedY = 500 - torso.getSize().y;
            setPosition(torso.getPosition().x, correctedY);
        }
    }

    void move(float dx, float dy)
    {
       
        torso.move(dx, dy);
        head.move(dx, dy);
        leftArm.move(dx, dy);
        rightArm.move(dx, dy);
        leftLeg.move(dx, dy);
        rightLeg.move(dx, dy);
    }

    void setPosition(float x, float y)
    {
        torso.setPosition(x, y);
        head.setPosition(x + .5f, y - 50);
        leftArm.setPosition(x - 20, y);
        rightArm.setPosition(x + 55, y);
        leftLeg.setPosition(x + 5, y + 100);
        rightLeg.setPosition(x + 30, y + 100);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(torso);
        window.draw(head);
        window.draw(leftArm);
        window.draw(rightArm);
        window.draw(leftLeg);
        window.draw(rightLeg);
    }
};


