#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "game.hpp"

int main(int argc, char* args[]){
    Game newGame;
    while (newGame.tick()){
        if (!newGame.process()) break;
    }
    return 0;
}
