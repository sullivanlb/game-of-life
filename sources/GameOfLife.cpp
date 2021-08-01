#include "gameOfLife.h"

/*
* @brief display the menu
* @param window - the window where we display the menu
*/
void displayMenu(sf::RenderWindow& window, sf::RoundedRectangleShape& startButton, sf::RoundedRectangleShape& stopButton, sf::RoundedRectangleShape& clearButton, sf::RoundedRectangleShape& randomButton, sf::Text& scoreValueText, sf::RoundedRectangleShape& minusDelayButton, sf::RoundedRectangleShape& plusDelayButton, sf::Text& delayValueText)
{
    sf::Vector2u size = window.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    // Background
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Blue);
    background.setPosition(sf::Vector2f(width - 200, 0));

    sf::Font font;
    if (!font.loadFromFile("ressources/GoogleSans-Bold.ttf"))
    {
        if (!font.loadFromFile("GoogleSans-Bold.ttf"))
        {
            std::cerr << "ERROR font loading !" << std::endl;
        }
    }

    // Score text
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score :");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(sf::Vector2f(width - 190, 10));

    // Score value text
    scoreValueText.setFont(font);
    scoreValueText.setCharacterSize(24);
    scoreValueText.setPosition(sf::Vector2f(width - 100, 10));

    // Start button
    startButton.setOutlineThickness(5.f);
    startButton.setOutlineColor(sf::Color::White);
    startButton.setPosition(sf::Vector2f(width - 185, 100));

    // Start button text
    sf::Text startText;
    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(24);
    startText.setPosition(sf::Vector2f(width - 130, 105));

    // Stop button
    stopButton.setOutlineThickness(5.f);
    stopButton.setOutlineColor(sf::Color::White);
    stopButton.setPosition(sf::Vector2f(width - 185, 160));

    // Stop button text
    sf::Text stopText;
    stopText.setFont(font);
    stopText.setString("Stop");
    stopText.setCharacterSize(24);
    stopText.setPosition(sf::Vector2f(width - 127, 165));

    // Clear button
    clearButton.setOutlineThickness(5.f);
    clearButton.setOutlineColor(sf::Color::White);
    clearButton.setPosition(sf::Vector2f(width - 185, 220));

    // Clear button text
    sf::Text clearText;
    clearText.setFont(font);
    clearText.setString("Clear");
    clearText.setCharacterSize(24);
    clearText.setPosition(sf::Vector2f(width - 130, 225));

    // Random button
    randomButton.setOutlineThickness(5.f);
    randomButton.setOutlineColor(sf::Color::White);
    randomButton.setPosition(sf::Vector2f(width - 185, 280));

    // Random button text
    sf::Text randomText;
    randomText.setFont(font);
    randomText.setString("Random");
    randomText.setCharacterSize(24);
    randomText.setPosition(sf::Vector2f(width - 147, 285));

    // Delay text
    sf::Text delayText;
    delayText.setFont(font);
    delayText.setString("Delay : ");
    delayText.setCharacterSize(24);
    delayText.setPosition(sf::Vector2f(width - 185, height - 250));

    // Delay value text
    delayValueText.setFont(font);
    delayValueText.setCharacterSize(24);
    delayValueText.setPosition(sf::Vector2f(width - 100, height - 250));

    // Minus delay button
    minusDelayButton.setOutlineThickness(3.f);
    minusDelayButton.setOutlineColor(sf::Color::White);
    minusDelayButton.setPosition(sf::Vector2f(width - 185, 400));

    // Minus delay button text
    sf::Text minusDelayText;
    minusDelayText.setFont(font);
    minusDelayText.setString("-");
    minusDelayText.setCharacterSize(24);
    minusDelayText.setPosition(sf::Vector2f(width - 152, 405));

    // Plus delay button
    plusDelayButton.setOutlineThickness(3.f);
    plusDelayButton.setOutlineColor(sf::Color::White);
    plusDelayButton.setPosition(sf::Vector2f(width - 95, 400));

    // Plus delay button text
    sf::Text plusDelayText;
    plusDelayText.setFont(font);
    plusDelayText.setString("+");
    plusDelayText.setCharacterSize(24);
    plusDelayText.setPosition(sf::Vector2f(width - 63, 405));

    // Credits text
    sf::Text creditsText;
    creditsText.setFont(font);
    creditsText.setString("Credits: Sullivan Leboeuf");
    creditsText.setCharacterSize(12);
    creditsText.setPosition(sf::Vector2f(width - 178, height - 20));

    window.draw(background);
    window.draw(scoreText);
    window.draw(scoreValueText);
    window.draw(startButton);
    window.draw(startText);
    window.draw(stopButton);
    window.draw(stopText);
    window.draw(clearButton);
    window.draw(clearText);
    window.draw(randomButton);
    window.draw(randomText);
    window.draw(delayText);
    window.draw(delayValueText);
    window.draw(creditsText);
    window.draw(minusDelayButton);
    window.draw(minusDelayText);
    window.draw(plusDelayButton);
    window.draw(plusDelayText);
    window.draw(creditsText);
}

