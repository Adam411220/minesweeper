#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "MinesweeperBoard.h"
class MSSFMLView
{
    MinesweeperBoard *Board;

public:

    MSSFMLView()
    {
        Board=NULL;
    };
    MSSFMLView(MinesweeperBoard &Board)
    {
        this->Board=&Board;
    };

    void draw(sf::RenderWindow &win)
    {
        int posX=5,posY=5;
        sf::Font font;
        font.loadFromFile("arial.ttf");
        for(int i=0; i<Board->getBoardWidth(); i++)
        {
            posX=5;
            for(int j=0; j<Board->getBoardHeight(); j++)
            {
                sf::RectangleShape rectangle( sf::Vector2f( 20, 20 ) ); // tworzymy prostokąt
                rectangle.setPosition( posX, posY );
                sf::Text text(Board->getFieldInfo(i,j), font);
               text.setCharacterSize(10);
               text.setStyle(sf::Text::Bold);
                text.setColor(sf::Color::Red);
                text.setPosition(rectangle.getPosition().x+3,rectangle.getPosition().y+3);

                rectangle.setOutlineColor( sf::Color::Red );
                rectangle.setOutlineThickness( 2 );
                win.draw(rectangle);
                win.draw(text);
                posX+=20;
            }
            posY+=20;
        }
    }







};
