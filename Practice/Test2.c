//Chase Elliott 
//Started 9-9-2021

#include "raylib.h"

int main(void)
{
    const int ScreenWidth = 500;
    const int ScreenHeight = 500;
 
    InitWindow(ScreenWidth, ScreenHeight, "Journey of the Prarie King");
    
    Vector2 PlayerPosition = {ScreenWidth/2, ScreenHeight/2};
    
    Vector2 VehiclePosition = {ScreenWidth/2, 0};
    
    SetTargetFPS(60);
    
    while(!WindowShouldClose())
    {
        //Update
        if (IsKeyDown(KEY_RIGHT)) PlayerPosition.x += 2;
        if (IsKeyDown(KEY_LEFT)) PlayerPosition.x -= 2;
        if (IsKeyDown(KEY_UP)) PlayerPosition.y -= 2;
        if (IsKeyDown(KEY_DOWN)) PlayerPosition.y += 2;
        if (VehiclePosition.y < ScreenHeight) VehiclePosition.y += 5;
        else VehiclePosition.y -= 700;
        if (CheckCollisionRecs())
    
        //Draw
        BeginDrawing();
            
            ClearBackground(WHITE);
            
            DrawText("Test", 25, 25, 20, BLACK);
            
            DrawRectangle(PlayerPosition.x, PlayerPosition.y, 50, 50, BLACK);
            
            DrawRectangle(VehiclePosition.x, VehiclePosition.y, 25, 25, RED);
            
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}


//Things that didn't work
/*
if (Fire = 1)
            {
                
                Vector2 Bullet = {PlayerPosition.x + 5, PlayerPosition.y + 5};
                Fire = 2;
            }
            
            if (Fire == 2)
            {
                DrawCircle(Bullet.x, Bullet.y, 2, RED);
                Bullet.x += 5;
                if (Bullet.x > ScreenWidth || Bullet.x < ScreenWidth || Bullet.y > ScreenHeight || Bullet.y < ScreenHeight)
                {
                    Fire = 0;
                }
            }    
          */