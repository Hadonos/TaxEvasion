#include "raylib.h"
#include <stdbool.h>


int main()
{

    int ScreenWidth = 1280, ScreenHeight = 720;
       
  
        
    Rectangle Player = {ScreenWidth/2, ScreenHeight/2, 50, 50};
    int PlayerXVel = 0, PlayerYVel = 0; 
    float Gravity = 2;
    bool landed = false;

    Rectangle Ground = {ScreenWidth / 4, ScreenHeight-75, ScreenWidth/2, 50}; 
    
    Rectangle Ground2 = {0, ScreenHeight-275, ScreenWidth/4, 50}; 
    
    Rectangle Ground3 = {3*ScreenWidth / 4, ScreenHeight-275, ScreenWidth/4, 50}; 
    
    Rectangle Goal = {ScreenWidth/2 - 25, ScreenHeight/2 - 50, 50, 50}; 
    bool win = false;
    
    Camera2D camera = { 0 };
    camera.target = (Vector2){ Player.x + 20.0f, Player.y + 20.0f };
    camera.offset = (Vector2){ ScreenWidth/2.0f, ScreenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    InitWindow(ScreenWidth, ScreenHeight, "benis");

    SetTargetFPS(60); 
    
  
    

    while (!WindowShouldClose())
    {
          
        if (Player.y + 50 > ScreenHeight)
        {
            Player.y = -50;
        }
        
        if (Player.x < -50)
        {
          Player.x = ScreenWidth;
        }
        
        if (Player.x > ScreenWidth)
        {
          Player.x = -50;
        }
        
    
        
        
        
        if (PlayerXVel < 0)
        {
            PlayerXVel += 2;
        }
        else if(PlayerXVel > 0)
        {
           PlayerXVel -= 2; 
        }
        
        PlayerYVel += Gravity;
        
        Player.x += PlayerXVel;
        Player.y += PlayerYVel;
        
    
       
        if (CheckCollisionRecs(Player, Ground))
        {
            Player.y = Ground.y -50;
            PlayerYVel = 0;
            landed = true;
        }else if (CheckCollisionRecs(Player, Ground2))
        {
            Player.y = Ground2.y -50;
            PlayerYVel = 0;
            landed = true;
        }else if (CheckCollisionRecs(Player, Ground3))
        {
            //Player.y = Ground3.y -50;
            PlayerYVel = 0;
            landed = true;
        }else 
        {
            landed = false;
        }
        
        if (CheckCollisionRecs(Player, Goal))
        {
            win = true;
        }
        
       
         if (IsKeyDown(KEY_A)){
             
           if (PlayerXVel > -25)
           {
              PlayerXVel -= 3;
           }
        }
        if (IsKeyDown(KEY_D)){
            if (PlayerXVel < 25)
            {
              PlayerXVel += 3;
            }
        }
        if (landed == true)
        {

            if (IsKeyPressed(KEY_SPACE))
            {
                PlayerYVel = -30;
                
       }
        }
        
        
        camera.target = (Vector2){Player.x +25,Player.y + 25};
         BeginDrawing();
            
            
         ClearBackground(RAYWHITE);
         
           BeginMode2D(camera);
           
           
         DrawRectangleRec(Player, ORANGE);
         
         
         
         DrawRectangleRec(Ground, BROWN);
         DrawRectangleRec(Ground2, BROWN);
         DrawRectangleRec(Ground3, BROWN);
         
         if (!win)
         {
             DrawRectangleRec(Goal, GREEN);
         }
         
         EndMode2D();
         
         DrawFPS(0, 0);
     
           
           
         if (win)
         {
               DrawText("WIN!", ScreenWidth/2 - 100, 0, 40, GREEN); 
             
         }
           
         EndDrawing();


    }
    
    CloseWindow();

    return 0;
}