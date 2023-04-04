#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void moveUp(sf::Vector2f&vect) {
    vect.y -= 10;

}

void moveDown(sf::Vector2f&vect) {
    vect.y += 10;
}

void moveLeft(sf::Vector2f&vect) {
    vect.x -= 10;
}

void moveRight(sf::Vector2f&vect) {
    vect.x += 10;
}

void chColor(sf::RectangleShape&rect) {
    sf::Color color = rect.getFillColor();
    if (color == sf::Color::Cyan) {
        rect.setFillColor(sf::Color::Red);
    }
    else
    {
        rect.setFillColor(sf::Color::Cyan);
    }
}


int main()
{
    const float x_side = 100;
    const float y_side = 100;

    sf::RenderWindow window(sf::VideoMode(1200, 700), "My game");
    window.setFramerateLimit(60);
    
    sf::RectangleShape rect;

    sf::Vector2f rectPosition(600, 400);

    rect.setSize(sf::Vector2f(x_side, y_side));


    float xVelocity = 10;
    float yVelocity = 10;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) moveUp(rectPosition);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) moveDown(rectPosition);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) moveLeft(rectPosition);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) moveRight(rectPosition);


        }

        //physics
        if (rectPosition.x == 0 && rectPosition.y == 00) chColor(rect);
        if (rectPosition.x == 1200 && rectPosition.y == 00) chColor(rect);
        if (rectPosition.x == 0 && rectPosition.y == 700) chColor(rect);
        if (rectPosition.x == 1200 && rectPosition.y == 700) chColor(rect);
        if (rectPosition.x < 0 || rectPosition.x > 1200 - x_side) xVelocity *= -1;
        if (rectPosition.y < 0 || rectPosition.y > 700 - y_side) yVelocity *= -1;

        rect.setPosition(rectPosition);

        rectPosition.x += xVelocity;
        rectPosition.y += yVelocity;

        //render
        window.clear();
        window.draw(rect);
        window.display();
    }

    return 0;
}

