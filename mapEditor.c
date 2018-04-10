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

#define CAMERA_ZOOM_LIMIT 0.0F
#define CAMERA_ZOOM_MIN 10.0F

typedef enum LayerMode { COLLIDERS, GAMEOBJECTS, DETAILS, UI } GameScreen;

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    
    //LayerMode editingLayer = COLLIDERS;

    InitWindow(screenWidth, screenHeight, "Ryuu Map Editor");
    
    //Map
    int mapSize = 500;
    
    //UI variables
    
    int toggleButtonSize = 20;
    
    Vector2 mousePosition;
    
    //Layer 0 Colliders
    
    Rectangle buttonLayerZero = {screenWidth -toggleButtonSize * 4,0,toggleButtonSize,toggleButtonSize};
    
    bool LayerZeroToggle = true;
    
    Rectangle colliders[9999];
    int ColliderCounter = 0;
    
    bool DrawingNewCollider;
    Rectangle flashRec;
    
    //Layer 1
    
        //TODO GameObjects Variables.
    
    //Layer 2
    
        //TODO Detail Variables
    
    //Layer 3

        //TODO UI

    
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
        
        mousePosition = GetMousePosition();
        
        if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON ))
        {
            // UI buttons
            if(CheckCollisionPointRec(mousePosition, buttonLayerZero)) LayerZeroToggle = !LayerZeroToggle;
        }
        if(IsMouseButtonPressed)
        
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

                
                //Layer 0 Collider
                
                if(LayerZeroToggle)
                {
                    for(int i = 0; i >= ColliderCounter;i++)
                    {
                        DrawRectangleRec(Colliders[i],RED);
                    }
                }
                
                //Layer 3 UI
                
            End2dMode();
            
            DrawText(FormatText("Zoom %i", camera.zoom), 0, 0, 20, RED);
            DrawText(FormatText("Collider %i", LayerZeroToggle), 0, 30, 20, RED);
            
            if(LayerZeroToggle)DrawRectangleRec(buttonLayerZero,MAROON); //ON
            else DrawRectangleRec(buttonLayerZero,BLACK); //OFF
            
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