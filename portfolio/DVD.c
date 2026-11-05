// My First C Game; using raylib, a DVD screensaver clicker

#include <raylib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    const int screenWidth = 960;
    const int screenHeight = 540;
    const float playerRadius = 20.0f;
    int DVDscore = 0;
    Vector2 player = {
        .x = (float)screenWidth / 2.0f,
        .y = (float)screenHeight / 2.0f,
    };
    Vector2 playerSpeed = {
        .x = (float) 100.0f,
        .y = (float) 100.0f,
    };

    InitWindow(screenWidth, screenHeight, "raylib C starter;");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {  
        const float dt = GetFrameTime();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 RelMousePos = GetMousePosition();
            RelMousePos.x -= player.x;
            RelMousePos.y -= player.y;
            if (sqrt((RelMousePos.x * RelMousePos.x) + (RelMousePos.y * RelMousePos.y)) <= playerRadius + 5) {
                DVDscore += 10;
                playerSpeed.x += .1;
                playerSpeed.y += .1;
            }
        }
        player.x += playerSpeed.x * dt;
        player.y += playerSpeed.y * dt;
        if (player.x - playerRadius < 0) playerSpeed.x *= -1; 
        if (player.x + playerRadius> screenWidth) playerSpeed.x *= -1;
        if (player.y - playerRadius < 0) playerSpeed.y *= -1;
        if (player.y + playerRadius > screenHeight) playerSpeed.y *= -1;
        
        BeginDrawing();
        ClearBackground((Color){ 22, 27, 38, 255 });
        DrawText("DVD Clicker", 32, 28, 30, RAYWHITE);
        DrawText("An amazing DVD simulator.", 34, 72, 18, LIGHTGRAY);
        DrawText(TextFormat("DVDscore: %08i", DVDscore), 32, 120, 20, GREEN);
        if (IsKeyDown(KEY_SPACE)) {
        DrawText(TextFormat("Debug: %f", dt), 32, 160, 20, PINK);
        }
        DrawCircleV(player, playerRadius,  (Color) { 92, 206, 190, 255 });
        EndDrawing();
    } 

    CloseWindow();
    return 0;
}
