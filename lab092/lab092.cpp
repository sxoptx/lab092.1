#include <iostream>
#include "macros.h"

#define Z 7

using namespace std;

int main()
{
    double x, y;    // змінні, які вводить користувач
    double w;       // результат

    cout << "Enter x: "; cin >> x;
    cout << "Enter y: "; cin >> y;

#if Z > 3
    // гілка 1: z > 3
    cout << "Branch: z > 3" << endl;
    w = MAX(SQR(x - Z), x - y);
#else
    // гілка 2: z <= 3
    cout << "Branch: z <= 3" << endl;
    w = MAX(x * y, y * Z) + MAX(Z * x, y * Z);
#endif

    PRINT_RESULT(w);

    cin.get();
    cin.get();
    return 0;
}