#include <vector>
#include <iostream>
#include "raylib.h"
#include "Movement.h"
#include "Screen.h"
using namespace std;

int main(){
    
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Main File");
    int screen = 1;
    
    movement Player(Vector2 {500,520});
    UpdateScreen( Player, screen);
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   ClearBackground(Color {180,180,180,255});
        Player.Movement();
        BeginDrawing();
            if(screen == 1) Screen_1(); // draw the background
            
            Player.Update(); // draw player on the screen
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}