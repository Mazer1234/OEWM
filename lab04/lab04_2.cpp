#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(){
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

    while(key != 27){
        key = getch();
        if (key == 68){
            if (wherex() < (x2 - x1)){
                    cprintf(" #");
                    gotoxy(wherex() - 1, wherey());
            }
        }
        if (key == 67){
            if (wherex() > 1){
                cprintf(" ");
                gotoxy(wherex() - 2, wherey());
                cprintf("#");
                gotoxy(wherex()-1, wherey());
            }
        }
    }
    return 0;
}