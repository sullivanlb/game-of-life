#include <SFML/Graphics.hpp>

#include "gameOfLife.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1290, 613), "Cellular Automaton", sf::Style::Close);
    launchGOF(window);

    return 0;
}