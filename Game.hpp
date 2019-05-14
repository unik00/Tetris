#ifndef _GAME_HPP
#define _GAME_HPP

#include <SDL.h>
#include "Well.hpp"
#include "Block.hpp"

class Game{
public:
    Game();
    ~Game();
    bool tick();
    bool process();
    Block active;
    Well* well;
private:
    int previousTime;
    int lastCollide;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
#endif
