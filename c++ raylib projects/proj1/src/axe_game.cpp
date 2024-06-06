/*
    IDEA TO WORK ON

    - create a block on right side and create collision counter with the ball
    - add a counter system 
    - add animations
    - increase fps over time as points get higer 
    - increase difficulty
    - add stages [stage 1 = 1 axe ; stage 2 = 2 axes ; stage 3 = 3 axes]
*/



#include<iostream>
#include "raylib.h"

int main(void) {
    
    //Window settings:
    int win_x {700},win_y{400};
    InitWindow(win_x,win_y,"Axe-Game");

    //circle dimensions:
    int circle_r{15};
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
    int direction = 1;


    //goal dimensions: 
    int goal_w{20};
    int goal_h{win_y-40};
    int goal_x{win_x-goal_w};
    int goal_y{20};
    
    //goalpost dimension:
   // int gp_x{}
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
            DrawRectangle(goal_x,goal_y,goal_w,goal_h,BLACK);

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
            else if(IsKeyDown(KEY_S) && circle_y<350) {
                circle_y += 5;
            }
            else if(IsKeyDown(KEY_W)  && circle_y>50) {
                circle_y -= 5;
            }
        }
        

        //game logic ends here:
        EndDrawing();
    }
}