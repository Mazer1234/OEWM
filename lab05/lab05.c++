#include <stdio.h>
#include <conio.h>
#include <dos.h>

volatile int run_program = 1;
//volatile int alpha;

void interrupt (*oldkeyboard)();

int glas(int alph){
    int code[12] = {18, 21, 22, 23, 24, 30};
    int a = 1;
    int i;

    for (i = 0; i < 12; i++){
        if (alph == code[i]){
            a = 0;
        }
    }
    return a;
}


void interrupt newkeyboard(){
    char scancode;
    char alpha;
    
    disable();
    scancode = inport(0x60);
    alpha = 0;
    if (scancode >= 16 && scancode <= 64) { // A-Z
        alpha = scancode;
        if(alpha == 41){
            gotoxy(10, wherey()-1);
        }
    } else if (scancode >= 2 && scancode <= 11) { // 1-9
        alpha = scancode;
    } else {
        oldkeyboard();
        return; 
    }


    if (!glas(alpha)){
        oldkeyboard();
        return;
    }else {
        // printf("%c", alpha);
        //outportb(0x20, 0x20);
        oldkeyboard();
    }
    enable();
    oldkeyboard();
}




int main(){
    int key = 0;
    int x1 = 1, y1 = 5, x2 = 65, y2 = 55;
    int alph = 0;
    char al;
    clrscr();
    textbackground(0);
    window(x1, y1, x2, y2);

    gotoxy(10, 10);
    printf("Enter alphas. ESC for exit\n");

    oldkeyboard = getvect(0x09);
    setvect(0x09, newkeyboard);

    
    while(1){
        al = getch();
        if (kbhit()){
            if (getch() == 27){
                break;
            }
            printf("%c", al);
        }
    }

    setvect(0x09, oldkeyboard);
    return 0;
}

