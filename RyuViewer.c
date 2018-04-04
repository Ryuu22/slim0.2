/*******************************************************************************************
*
*   raylib [models] example - Load and draw a 3d model (OBJ)
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - obj model loading");

    // Define the camera to look into our 3d world
    Camera camera = {{ 3.0f, 3.0f, 3.0f }, { 0.0f, 1.5f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f };

    Model slime = LoadModel("slime.obj");                   // Load OBJ model
    Texture2D texture = LoadTexture("diffuse.png");   // Load model texture
    slime.material.maps[MAP_DIFFUSE].texture = texture;                     // Set map diffuse texture
    Vector3 position = { 0.0f, 0.0f, 0.0f };                                // Set model position
    
    bool wired = false;
    int freeCamera = 0;

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyPressed(KEY_Z))wired = !wired;
        if(IsKeyPressed(KEY_C))
        {
            freeCamera++;
            if(freeCamera >= 2)
            {
                freeCamera = 0;
            }
            SetCameraMode(camera,freeCamera);
        }
        UpdateCamera(&camera);
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

            Begin3dMode(camera);

                if(!wired)DrawModel(slime, position, 1.0f, WHITE);   // Draw 3d model with texture
                
                else DrawModelWires(slime, position, 1.0f, WHITE);
                
                DrawGrid(10, 1.0f);         // Draw a grid

                DrawGizmo(position);        // Draw gizmo

            End3dMode();
            
            DrawText("Displaying Slime", screenWidth - 200, screenHeight - 20, 10, GRAY);
            DrawText(FormatText("Camera Mode %i",freeCamera), screenWidth - 200, screenHeight - 10, 10, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);     // Unload texture
    UnloadModel(slime);         // Unload model

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}