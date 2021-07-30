#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <stdlib.h>

#define NBCELL 2304 // Cell number in the grid
#define NBCELLROW 36 // Cell number in a row
#define NBCELLCOLUMN 64 // Cell number in a column
#define CELLSIZE 17 // Cell size

void launchGOF(sf::RenderWindow &window);
void drawGrid(int binaryArray[NBCELLROW][NBCELLCOLUMN], sf::RenderWindow &window);
void handleClick(int binaryArray[NBCELLROW][NBCELLCOLUMN], int x, int y);
void playStop(int binaryArray[NBCELLROW][NBCELLCOLUMN], bool isGameLaunched);
int countLivingCell(int binaryArray[NBCELLROW][NBCELLCOLUMN], int row, int column);
void displayMenu(sf::RenderWindow& window, sf::RoundedRectangleShape& startButton, sf::Text& startText);
void randomize(int binaryArray[NBCELLROW][NBCELLCOLUMN]);

#endif
