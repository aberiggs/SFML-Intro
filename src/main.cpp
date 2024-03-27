#include <SFML/Graphics.hpp>

void CheckAndMove(sf::Shape& object) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // left key is pressed: move our character 
            object.move(-1.f, 0.f);
        }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // left key is pressed: move our character 
            object.move(1.f, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // left key is pressed: move our character 
            object.move(0.f, -1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // left key is pressed: move our character 
            object.move(0.f, 1.f);
        }
} 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML-Intro");
    sf::RectangleShape shape(sf::Vector2f(40.f, 40.f));
    shape.setFillColor(sf::Color(190, 200, 220, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        CheckAndMove(shape);


        window.clear(sf::Color(45, 50, 50, 255));
        window.draw(shape);
        window.display();
    }

    return 0;
}