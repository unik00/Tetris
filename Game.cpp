#include "Game.hpp"
#include <iostream>
#include <random>

Game::Game(){
    previousTime = SDL_GetTicks();
    well = new Well;
    if (SDL_Init(SDL_INIT_VIDEO)){
        std::cerr<<"SDL_Init(SDL_INIT_VIDEO)"<<std::endl;
    }
    SDL_CreateWindowAndRenderer(720/2,720,SDL_WINDOW_OPENGL, &window,&renderer);
    well->draw(renderer);

    SDL_RenderPresent(renderer);
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

}

int ccc=0;

bool Game::tick(){
 SDL_Event e;
  if (SDL_WaitEventTimeout(&e, 1)){

    switch (e.type)
    {

    case SDL_KEYDOWN:
      {
        switch (e.key.keysym.sym)
        {
        case SDLK_DOWN:
          {
            active.move(0, 1, well);

          }
        break;

        case SDLK_RIGHT:
          {
              active.move(1,0,well);
           }
          break;
        case SDLK_LEFT:
          {
              active.move(-1,0,well);
            }
          break;
        case SDLK_UP:
          {
              active.rotateBlock(well);
            }
          break;
        case SDLK_SPACE:
            {
                while (!active.collided(well)) active.move(0,1,well);
            }
            break;
        }
      }
      break;
    case SDL_QUIT:
      return false;
        }

    }
    return true;
}

bool Game::process(){
//    printf("%d %d\n", SDL_GetTicks(), previousTime);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
    SDL_RenderClear(renderer);

    well->clean();
    well->draw(renderer);

    active.draw(renderer);

    SDL_RenderPresent(renderer);

    if (SDL_GetTicks() - previousTime > 400){
        for(int i = 0; i < 4; ++i)
            for(int j = 0; j < 4; ++j)
                if (active.isPoint(i,j) && well->filled[active.getX()+i][active.getY()+j])
        {
            std::cout << "You losed!" << std::endl;
            SDL_Delay(2000);
            return false;
        }

        if (active.collided(well)){
            if (true){
                for(int i = 0; i < 4; ++i)
                    for(int j = 0; j < 4; ++j) if (active.isPoint(i,j)){
                        std::cout << active.getX()+i << " " << active.getY()+j << std::endl;
                        if (!well->inside(active.getX()+i,active.getY()+j)) return false;
                        well->fillData(active.getX()+i,active.getY()+j,active.getType());
                    }
                active=Block();
            }
        }
        active.move(0,1,well);
        previousTime =SDL_GetTicks();
    }
    return true;
}
