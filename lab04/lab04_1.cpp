#include <stdio.h>
#include <conio.h>
#include <dos.h>

int my_getch(){
    union REGS regs;
    regs.h.ah = 0x00;
    int86(0x16, &regs, &regs);
    return regs.x.ax;
}

int main() {
    int x1 = 25, y1 = 12, x2 = 55, y2 = 23;
    int screen_x, screen_y, key = 0;
    clrscr();
    textbackground(0);
    window(x1, y1, x2, y2);
    screen_x = (x2 - x1)/2;
    screen_y = (y2 - y1)/2;
    gotoxy(screen_x, screen_y);
    cprintf("#");
    gotoxy(screen_x, screen_y);

    while (key != 0x011B){
        key = my_getch();
        if (key == 0x4400){
            if (wherex() < (x2 - x1)){
                cprintf(" #");
                gotoxy(wherex() - 1, wherey());
            }
        }
        if (key == 0x4300){
            if (wherex() > 1){
                cprintf(" ");
                gotoxy(wherex() - 2, wherey());
                cprintf("#");
                gotoxy(wherex() - 1, wherey());
            }
        }
    }
    return 0;
}