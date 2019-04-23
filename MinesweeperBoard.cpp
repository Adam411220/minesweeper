#include "MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard()
{
    width=10;
    height=10;

    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
        {
            board[i][j].hasFlag=false;
            board[i][j].hasMine=false;
            board[i][j].isRevealed=false;
        }

}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode )
{

    if(height<=100)
        this->width=width;
    else
        this->width=100;
    if(width<=100)
        this->height=height;
    else
        this->height=100;

    switch(mode)
    {
    case DEBUG:
        break;
    case EASY:
        mine=this->width*this->height*0.1;
        break;
    case NORMAL:
        mine=this->width*this->height*0.2;
        break;
    case HARD:
        mine=this->width*this->height*0.3;
        break;
    }




    for(int i=0; i< this->width; i++)
        for(int j=0; j< this->height; j++)
        {
            board[i][j].hasFlag=false;
            board[i][j].hasMine=false;
            board[i][j].isRevealed=false;
        }

        int x,y;
if(mode!=GameMode::DEBUG)
{


        for(int j=0; j< mine;)
        {
            x=rand()%width;
            y=rand()%height;
            if(!board[x][y].hasMine)
            {
                board[x][y].hasMine=true;
                j++;
            }

        }
}
else
{
       for(int i=0; i< this->width; i++)
        for(int j=0; j< this->height; j++)
        {

            if(j==i)
                board[i][j].hasMine=true;
            if(j==0)
                board[i][j].hasMine=true;
                            if(0==i)
                board[i][j].hasMine=true;

        }
}

}




int MinesweeperBoard::getBoardWidth() const
{
    return width;
}
int MinesweeperBoard::getBoardHeight() const
{
    return height;
}
int MinesweeperBoard::getMineCount() const
{
    return mine;
}


void MinesweeperBoard::revealField(int x, int y)
{
    if(x<width && x>=0)
    {
        if(y<height && y>=0)
        {
            if(!board[x][y].hasFlag && !board[x][y].isRevealed && getGameState()== RUNNING)
            {
                board[x][y].isRevealed=true;
            }
        }
    }
}

void MinesweeperBoard::toggleFlag(int x, int y)
{
    if(x<width && x>=0)
    {
        if(y<height && y>=0)
        {
            if(!board[x][y].isRevealed && getGameState()== RUNNING)
            {
                if(!board[x][y].hasFlag)
                board[x][y].hasFlag=true;
                else
                 board[x][y].hasFlag=false;
            }
        }
    }
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{

    return board[x][y].hasFlag;
}

bool MinesweeperBoard::isRevealed(int x, int y) const
{
    return board[x][y].isRevealed;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const
{
    if(isRevealed( x,  y))
    {
        if(board[x][y].hasMine)
        {
            return 'X';
        }
        else
        {
            switch(countMines( x, y))
            {
            case 0:
                return ' ';
                break;
            case 1:
                return '1';
                break;
            case 2:
                return '2';
                break;
            case 3:
                return '3';
                break;
            case 4:
                return '4';
                break;
            case 5:
                return '5';
                break;
            case 6:
                return '6';
                    break;
            case 7:
                return '7';
                break;
            case 8:
                return '8';
                break;
            }


        }
    }
    else if(hasFlag( x,  y))
    {
        return 'F';
    }
    else
    {
        return '_';
    }

      return '#';
}



/// okreslanie ilosci min wokol///
int MinesweeperBoard::countMines(int x, int y) const
{
    int how_many_mine=0;

    if(board[x-1][y].hasMine && x>0)
    {
        how_many_mine++;
    }
    if(board[x+1][y].hasMine && x<width-1)
    {
        how_many_mine++;
    }
    if(board[x][y-1].hasMine && y>0)
    {
        how_many_mine++;
    }
    if(board[x][y+1].hasMine && y<height-1)
    {
        how_many_mine++;
    }
    if(board[x-1][y-1].hasMine && x>0 && y>0)
    {
        how_many_mine++;
    }
    if(board[x+1][y+1].hasMine && y<height-1 && x<width-1)
    {
        how_many_mine++;
    }
    if(board[x-1][y+1].hasMine && x>0 && y<height-1)
    {
        how_many_mine++;
    }
    if(board[x+1][y-1].hasMine && x<width-1 && y>0)
    {
        how_many_mine++;
    }

    return how_many_mine;

}

GameState MinesweeperBoard::getGameState() const
{

    for(int i=0 ; i<width;i++)
    {
        for(int j=0 ; j<height;j++)
        {
            if(board[i][j].isRevealed && board[i][j].hasMine)
            {
                return GameState::FINISHED_LOSS;
            }
        }
    }
int win=0;
       for(int i=0 ; i<width;i++)
    {
        for(int j=0 ; j<height;j++)
        {
            if(board[i][j].isRevealed && !board[i][j].hasMine )
            {
                win++;
            }
            if((width*height-mine)==win)
            return GameState::FINISHED_WIN;
        }
    }

       for(int i=0 ; i<width;i++)
    {
        for(int j=0 ; j<height;j++)
        {
            if(!board[i][j].isRevealed && !board[i][j].hasMine )
            {
                return GameState::RUNNING;
            }
        }
    }

 return GameState::RUNNING;
}


void MinesweeperBoard::debug_display() const
{

    for(int i=0; i<height; i++)
    {


        for(int j=0; j<width; j++)
        {
            std::cout<<'[';
            if(board[i][j].hasMine)
                std::cout<<'m';
            else
                std::cout<<'.';
            if(board[i][j].isRevealed)
                std::cout<<'O';
            else
                std::cout<<'.';
            if(board[i][j].hasFlag)
                std::cout<<'f';
            else
                std::cout<<'.';
            std::cout<<']';
        }
        std::cout<<std::endl;
    }
}
