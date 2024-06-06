// #include "raylib.h"
// #include "raymath.h"

// #include <iostream>

// int main(void)
// {
//     InitWindow(800, 450, "raylib [core] example - basic window");

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//             ClearBackground(RAYWHITE);
//             DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
//         EndDrawing();
//     }

//     CloseWindow();

//     return 0;
// }


/*----------------------------------------------------------------------------------------------------------*/






 /*
        InitWindow(width , height , " txt ") ;

        in raylib the canvas area is called using BeginDrawing()  and EndDrawing();

        to clear the canvas we use - ClearBackground(WHITE);

        NOTE: if u dont use white colour, the background frame buffer is black and it causes flickering.(empty 
        frame buffer is black )

        WindowShouldClose() --> this is false until u hit the cross button . 
    
*/



/*----------------------------------------------------------------------------------------------------------*/
#include<iostream>
#include 'raylib.h'

int main(void) {
    
    //Window settings:
    int win_x {700},win_y{400};
    InitWindow(win_x,win_y,"first program");

    //circle dimensions:

    //Circle 1
    int circle_r{50};
    int circle_x{circle_r};
    int circle_y{200};
    

     //circle edges :
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int u_circle_y{circle_y - circle_r};
    int b_circle_y{circle_y + circle_r};

    //axe dimensions:
    int axe_x {400};
    int axe_y {0};
    int axe_l{50};

    //axe edges:
    int l_axe_x{axe_x};
    int r_axe_x{axe_l + axe_x};
    int u_axe_y{axe_y};
    int b_axe_y{axe_l + axe_y};
   
    //directions of axe frame:
    int direction = 10;

    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    //FPS settings:
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //game logic begins here:

        if(collision_with_axe) {
            DrawText("GAME OVER ! PRESS ENTER TO CONTINUE:",0,200,20,RED);
            if(IsKeyPressed(KEY_ENTER)) {
                circle_x = circle_r;
                circle_y = 200;
                collision_with_axe = false;
            }
            
        }
        else{
            
           //updating the dimensions of the objects:
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y + circle_r;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_l;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_l;

            //Checking for collisio
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);


            //declaring shapes:
            DrawCircle(circle_x,circle_y,circle_r,DARKGREEN);
            DrawRectangle(axe_x,axe_y,axe_l,axe_l,BLACK);

            //moving axe:
            axe_y +=direction;
            if(axe_y>win_y || axe_y<0) direction = -direction;

            //controls of ball:
            if(IsKeyDown(KEY_D) && circle_x<win_x-circle_r) {
                circle_x += 10;
            }
            else  if(IsKeyDown(KEY_A) && circle_x>circle_r) {
                circle_x -= 10;
            }
            // else if(IsKeyDown(KEY_S) && circle_y<350) {
            //     circle_y += 5;
            // }
            // else if(IsKeyDown(KEY_W)  && circle_y>50) {
            //     circle_y -= 5;
            // }
        }
        

        //game logic ends here:
        EndDrawing();
    }
    

}

