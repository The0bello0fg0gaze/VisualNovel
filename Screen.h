#include "raylib.h"
#include <iostream>
#include <vector>
#pragma once
#include "Movement.h"

void Update();
void Screen_1();

std::vector<Rectangle> Map1 = {
    Rectangle{500,200,900,700}, //0
    Rectangle{500,570,150,50}, //1
    Rectangle{720,520,150,50}, //2
    Rectangle{920,520,60,50}, //3
    Rectangle{1030,520,60,50}, //4
    Rectangle{1140,520,60,50}, //5
    Rectangle{1250,470,150,50} //6
    };

void UpdateScreen(movement &Player, int screen){
    switch (screen) {
    case 1:
        Player.Map_Objects = Map1;
        break;
    default:
        std::cout << " not an case ";
    }
}

void Screen_1(){
    DrawRectangleRec(Rectangle{Map1.at(0).x-50,Map1.at(0).y-50,Map1.at(0).width+100,Map1.at(0).height+100}, Color {255,255,255,255});
    for(int i=1; i < (int)Map1.size(); i++){
        DrawRectangleRec(Map1.at(i), RED);
    }
    
}