//Chase Elliott
//9/30/2021
//Basic Platformer

#include "Raylib.h"

int main(void)
{
    
    int ScreenWidth = 1000;
    int ScreenHeight = 800;
    float GravitySpeed = .5;
    float Gravity = .5;
    int Count = 0;
    
    Rectangle Player = {ScreenWidth/2 - 25, ScreenHeight/2 - 25, 50, 50};
    int PlayerSpeed = 5;
    
    Rectangle Platform = {ScreenWidth/2 - 50, ScreenHeight/2 + 25, 100, 10};
    Rectangle LeftPlatform = {ScreenWidth/2 - 350, ScreenHeight/2 + 100, 200, 10};
    Rectangle RightPlatform = {ScreenWidth/2 + 150, ScreenHeight/2 + 100, 200, 10};
    
    SetTargetFPS(60);
    InitWindow(ScreenWidth, ScreenHeight, "Basic Platformer");
    while (!WindowShouldClose())
    {
        //Update
        
        //Jump
        if (IsKeyPressed(KEY_SPACE)) 
        {    
            Count = 15;
            Gravity -= Gravity;
        }
        if (Count > 0)
        {
            Player.y -= Count;
            Count--;
        }
        
        //Basic Movement
        if (IsKeyDown(KEY_D)) Player.x += PlayerSpeed;
        if (IsKeyDown(KEY_A)) Player.x -= PlayerSpeed;
        
        //Gravity
        if (CheckCollisionRecs(Player, Platform) == 1 || CheckCollisionRecs(Player, RightPlatform) == 1 || CheckCollisionRecs(Player, LeftPlatform) == 1)
        {
            Gravity -= Gravity; 
        }
        else //(CheckCollisionRecs(Player, Platform) == 1 || CheckCollisionRecs(Player, RightPlatform) == 1 || CheckCollisionRecs(Player, LeftPlatform) == 1)
        {
            Player.y += Gravity;
            Gravity += GravitySpeed;
        }
        
        
        //Draw
        BeginDrawing();
            ClearBackground(WHITE);
            DrawRectangleRec(Player, BLUE);
            DrawRectangleRec(Platform, BLACK);
            DrawRectangleRec(RightPlatform, BLACK);
            DrawRectangleRec(LeftPlatform, BLACK);
            DrawFPS(20, 20);
        EndDrawing();
    }
    return 0;
}