#include "gameOfLife.h"

/*
* @brief draw the grid according to the array
* @param binaryArray - the array to be taken into account
* @param window - the window where we want to draw
*/
void drawGrid(int binaryArray[NBCELLROW][NBCELLCOLUMN], sf::RenderWindow &window)
{
    float x = 1;
    float y = 1;

    for (int i = 0; i < NBCELLROW; i++)
    {
        for (int j = 0; j < NBCELLCOLUMN; j++)
        {
            sf::RectangleShape cell(sf::Vector2f(17.f, 17.f));
            cell.setOutlineThickness(1.f);
            cell.setOutlineColor(sf::Color::Black);
            cell.setPosition({ x, y });

            binaryArray[i][j] == 0 ? cell.setFillColor(sf::Color::White) : cell.setFillColor(sf::Color::Black);

            window.draw(cell);

            if (j != NBCELLCOLUMN - 1)
            {
                x = x + 17;
            }
            else
            {
                y = y + 17;
                x = 1;
            }
        }
    }
}

/*
* @brief detect the clicked cell and change his state
* @param binaryArray - the array to analyze
* @param x - the x position of the mouse
* @param y - the y position of the mouse
*/
void handleClick(int binaryArray[NBCELLROW][NBCELLCOLUMN], int x, int y)
{
    int rowCellDetected = x / CELLSIZE;
    int columnCellDetected = y / CELLSIZE;

    if (binaryArray[rowCellDetected][columnCellDetected] == 0)
    {
        binaryArray[rowCellDetected][columnCellDetected] = 1;
    }
    else
    {
        binaryArray[rowCellDetected][columnCellDetected] = 0;
    }
}

int countLivingCell(int binaryArray[NBCELLROW][NBCELLCOLUMN], int row, int column)
{
    int count = 0;

    if (binaryArray[row - 1][column - 1] == 1) count++;
    if (binaryArray[row - 1][column] == 1) count++;
    if (binaryArray[row - 1][column + 1] == 1) count++;
    if (binaryArray[row][column - 1] == 1) count++;
    if (binaryArray[row][column + 1] == 1) count++;
    if (binaryArray[row + 1][column - 1] == 1) count++;
    if (binaryArray[row + 1][column] == 1) count++;
    if (binaryArray[row + 1][column + 1] == 1) count++;

    return count;
}

void playStop(int binaryArray[NBCELLROW][NBCELLCOLUMN], bool isGameLaunched)
{
    if (isGameLaunched)
    {
        int testedArray[NBCELLROW][NBCELLCOLUMN];
        for (int i = 0; i < NBCELLROW; i++)
        {
            for (int j = 0; j < NBCELLCOLUMN; j++)
            {
                testedArray[i][j] = binaryArray[i][j];
            }
        }

        for (int i = 0; i < NBCELLROW; i++)
        {
            for (int j = 0; j < NBCELLCOLUMN; j++)
            {
                // if the tested cell is dead
                if (testedArray[i][j] == 0)
                {
                    if (countLivingCell(testedArray, i, j) == 3)
                    {
                        binaryArray[i][j] = 1;
                    }
                }
                // if the tested cell is alive
                else if (testedArray[i][j] == 1)
                {
                    if (!(countLivingCell(testedArray, i, j) == 3) && !(countLivingCell(testedArray, i, j) == 2))
                    {
                        binaryArray[i][j] = 0;
                    }
                }
            }
        }
        sf::sleep(sf::milliseconds(250));
    }
}

/*
* @brief launch the game of life
*/
void launchGOF(sf::RenderWindow& window)
{
    bool isGameLaunched = false;

    // fill the binary array with zero
    int binaryArray[NBCELLROW][NBCELLCOLUMN];
    for (int i = 0; i < NBCELLROW; i++)
    {
        for (int j = 0; j < NBCELLCOLUMN; j++)
        {
            binaryArray[i][j] = 0;
        }
    }

    // keep the window open until close
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    handleClick(binaryArray, event.mouseButton.y, event.mouseButton.x);
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::P)
                {
                    isGameLaunched = !isGameLaunched;
                }
            }

        }

        playStop(binaryArray, isGameLaunched);

        window.clear();
        drawGrid(binaryArray, window);
        window.display();
    }
}