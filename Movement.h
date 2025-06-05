#include "raylib.h"
#include <vector>
#pragma once

class movement{
    
    private:
    float MovementSpeed = 0.15;
    Rectangle Player_Rect = {0,0,50,50};
    
    public:
    std::vector<Rectangle> Map_Objects;
    bool Enable = true;
    movement(Vector2 Pos){
        Player_Rect.x = Pos.x;
        Player_Rect.y = Pos.y;
    }
    
    void Update(){
        DrawRectangleRec(Player_Rect, RED);
    }
    
    void Movement(){
        if(Enable){
            Rectangle Temp_Position = Player_Rect;
            if(IsKeyDown(KEY_A)){
                Player_Rect.x -= MovementSpeed;
            }else if(IsKeyDown(KEY_D)){
                Player_Rect.x += MovementSpeed;
            }else if(IsKeyDown(KEY_W)){
                Player_Rect.y -= MovementSpeed;
            }else if(IsKeyDown(KEY_S)){
                Player_Rect.y += MovementSpeed;
            }
            
            if(PlayerCollison()) Player_Rect = Temp_Position;
        }
    }
    
    bool PlayerCollison(){
        for(int i=0; i < (int)Map_Objects.size(); i++){ 
            bool collison = CheckCollisionRecs(Map_Objects.at(i), Player_Rect);
            switch (i) {
            case 0:
                if(!collison) return true;
                break;
            default:
                if(collison) return true;
            }
        }
        return false;
    }
    
};