/*
* @brief draw the grid according to the array
* @param binaryArray - the array to be taken into account
* @param window - the window where we want to draw
*/
void drawGrid(int binaryArray[NBCELLROW][NBCELLCOLUMN], sf::RenderWindow &window)
{
    float x = 1;
    float y = 1;

    for (unsigned int i = 0; i < NBCELLROW; i++)
    {
        for (unsigned int j = 0; j < NBCELLCOLUMN; j++)
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

/*
* @brief count the number of living cell around the given cell
* @param binaryArray - contain the grid
* @param row - the row of the cell
* @param column - the column of the cell
*/
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

/*
* @brief if isGameLaunch is true then a new binaryArray is calculate following the two game of life rules
* @param binaryArray - contain the grid
* @param isGameLaunched - true if the game is launched, false otherwise
*/
void playStop(int binaryArray[NBCELLROW][NBCELLCOLUMN], bool isGameLaunched, int& counter, int& delay)
{
    if (isGameLaunched)
    {
        int testedArray[NBCELLROW][NBCELLCOLUMN];
        for (unsigned int i = 0; i < NBCELLROW; i++)
        {
            for (unsigned int j = 0; j < NBCELLCOLUMN; j++)
            {
                testedArray[i][j] = binaryArray[i][j];
            }
        }

        for (unsigned int i = 0; i < NBCELLROW; i++)
        {
            for (unsigned int j = 0; j < NBCELLCOLUMN; j++)
            {
                // if the tested cell is dead
                if (testedArray[i][j] == 0)
                {
                    if (countLivingCell(testedArray, i, j) == 3)
                    {
                        binaryArray[i][j] = 1;
                        counter++;
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
        sf::sleep(sf::milliseconds(delay));
    }
}

void clearBinaryArray(int binaryArray[NBCELLROW][NBCELLCOLUMN])
{
    for (unsigned int i = 0; i < NBCELLROW; i++)
    {
        for (unsigned int j = 0; j < NBCELLCOLUMN; j++)
        {
            binaryArray[i][j] = 0;
        }
    }
}

/*
* @brief get the binary array and randomize the living cell and the ones
* @param binaryArray - the binary array to randomize
*/
void randomize(int binaryArray[NBCELLROW][NBCELLCOLUMN])
{
    clearBinaryArray(binaryArray);

    for (unsigned int i = 0; i < NBCELLROW; i++)
    {
        int livingCellRow = rand() % (NBCELLCOLUMN / 2);

        for (unsigned int j = 0; j < livingCellRow; j++)
        {
            int randomLivingCell = rand() % NBCELLCOLUMN;
            if (binaryArray[i][randomLivingCell] == 1) j--;
            else binaryArray[i][randomLivingCell] = 1;
        }
    }
}

/*
* @brief launch the game of life
*/
void launchGOF(sf::RenderWindow& window)
{
    sf::RoundedRectangleShape startButton(sf::Vector2f(170.f, 40.f), 10.f, 50);
    sf::RoundedRectangleShape stopButton(sf::Vector2f(170.f, 40.f), 10.f, 50);
    sf::RoundedRectangleShape clearButton(sf::Vector2f(170.f, 40.f), 10.f, 50);
    sf::RoundedRectangleShape randomButton(sf::Vector2f(170.f, 40.f), 10.f, 50);
    sf::RoundedRectangleShape minusDelayButton(sf::Vector2f(80.f, 40.f), 10.f, 50);
    sf::RoundedRectangleShape plusDelayButton(sf::Vector2f(80.f, 40.f), 10.f, 50);
    
    sf::Text delayText;
    delayText.setString("250");

    sf::Text scoreValueText;
    scoreValueText.setString("0");

    startButton.setFillColor(sf::Color::Blue);
    stopButton.setFillColor(sf::Color::Blue);
    clearButton.setFillColor(sf::Color::Blue);
    randomButton.setFillColor(sf::Color::Blue);
    minusDelayButton.setFillColor(sf::Color::Blue);
    plusDelayButton.setFillColor(sf::Color::Blue);

    bool isGameLaunched = false;
    int counter = 0;
    int delay = 250;

    // fill the binary array with zero
    int binaryArray[NBCELLROW][NBCELLCOLUMN];
    clearBinaryArray(binaryArray);

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
                    if (!(event.mouseButton.x > 1090))
                    {
                        handleClick(binaryArray, event.mouseButton.y, event.mouseButton.x);
                    }
                }

                if (event.mouseButton.x > 1090)
                {
                    // if startButton is clicked
                    if (event.mouseButton.x >= startButton.getPosition().x && event.mouseButton.x <= startButton.getPosition().x + startButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= startButton.getPosition().y && event.mouseButton.y <= startButton.getPosition().y + startButton.getLocalBounds().height)
                        {
                            isGameLaunched = true;
                        }
                    }

                    // if stopButton is clicked
                    if (event.mouseButton.x >= stopButton.getPosition().x && event.mouseButton.x <= stopButton.getPosition().x + stopButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= stopButton.getPosition().y && event.mouseButton.y <= stopButton.getPosition().y + stopButton.getLocalBounds().height)
                        {
                            isGameLaunched = false;
                        }
                    }

                    // if clearButton is clicked
                    if (event.mouseButton.x >= clearButton.getPosition().x && event.mouseButton.x <= clearButton.getPosition().x + clearButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= clearButton.getPosition().y && event.mouseButton.y <= clearButton.getPosition().y + clearButton.getLocalBounds().height)
                        {
                            clearBinaryArray(binaryArray);
                            isGameLaunched = false;
                        }
                    }

                    // if randomButton is clicked
                    if (event.mouseButton.x >= randomButton.getPosition().x && event.mouseButton.x <= randomButton.getPosition().x + randomButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= randomButton.getPosition().y && event.mouseButton.y <= randomButton.getPosition().y + randomButton.getLocalBounds().height)
                        {
                            randomize(binaryArray);
                        }
                    }

                    // if minusDelayButton is clicked
                    if (event.mouseButton.x >= minusDelayButton.getPosition().x && event.mouseButton.x <= minusDelayButton.getPosition().x + minusDelayButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= minusDelayButton.getPosition().y && event.mouseButton.y <= minusDelayButton.getPosition().y + minusDelayButton.getLocalBounds().height)
                        {
                            if (delay > 1) delay -= (delay / 2);
                        }
                    }

                    // if plusDelayButton is clicked
                    if (event.mouseButton.x >= plusDelayButton.getPosition().x && event.mouseButton.x <= plusDelayButton.getPosition().x + plusDelayButton.getLocalBounds().width)
                    {
                        if (event.mouseButton.y >= plusDelayButton.getPosition().y && event.mouseButton.y <= plusDelayButton.getPosition().y + plusDelayButton.getLocalBounds().height)
                        {
                            if (delay > 1) delay += (delay / 2);
                            else delay += 1;
                        }
                    }
                }
            }
        }

        scoreValueText.setString(std::to_string(counter));

        if (delay > 1000) delayText.setString(std::to_string(delay/1000) + " s");
        else delayText.setString(std::to_string(delay) + " ms");

        playStop(binaryArray, isGameLaunched, counter, delay);
        window.clear();
        displayMenu(window, startButton, stopButton, clearButton, randomButton, scoreValueText, minusDelayButton, plusDelayButton, delayText);
        drawGrid(binaryArray, window);
        window.display();
    }
}