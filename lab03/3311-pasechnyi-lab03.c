#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define PI M_PI

float function(float x){
    return pow(sin(x/2), 3) - sqrt(x);
}

void draw_ax_lb(float x_l_border, float x_r_border, float y_b_border, float y_top_border, float x_step, float y_step){
    char label[50];
    float x, y;
    float screen_x, screen_y;
    float count = 0;

    setcolor(WHITE);

    for (x = x_l_border; x <= x_r_border; x+= x_step){
        screen_x = 50 + (x - x_l_border)*550 / (x_r_border - x_l_border);
        line(screen_x, 231, screen_x, 221);
        sprintf(label, "%.1f", count);
        outtextxy(screen_x - 10, 210, label);
        count = count+2;
    }

    for (y = y_b_border; y <= y_top_border; y+= y_step){
        screen_y = 400 - (y - y_b_border)*350 / (y_top_border - y_b_border);
        line(45, screen_y, 55, screen_y);
        sprintf(label, "%.1f pi", y-5);
        if(y == 5){
                continue;
        }else{
            outtextxy(20, screen_y - 15, label);
        }
    }
}

int main(){
    int graph_driver = DETECT, graph_mode, graph_error_code;
    float x_r_border = 12*PI, x_l_border = PI/2;
    float y_b_border = 0, y_top_border = 10;
    float step = 0.01;
    float x, y, screen_x, screen_y;
    float y_max_val = -1000000;
    float x_max, y_max;
    char str_max[50];

    initgraph(&graph_driver, &graph_mode, "\\tc\\bgi");
    setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
    setcolor(WHITE);
    line(50, 226, 600, 226);//x line
    line(50, 450, 50, 50);//y line
    line(600, 226, 590, 221);//x arrow
    line(600, 226, 590, 231);
    outtextxy(600, 240, "x");
    line(50, 50, 45, 60);//y arrow
    line(50, 50, 55, 60);
    outtextxy(60, 50, "y");

    draw_ax_lb(0, x_r_border, y_b_border, y_top_border, PI, 1);

    for(x = x_l_border; x < x_r_border; x+=step){
        y = function(x);
        screen_x = 50 + (x) * 550/(x_r_border);
        screen_y = 231 - (y - y_b_border) * 350/(y_top_border - y_b_border);
        putpixel(screen_x,screen_y, WHITE);
        if (y > y_max_val){
            y_max_val = y;
            y_max = screen_y;
            x_max = screen_x;

        }
    }

    setcolor(RED);
    circle(x_max, y_max, 5);
    setfillstyle(1, RED);
    floodfill(x_max, y_max, RED);
    outtextxy(x_max-40, y_max-20, "max_value");
    setcolor(WHITE);
    sprintf(str_max, "Max Value of function: %.2f", y_max_val);
    outtextxy(30, 450, str_max);
    outtextxy(320, 450, "f(x) = Sin^3(x) - Sqrt(x)");
    getchar();
    closegraph();
    return 0;
}