

/*----------------------------------------------------------------------------------------------------------*/

 /*
        -  CloseWindow(); this is similar to return 0 , use this evrrytime as this does the real job.
        - velocity logic: if u move an axe 10 pixles per frame at 60 fps then its = 
                                                        10(p/f) * 60fps = 600 pixles per second;

        - Texture2D scarfy = LoadTexture("textures/scarfy.png"); -->this is to load the textures.
        now we can use . operator to access the image. 
        => height , width , id , format , mipmaps from sprite sheet;

        -  Rectangle scarfyrec; --> this creates a reactangle box of the above by splitting the above images. 
            scarfyrec.width = scarfy.width/6;  =>
            this has height , width , x , y; the whole of this is used  to take chunks from the sprite sheet. 
            , here x and y will be 0 as it starts from the top of the sprite sheet.
        

        - Vector2 scarfypos; --> this gives the x and the y point of the top of the box , which can be used to 
                                place the box in different places.  .x  ||  .y

        -          

        
*/

/*
    - learn how delt time works:
*/



/*----------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include "raylib.h"

int main(void) {
    
    //windows dimension:
    int windowWidth = 700;
    int windowHeight = 500;

    InitWindow(windowWidth,windowHeight,"Project - 2");


    // jump velocity (pixels/second)
    const int jumpVal{-600};
    int velocity{jumpVal};

    // acceleration due to gravity (pixels/s)/s
    const int gravity{1000};

    //airtime check:
    bool isAir{};

    //creating a nebula:
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebRec{0, 0, nebula.width/8, nebula.height/8};
    Vector2 nebPos{windowWidth, windowHeight - nebRec.height};

    //nebula x velocity:
    int nebval{-600};

    //creating of scarfy:
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
   
    Rectangle scarfyrec;
    scarfyrec.width = scarfy.width/6;
    scarfyrec.height = scarfy.height;
    scarfyrec.x = 0;
    scarfyrec.y = 0;

    Vector2 scarfypos;
    scarfypos.x = windowWidth/2 - scarfyrec.width/2-100;
    scarfypos.y = windowHeight - scarfyrec.height;

    //animations frame:
    int frame{};
    const float updateTime {1.0/12.0};
    float runningTime {};

    //setting FPS:
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        //game logic begins:
        const float dT{GetFrameTime()};


         // perform ground check
        if (scarfypos.y >= windowHeight - scarfyrec.height)
        {
            // rectangle is on the ground
            velocity = 0;
            isAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity * dT;
            isAir = true;

        }
        //jump checK:
        if(IsKeyPressed(KEY_SPACE) && !isAir) {
            velocity += jumpVal;
        }

        //updating nebula position:
        nebPos.x = nebval * dT;

        //update the position:
       scarfypos.y +=velocity * dT;

        // update running time:
       runningTime += dT;
        if(updateTime>=runningTime) {
            runningTime = 0.0;
            //runs through the sprite sheet:
            scarfyrec.x = frame*scarfyrec.width;
            frame++;

            if(frame>5) frame = 0;
        }

        //drawing nebula:
        DrawTextureRec(nebula,nebRec,nebPos,WHITE);

        //drawing scarfy:
        DrawTextureRec(scarfy,scarfyrec,scarfypos,WHITE) ;



        EndDrawing();

    }
     UnloadTexture(nebula);
    UnloadTexture(scarfy);
    CloseWindow();
}   

