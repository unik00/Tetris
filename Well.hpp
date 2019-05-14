#ifndef _WELL_HPP
#define _WELL_HPP
#include <SDL.h>
#include <iostream>
#include "ColorVector.hpp"
class Well{
public:
    Well();
    ~Well();
    void draw(SDL_Renderer *);
    void fillData(int,int,int);
    bool inside(int,int);
    static const int Height = 20, Width = 10;
    int filled[Width][Height];
    void debugWell(){
        for(int i =0;i<Width;++i){
            for(int j=0;j<Height;++j)
                std::cout<<filled[i][j];
        std::cout<<std::endl;
        }
    }
    void clean();
    ColorVector getColor(int,int);
};
#endif
