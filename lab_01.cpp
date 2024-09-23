#include <iostream>
#include <limits>
#define MAXLEN 100
using namespace std;

void print_binar_long(unsigned long ul){
    for (int i = (sizeof(unsigned long) * 8 - 1); i >= 0; i-- ){
        unsigned long u1 = 1 << i;
        cout << ((ul & u1) ? '1' : '0');
        if (i == 31){
            cout << " ";
        }
    }
    cout << endl;
}

void print_binar_double(double d){
    union{
        double d;
        unsigned long long ul;
    } u;
    u.d = d;

    for(int i = (sizeof(double)*8 - 1); i >= 0; i--){
        long long u1 = (u.ul >> i) & 1;
        cout << u1;
        if(i == 63) cout << " ";
        if(i == 52) cout << ",";
    }
    cout << endl;
}

void move_bits_int(unsigned long ul){
    unsigned long ul1 = ul;
    ul1 = ul1 << 1;
    cout << "---------------------" << endl;
    cout << "Move bits 1 to the left in unsigned long: ";
    for (int i = (sizeof(unsigned long) * 8 - 1) ; i >= 0; i--){
        cout << (ul1 & (1 << i) ? '1' : '0');
        if (i == 31) cout << " ";
    }
    cout << endl;
    cout << "Binary sistem : " << ul1 << endl;
}

void move_bits_double(double d){
    union{
        double d;
        long long ll;
    } u;
    u.d = d;
    u.ll = u.ll << 1;
    cout << "---------------------" << endl;
    cout << "Move bits 1 to the left in double: ";
    for (int i = (sizeof(long long) * 8 - 1); i >= 0; i-- ){
        long long test = u.ll >> i & 1; 
        cout << test;
        if (i == 63) cout << " ";
        if (i == 52) cout << ",";
    }
    cout << endl;
    cout << "Binary system: " << u.d << endl;
    cout << "---------------------" << endl;

}

int main(){
    unsigned long ul;
    cout << "-----------LONG-----------------" << endl;
    cout << "Enter the unsigned long digit: ";

    while(!(cin >> ul)){
        cout << "Invalid number? try again";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    cout << "Binary representstion of unsigned long is ";
    print_binar_long(ul);
    cout << "Decimal represintation of unsigned long is ";
    cout << ul << endl;
    move_bits_int(ul);
    cout << "-----------DOUBLE-----------------" << endl;
    double d;
    cout << "Enter the double digit: ";
     while(!(cin >> d)){
        cout << "Invalid number? try again";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    };

    cout << "Binary representation of double is ";
    print_binar_double(d);
    cout << "Decimal representation of double is ";
    cout << d << endl;

    move_bits_double(d);
    return 0;
}