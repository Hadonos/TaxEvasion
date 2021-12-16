//Chase Elliott
//Started 9-10-21

#include "raylib.h"

int main(void)
{
    const int ScreenWidth = 500;
    const int ScreenHeight = 500;
    
    InitWindow(ScreenWidth, ScreenHeight, "Collision");
    
    Rectangle Player = {0, 0, 50, 50};
    
    Rectangle Obstacle = {ScreenWidth/2 - 25, 0, 50, 50};
    int ObstacleSpeed = 5;
    
    bool collision = false;
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        //Update
        if (IsKeyDown(KEY_RIGHT)) Player.x += 2;
        if (IsKeyDown(KEY_LEFT)) Player.x -= 2;
        if (IsKeyDown(KEY_DOWN)) Player.y += 2;
        if (IsKeyDown(KEY_UP)) Player.y -= 2;
        
        if (Player.x <= -2) Player.x += 2;
        if (Player.y <= -2) Player.y += 2;
        if (Player.x >= ScreenWidth - 50 + 2) Player.x -= 2;
        if (Player.y >= ScreenHeight - 50 + 2) Player.y -= 2;
        
        Obstacle.y += ObstacleSpeed;
        if ((Obstacle.y + Obstacle.height) >= ScreenHeight || (Obstacle.y <= 0)) ObstacleSpeed *= -1;
        
        if (CheckCollisionRecs(Player, Obstacle)) collision = true;
        else collision = false;
        
        //Draw
        BeginDrawing();
            ClearBackground(WHITE);
            DrawFPS(20, 20);
            DrawText("Collision Practice", 110, 20, 20, BLACK);
            
            DrawRectangleRec(Obstacle, RED);
            DrawRectangleRec(Player, BLACK);
            
            if (collision) 
            {
                DrawRectangle(0, 400, 500, 100, RED);
                DrawText("Colision Detected", 150, 450, 20, BLACK);
            }
            
        EndDrawing();
        
    }
    CloseWindow();
    return(0);
}