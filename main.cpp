#include <iostream>
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    srand(time(NULL));
    MinesweeperBoard bord(40,41,GameMode::EASY);
    MSSFMLView M(bord);
    MSTextController ctr(bord,M);



       ctr.Play();

    return 0;
}
