#include <SFML/Graphics.hpp>

int main()
{
    const float x_side = 300;
    const float y_side = 100;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "My game");
    window.setFramerateLimit(60);
    
    sf::RectangleShape rect;

    sf::Vector2f rectPosition(600, 350);

    rect.setSize(sf::Vector2f(x_side, y_side));


    float xVelocity = 3;
    float yVelocity = 3;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        //physics
        if (rectPosition.x < 0 || rectPosition.x > 1280 - x_side) xVelocity *= -1;
        if (rectPosition.y < 0 || rectPosition.y > 720 - y_side) yVelocity *= -1;

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