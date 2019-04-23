#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"



class MSTextController
{
    MinesweeperBoard *Bord;
    MSSFMLView *View;
public:
    MSTextController()
    {
        Bord=NULL;
        View=NULL;
    }
    MSTextController( MinesweeperBoard &Bord,MSSFMLView &View)
    {
        this->Bord=&Bord;
        this->View=&View;
    }




    void Play()
    {
        sf::RenderWindow win( sf::VideoMode( Bord->getBoardHeight()*20+10, Bord->getBoardWidth()*20+10), "SAPER" );
        int x,y;
        Bord->debug_display();
        while( win.isOpen() && Bord->getGameState()==GameState::RUNNING )
        {

            sf::Event event;
            while( win.pollEvent( event ) )
            {
                if( event.type == sf::Event::Closed )
                    win.close();

            }
            y=sf::Mouse::getPosition(win).x/20;  //pobiera pozycje myszki i dzieli przez szerokosc pola co daje nam indeks tablicy
            x=sf::Mouse::getPosition(win).y/20;

            if(sf::Mouse::getPosition(win).x<Bord->getBoardWidth()*20+5 && sf::Mouse::getPosition(win).y < Bord->getBoardHeight()*20+5)
            {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    // std:: cout<<x<<" "<<y<<std::endl;
                    Bord->revealField(x, y);

                }


                if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
                {


                    Bord->toggleFlag(x,y);
                }
            }
            win.clear();

            View->draw(win);
  std:: cout<<x<<" "<<y<<std::endl;

            ///  sf::sleep(sf::microseconds(1000000));
            win.display();
        }





    while( win.isOpen() )
    {

        sf::Event event;
        while( win.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                win.close();

        }
        if(Bord->getGameState()==GameState::FINISHED_WIN)
        {
            sf::Font font;
            font.loadFromFile("arial.ttf");
            sf::Text text("WINNN!!!", font);
            text.setCharacterSize(20);
            text.setStyle(sf::Text::Bold);
            text.setColor(sf::Color::Green);
            text.setPosition(0,0);


            View->draw(win);
            win.draw(text);
            win.display();
        }
                if(Bord->getGameState()==GameState::FINISHED_LOSS)
        {
            sf::Font font;
            font.loadFromFile("arial.ttf");
            sf::Text text("LOSSS!!!", font);
            text.setCharacterSize(20);
            text.setStyle(sf::Text::Bold);
            text.setColor(sf::Color::Blue);
            text.setPosition((float)Bord->getBoardHeight(),Bord->getBoardWidth());


            View->draw(win);
            win.draw(text);
            win.display();
        }
    }
    }


};
