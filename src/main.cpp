#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

std::vector<sf::Shape *> obstacles {};

bool CollisionDetected(const sf::FloatRect& bounding_box) {
    for (auto obs : obstacles) {
        sf::FloatRect obs_bounding = obs->getGlobalBounds();
        if (obs_bounding.intersects(bounding_box)) {
            std::cout << "Collision \n";
            return true;
        }
    }
    return false;
}

void CheckAndMove(sf::Shape& object) {
    static const float speed = 2.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            // left key is pressed: move our character
            object.move(-speed, 0.f);
            if (CollisionDetected(object.getGlobalBounds()))
                object.move(speed, 0.f);
        }

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            // left key is pressed: move our character 
            object.move(speed, 0.f);
            if (CollisionDetected(object.getGlobalBounds()))
                object.move(-speed, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            // left key is pressed: move our character 
            object.move(0.f, -speed);
            if (CollisionDetected(object.getGlobalBounds()))
                object.move(0.f, speed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            // left key is pressed: move our character 
            object.move(0.f, speed);
            if (CollisionDetected(object.getGlobalBounds()))
                object.move(0.f, -speed);
        }
} 

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML-Intro");
    sf::RectangleShape shape(sf::Vector2f(40.f, 40.f));
    
    sf::RectangleShape *obs1 = new sf::RectangleShape(sf::Vector2f(90.f, 40.f));
    obstacles.push_back(obs1);
    sf::RectangleShape *obs2 = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    obstacles.push_back(obs2);
    sf::RectangleShape *obs3 = new sf::RectangleShape(sf::Vector2f(40.f, 70.f));
    obstacles.push_back(obs3);

    obs1->setPosition(100.f, 100.f);
    obs2->setPosition(400.f, 400.f);
    obs3->setPosition(1000.f, 200.f);

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
        for (auto obs : obstacles) {
            auto obj = dynamic_cast<sf::Drawable*>(obs);
            window.draw(*obj);
        }
        window.display();
    }

    return 0;
}