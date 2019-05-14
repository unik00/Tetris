#include "Well.hpp"

void Well::fillData(int x,int y,int t){
    filled[x][y]=t+1;
}

bool Well::inside(int x,int y){
    return x>=0 && x<10 && y>=0 && y<20;
}

Well::Well(){
    for(int i = 0; i < Width; ++i)
        for(int j = 0; j < Height; ++j){
            filled[i][j] = 0;
        }

}

Well::~Well(){

}

void Well::clean(){
    while(true){
        bool didSomething=0;
        for(int j=0;j<Height;++j){
            bool solid=1;
            for(int i=0;i<Width;++i) if (!filled[i][j]) {
                solid=0;
                break;
            }
            if (solid){
                didSomething=1;
                for(int k=j;k>0;--k) for(int i=0;i<Width;++i)
                    filled[i][k]=filled[i][k-1];
                for(int i=0;i<Width;++i) filled[i][0]=0;
            }
        }
        if (!didSomething) break;
    }


}

void Well::draw(SDL_Renderer *renderer){

    for (int x = 0; x <= Width; ++x)
    for (int y = 0; y <= Height; ++y){

            SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderDrawPoint(renderer, 720/2/Width*(x),720/Height*(y));
        if (filled[x][y]){
            ColorVector tmp=getColor(x,y);
            SDL_SetRenderDrawColor(renderer, tmp.r,tmp.g,tmp.b,255);

            SDL_Rect rect{720/2/Width*(x)+2,720/Height*(y)+2,32,32};
            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

ColorVector Well::getColor(int x,int y){
    ColorVector ret;
    int t=this->filled[x][y]-1;
    if (t==0){
        ret={244, 66, 66};
    }
    else if (t==1){
        ret={244, 208, 65};
    }
    else if (t==2){

        ret={73, 244, 65};
    }
    else if (t==3){

        ret={65, 106, 244};
    }
    else if(t==4){

        ret={184, 65, 244};
    }
    else if (t==5){

        ret={244, 65, 172};
    }
    else if (t==6){

        ret={65, 244, 238};
    }
    return ret;
}

