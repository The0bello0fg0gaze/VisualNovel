#include "raylib.h"
#include <vector>
#pragma once

class movement{
    
    private:
    float MovementSpeed = 0.15;
    Rectangle Player_Rect = {0,0,50,50};
    float g = 0.05;
    bool IsOnGround = true;
    
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
    
    void Movement() {
        if (Enable) {
            Rectangle Temp_Position = Player_Rect;
            // Horizontal movement
            if (IsKeyDown(KEY_A)) {
                Player_Rect.x -= MovementSpeed;
            } else if (IsKeyDown(KEY_D)) {
                Player_Rect.x += MovementSpeed;
            }
            
            // Jump trigger
            if (IsKeyPressed(KEY_SPACE) && IsOnGround) {
                g = -0.5;
                IsOnGround = false;
            }

            // Apply gravity
            Player_Rect.y += g;
            g += 0.001;
            if (g > 0.5) g = 0.5; // Clamp gravity fall speed

            // Collision check
            if (PlayerCollison()) {
                IsOnGround = true;
                Player_Rect = Temp_Position;
                g = 0; // Stop gravity when on ground
            }
        }
    }
    
    bool PlayerCollison(){
        for(int i=0; i < (int)Map_Objects.size(); i++){ 
            bool collison = CheckCollisionRecs(Map_Objects.at(i), Player_Rect);
            switch (i) {
            case 0: // return true if player is not inside the rectangle 
                if(!collison) return true;
                break;
            default: // return true if player is inside the rectangle
                if(collison) return true;
            }
        }
        return false;
    }
    
};
