#include "Block.hpp"
#include <cstdio>
#include <random>

Block::Block(){
    type = rand()%7;
    rot = 0;
    x = 4;
    y=0;
}

Block::Block(int type_,int rot_,int x_,int y_): type(type_), rot(rot_), x(x_),y(y_){
}

Block::~Block(){

}


void Block::rotateBlock(Well* playfield){
    int tmp=rot;
    rot=(rot+1)%4;
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) if (isPoint(i,j)&&playfield->filled[x+i][y+j]){
        rot=tmp;
        return;
    }

}

bool Block::collided(Well* playfield){
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j) if (isPoint(i,j)){
            if (y+j==19) return true;
            if (playfield->inside(x+i,y+j+1) && playfield->filled[x+i][y+j+1])
                return true;
        }
    return false;
}

void Block::move(int u,int v, Well* playfield){
    int xx=x+u, yy=y + v;
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j) if (this->
            isPoint(i,j)){
            if (!playfield->inside(xx+i,yy+j)) return;
            if (playfield->inside(xx+i,yy+j) && playfield->filled[xx+i][yy+j])
                    return;
            }

    x = xx;
    y = yy;
}


bool Block::isPoint(int i,int j){
    static const char *Shapes[][4] = {
    {
      "*   "
      "*   "
      "*   "
      "*   ",
      "****"
      "    "
      "    "
      "    ",

      "*   "
      "*   "
      "*   "
      "*   ",

      "****"
      "    "
      "    "
      "    ",
    },
    {
      " *  "
      " *  "
      "**  "
      "    ",
      "*   "
      "*** "
      "    "
      "    ",
      "**  "
      "*   "
      "*   "
      "    ",
      "*** "
      "  * "
      "    "
      "    ",
    },
    {
      "*   "
      "*   "
      "**  "
      "    ",
      "*** "
      "*   "
      "    "
      "    ",
      "**  "
      " *  "
      " *  "
      "    ",
      "  * "
      "*** "
      "    "
      "    ",
    },
    {
      "**  "
      "**  "
      "    "
      "    ",
      "**  "
      "**  "
      "    "
      "    ",

      "**  "
      "**  "
      "    "
      "    ",

      "**  "
      "**  "
      "    "
      "    ",
    },
    {
      " *  "
      "**  "
      "*   "
      "    ",
      "**  "
      " ** "
      "    "
      "    ",

      " *  "
      "**  "
      "*   "
      "    ",
      "**  "
      " ** "
      "    "
      "    ",
    },
    {
      "*   "
      "**  "
      "*   "
      "    ",

      "*** "
      " *  "
      "    "
      "    ",

      " *  "
      "**  "
      " *  "
      "    ",

      " *  "
      "*** "
      "    "
      "    ",
    },
    {
      "*   "
      "**  "
      " *  "
      "    ",
      " ** "
      "**  "
      "    "
      "    ",

      "*   "
      "**  "
      " *  "
      "    ",

      " ** "
      "**  "
      "    "
      "    ",
    }
  };
    return Shapes[type][rot][j*4+i]=='*';
}

void Block::draw(SDL_Renderer *renderer){

    ColorVector tmp=getColor();
//    printf("%d %d %d\n", tmp.r,tmp.g,tmp.b);
    SDL_SetRenderDrawColor(renderer, tmp.r, tmp.g, tmp.b, 255);

    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j) if (isPoint(i,j)){
        //    printf("%d %d\n",i,j);
            SDL_Rect rect{x*36 +36 * i+2,y*36 +36 * j+2,32,32};
            SDL_RenderFillRect(renderer, &rect);
        }
}

ColorVector Block::getColor(){
    ColorVector ret;
    int t=this->type;
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
