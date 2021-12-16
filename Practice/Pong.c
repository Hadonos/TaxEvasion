//Chase Elliott 
//9-11-21 
//Pong
#include "raylib.h"

int main(void)
{
    int Time = 0;
    const int ScreenWidth = 1000;
    const int ScreenHeight = 500;
    
    InitWindow(ScreenWidth, ScreenHeight, "Pong");
    
    Rectangle Player1 = {50, ScreenHeight/2 -50, 25, 100};
    Rectangle Player2 = {ScreenWidth - 50 - 25,ScreenHeight/2 - 50, 25, 100};
    int PlayerSpeed = 6;
    
    Rectangle Ball = {ScreenWidth/2 - 10, ScreenHeight/2 - 10, 20, 20};
    int BallSpeedy = 5;
    int BallSpeedx = 5;
    
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        
        
        //Restart
        if (IsKeyPressed(KEY_R)) 
        {
            BallSpeedx = 5;
            BallSpeedy = 5;
            Ball.x = ScreenWidth/2 -10;
            Ball.y = ScreenHeight/2 -10;
        }
        
        //Update
        Time = Time + 1;
        //Player movement
        if (IsKeyDown(KEY_W)) Player1.y -= PlayerSpeed;
        if (IsKeyDown(KEY_S)) Player1.y += PlayerSpeed;
        if (IsKeyDown(KEY_UP)) Player2.y -= PlayerSpeed;
        if (IsKeyDown(KEY_DOWN)) Player2.y += PlayerSpeed;
        
        //Player Boundry collision
        if (Player1.y <= -PlayerSpeed) Player1.y += PlayerSpeed;
        if (Player1.y >= ScreenHeight - 100 + PlayerSpeed) Player1.y -= PlayerSpeed;
        if (Player2.y <= -PlayerSpeed) Player2.y += PlayerSpeed;
        if (Player2.y >= ScreenHeight - 100 + PlayerSpeed) Player2.y -= PlayerSpeed;
        
        
        //Ball movement and boundry collision
        Ball.x += BallSpeedx;
        Ball.y += BallSpeedy;
        if (Ball.y <= -5 || Ball.y >= ScreenHeight - 20 + 5) BallSpeedy *= -1;
        if (CheckCollisionRecs(Player1, Ball) || CheckCollisionRecs(Player2, Ball)) BallSpeedx *= -1;

        //Other updating information
        if (Time % 180 == 0) 
        {    
            if (BallSpeedx > 0) BallSpeedx += 1;
            else BallSpeedx -= 1;
            if (BallSpeedy > 0) BallSpeedy += 1;
            else BallSpeedy -= 1;
        }
        if (Ball.x <= BallSpeedx * -1 || Ball.x >= ScreenWidth + BallSpeedx)
        {
            DrawText("You Lose", (ScreenWidth/2) - 100, 10, 50 , WHITE);
        }
        
        //Draw
        BeginDrawing();
            ClearBackground(BLACK);
            
            DrawFPS(25, 25);
            
            DrawRectangleRec(Player1, WHITE);
            DrawRectangleRec(Player2, WHITE);
            DrawRectangleRec(Ball, WHITE);
            
        EndDrawing();
    }
    
    CloseWindow();
    
    return 0;
}