#include "graphics.hpp"
#include <cmath>
#include <ctime>
#include <random>
#include <vector>

using namespace genv;
using namespace std;
const int szel = 600;
const int mag = 600;
struct Ho {
    Ho(int xx, int yy):
    x(xx), y(yy)
    {
    }
    void rajzol() {
        gout<<color(255,255,255)<<move_to(x,y)<<dot;
    }
    void mozog(int dx, int dy) {
        x += dx;
        y= (y+dy)%mag;
    }
private:
    int x,y;
};
int main()
{
    int n = 1000;
    gout.open(szel,mag);
    gout << font("LiberationSans-Regular.ttf",20);
 /* gout<<color(0,0,255)<<move_to(50,50)<<box(700,500)<< refresh;
    gout<< move_to(300,350)<<color(0,255,255)<<dot;
    gout<<line_to(500,350)<<line_to(400,250)<<line_to(300,350) << refresh;
    */
/*
    event ev;
    while(gin >> ev)
    {
        /* if (ev.button == btn_left) {
            gout<<move_to(ev.pos_x, ev.pos_y)<<color(255,255,255)<<dot<<refresh;
       }*/
        /*if (ev.button==btn_left) {
            gout<<line_to(ev.pos_x,ev.pos_y)<<color(255,255,255)<<refresh;
        }*/
        /*
        if (ev.type == ev_mouse){
            gout<<move_to(20,550)<<refresh;
            gout<<color(255,255,255)<<text(std::to_string(ev.pos_x) +", "+std::to_string(ev.pos_y))<<color(0,0,0)<<box_to(20,500)<<refresh;

     *  }
    }
  */

    vector<Ho> v;
    gout<<move_to(0,0);
    gout<<color(0,0,0)<<refresh;
    gout<<box(szel,mag);
    gout<<color(255,255,255);
    for (int i = 0; i<n;i++) {
        v.push_back(Ho(rand()%szel, rand()%mag));
    }
    for (int i = 0; i<v.size();i++) {
        v[i].rajzol();

    }
    gout<<refresh;


    event ev;
    gin.timer(50);
    while (gin>>ev) {
        if (ev.type == ev_timer) {
            for (int i=0; i<v.size();i++) {
                v[i].mozog(rand()%7-3, rand()%11-3);
            }
            gout<<color(0,0,0)<<move_to(0,0)<<box(szel,mag)<<color(255,255,255);
            for (int i=0; i<v.size();i++) {
                v[i].rajzol();
            }
        }
        gout<<refresh;

    }
    return 0;
}
