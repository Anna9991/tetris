#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    size_t width = 800;
    size_t height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris");

    size_t halfW = width / 4;
    size_t borders = 100;
    size_t squareSize = (halfW - borders) / 5;

    // Creating our shape.
    sf::RectangleShape rectangle(sf::Vector2f(squareSize, squareSize));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2);

//    rectangle.setPosition(320,240);
//    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < 10; ++i)
        {
            for (size_t j = 0; j < 20; ++j)
            {
                rectangle.setPosition(halfW + borders + (i * squareSize),j * squareSize);
                window.draw(rectangle); // Drawing our shape.
            }
        }
        window.display();
    }

    return 0;
}
