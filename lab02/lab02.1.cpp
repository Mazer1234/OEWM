#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

const char* COLORS[] = {"BLACK","BLUE","GREEN","CYAN","RED","MAGENTA",
    "BROWN", "LIGHTGRAY", "DARKGRAY", "LIGHTBLUE", "LIGHTGREEN"
    ,"LIGHTCYAN", "LIGHTRED", "LIGHTMAGENTA", "YELLOW", "WHITE"
};

void set_bg_color(int color, int txt_color){
    textattr((color << 4) | txt_color);
}
void clearScr(int color){
    set_bg_color(color, 0);
    clrscr();
}

void set_color(int x1, int x2, int y1, int y2, float T, int S){
    char bfr1[40];
    char bfr2[40];
    int line = 0;
    int back_ground, text, attr;
    clrscr();
    clearScr(4);
    window(25, 12, 60, 23);
    for (back_ground = 0; back_ground < 16; back_ground++){
        clearScr(back_ground);
        for(text = 0; text < 16; text++){
            set_bg_color(back_ground, text);
            sprintf(bfr1, "BG_COLOR: %s TXT_COLOR: %s", COLORS[back_ground], COLORS[text]);
            cprintf("%s\r\n", bfr1);
            delay((int)(T*1000));
            line += 2;
            if (line >= S){
                clearScr(back_ground);
                line = 0;
            }

        }
    }
    clrscr();
    clearScr(4);

}
int main(){

    int x1,y1,x2,y2, S;
    float T;
    x1 = 25;
    y1 = 12;
    x2 = 60;
    y2 = 23;
    T = 0.6;
    S = 1;
    set_color(x1, y1, x2, y2, T, S);

    return 0;
}