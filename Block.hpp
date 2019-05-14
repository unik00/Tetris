#ifndef _BLOCK_HPP
#define _BLOCK_HPP
#include <SDL.h>
#include <cstdio>
#include "Well.hpp"
#include "ColorVector.hpp"

class Block{
public:
    Block();
    Block(int,int,int,int);
    ~Block();
    void draw(SDL_Renderer *);
    bool isPoint(int,int);
    ColorVector getColor();
    void move(int,int,Well*);
    int getX(){return x;}
    int getY(){return y;}
    bool collided(Well*);
    void rotateBlock(Well*);
    int getType(){
        return type;
    }
private:
    int x,y;
//    types: 0-I, 1-J, 2-L, 3-O, 4-S, 5-T, 6-Z
    int type,rot;
};
#endif
