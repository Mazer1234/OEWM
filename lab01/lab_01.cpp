#include <iostream>
#include <limits>
using namespace std;

/**
 * @brief Вывод числа типа unsigned long в двоичном представлении.
 * @param ul - Число типа unsigned long.
 */
void print_binar_long(unsigned long ul)
{
    for (int i = (sizeof(unsigned long) * 8 - 1); i >= 0; i--)
    {
        unsigned long u1 = 1 << i;
        cout << ((ul & u1) ? '1' : '0');
    }
    cout << endl;
}

/**
 * @brief Вывод числа типа long long в двоичном представлении.
 * @param ul - число типа long long.
 */
void print_binar_long_long(long long ul)
{
    for (int i = (sizeof(long long) * 8 - 1); i >= 0; i--)
    {
        long long u1 = (ul >> i) & 1;
        cout << u1;
        if (i == 63 || i == 52)
            cout << " ";
    }
    cout << endl;
}

/**
 * @brief Вывод числа double в двоичном представлении.
 * @param d - число типа double.
 */
void print_binar_double(double d)
{
    union
    {
        double d;
        long long ul;
    } u;
    u.d = d;

    print_binar_long_long(u.ul);
}

/**
 * @brief Подсчёт битов равных 1 в числе типа unsigned long.
 * @param ul - число типа unsigned long.
 */
int find_1(unsigned long ul)
{
    int num_1 = 0;
    for (int i = 0; i < (sizeof(unsigned long) * 8); i++)
    {
        if (ul & 1 << i)
        {
            num_1++;
        }
    }
    return num_1;
}

/**
 * @brief Подсчёт битов равных 1 в числе типа long long.
 * @param ul - число типа long long.
 */
int find_1_l(long long ul)
{
    int num_1 = 0;
    for (int i = sizeof(long long) * 8 - 1; i >= 0; i--)
    {
        long long test = ul >> i & 1;
        if (test)
        {
            num_1++;
        }
    }
    return num_1;
}

/**
 * @brief Смещение в числе типа unsigned long всех битов 1 влево на 1 позицию, а 0 вправо на 1 позицию.
 * @param ul - число типа unsigned long.
 */
void move_bits_int(unsigned long ul)
{
    unsigned long ul1 = ul, mask = 0;
    int num_1;
    cout << "---------------------" << endl;
    num_1 = find_1(ul);
    for (int i = 0; i < num_1; i++)
    {
        mask |= 1 << (sizeof(unsigned long) * 8 - 1 - i);
    }
    cout << "Move bits 1 to the left in unsigned long: ";
    print_binar_long(mask);
    cout << endl;
    cout << "Binary sistem : " << mask << endl;
}

/**
 * @brief Смещение в числе типа double всех битов 1 влево на 1 позицию, а 0 вправо на 1 позицию.
 * @param d - число типа double.
 */
void move_bits_double(double d)
{
    int num_1;
    long long mask = 0;
    union
    {
        double d;
        long long ll;
    } u;
    cout << endl;
    u.d = d;
    cout << "---------------------" << endl;
    num_1 = find_1_l(u.ll);
    cout << "Move bits 1 to the left in double: " << endl;
    for (int i = 0; i < num_1; i++)
    {
        mask |= 1LL << (sizeof(long long) * 8 - 1 - i);
    }
    print_binar_long_long(mask);
    cout << endl;
    cout << "Binary system: " << double(mask) << endl;
    cout << "---------------------" << endl;
}

int main()
{
    unsigned long ul;
    cout << "-----------LONG-----------------" << endl;
    cout << "Enter the unsigned long digit: ";
    while (!(cin >> ul))
    {
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
    while (!(cin >> d))
    {
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