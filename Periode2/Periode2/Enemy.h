#pragma once
#include <SFML/Graphics.hpp>
class Enemy
{
    sf::CircleShape ball;
    float speed;

public:
    Enemy(float radius, float x, float y, float enemySpeed)
        : speed(enemySpeed)
    {
        ball.setRadius(radius);
        ball.setFillColor(sf::Color::Red);
        ball.setPosition(x, y);
    }
    void update()
    {
       
        ball.move(-speed, 0);

        
        if (ball.getPosition().x + 2 * ball.getRadius() < 0)
        {
            ball.setPosition(800, ball.getPosition().y);
        }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(ball);
    }

    void setPosition(float x, float y)
    {
        ball.setPosition(x, y);
    }

    sf::Vector2f getPosition() const
    {
        return ball.getPosition();
    }

    float getRadius() const
    {
        return ball.getRadius();
    }

    const sf::CircleShape& getShape() const
    {
        return ball;
    }

    void reset(float x, float y)
    {
        setPosition(x, y);  
    }
};




