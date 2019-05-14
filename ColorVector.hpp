#ifndef _COLORVECTOR_HPP
#define _COLORVECTOR_HPP

struct ColorVector{
    int r,g,b;
    ColorVector(){
        r=g=b=255;
    }
    ColorVector(int r_,int g_,int b_){
        r=r_;
        g=g_;
        b=b_;
    }
};

#endif
