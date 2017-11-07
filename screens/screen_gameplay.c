/**********************************************************************************************
*
*   raylib - Standard Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Global Variables Definition (local to this module)
//----------------------------------------------------------------------------------

// Gameplay screen global variables
static int framesCounter;
static int finishScreen;

static Vector2 mousePosition;
    
static Vector3 cubePosition = { 0.0f, 0.25f, 0.0f };    
 // Camera Definitions
static Camera camera = {  (Vector3){ 0.0f, 10.0f, 10.0f },  (Vector3){ 0.0f, 0.0f, 0.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, 45.0f };

static float axisX = 0.0f;
static float axisY = 0.0f;
    
static float playerSpeed = 0.1f; 

static Vector2 ballPosition = 0;   
    
//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------


// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;  
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    
    mousePosition = GetMousePosition(); //updates mousePosition
    
    GetAxisX();
    GetAxisY(); 

    //PlayerMovement
    cubePosition.x += axisX * playerSpeed;
    cubePosition.z += axisY * playerSpeed * -1;
    
    //CameraUpdate
    camera.target = cubePosition;
    camera.position.x = cubePosition.x ;
    camera.position.z += axisY * playerSpeed * -1;
    
    // Press enter to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER))
    {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    
     ClearBackground(RAYWHITE);

        Begin3dMode(camera);
           DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, GREEN);

            DrawGrid(1000, 1.0f);

        End3dMode();
        
       DrawRectangle(mousePosition.x,mousePosition.y, 10, 10, BLUE);
       DrawText( FormatText("cameraposition.z: %f", camera.position.z),0,0,40,BLACK);

}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
void GetAxisY()
{
        if(IsKeyDown(KEY_W) )
    {
        if (axisY < 1.000f)axisY+= 0.05f;
    }  
    else if(IsKeyDown(KEY_S) )
    {
        if(axisY > -1.000f)axisY-= 0.05f;
    }
    else
    {
        if(axisY > 0.000f)axisY-= 0.05f;
        if(axisY < 0.000f)axisY+= 0.05f;
    }

}
void GetAxisX()
{
    if(IsKeyDown(KEY_D) )
    {
        if (axisX < 1.0f)axisX+= 0.05f;
    }  
    else if(IsKeyDown(KEY_A) )
    {
        if(axisX > -1.0f)axisX-= 0.05f;
    }
    else
    {
        if(axisX > 0.0f)axisX  -= 0.05f;
        if(axisX < 0.0f)axisX += 0.05f;
    }

}