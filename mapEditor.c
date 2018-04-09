/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define CAMERA_ZOOM_LIMIT 1.0F
#define CAMERA_ZOOM_MIN 10.0F

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    //Map
    int mapSize = 200;
    
    Camera2D camera;
    
    camera.target = (Vector2){0,0};
    camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if(IsKeyDown(KEY_A))camera.target.x-= camera.zoom;
        if(IsKeyDown(KEY_D))camera.target.x+= camera.zoom;
        if(IsKeyDown(KEY_W))camera.target.y-= camera.zoom;
        if(IsKeyDown(KEY_S))camera.target.y+= camera.zoom;
        
        
        
        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        
        if (camera.zoom > CAMERA_ZOOM_MIN) camera.zoom = CAMERA_ZOOM_MIN;
        else if (camera.zoom < -CAMERA_ZOOM_LIMIT) camera.zoom = -CAMERA_ZOOM_LIMIT;
        
        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R)) 
        {
            camera.zoom = 1.0f;
        }
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            Begin2dMode(camera);

               for(int i = 0; i <= mapSize/10; i++)
               {
                   DrawLine(i * 10, 0, i*10, mapSize, DARKGRAY);
                   DrawLine(0, i * 10, mapSize, i*10, DARKGRAY);
               }
                
            End2dMode();
            
            DrawText(FormatText("Zoom %i", camera.zoom), 0, 0, 20, RED);
            
            ClearBackground(RAYWHITE);

            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}