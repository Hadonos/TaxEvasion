//Chase Elliott
//9-29-21
//Tetris
#include "raylib.h"

int main(void)
{
    
    const int ScreenWidth = 500;
    const int ScreenHeight = 800;
    
    SetTargetFPS(60);
    InitWindow(ScreenWidth, ScreenHeight, "Tetris");
    while(!WindowShouldClose())
    {
        //Update
        
        
        
        //Draw
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText("Tetris", 25, 25, 25, BLACK);
            DrawFPS(125, 30);
            
        EndDrawing();
    }
    return 0;
}