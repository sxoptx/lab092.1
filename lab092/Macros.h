//macros.h:

#pragma once

#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))   // більше з двох чисел
#define MIN(a, b) ((a) < (b) ? (a) : (b))   // менше з двох чисел
#define ABS(a)    ((a) < 0 ? -(a) : (a))    // модуль числа
#define SQR(a)    ((a) * (a))               // піднесення до квадрата

// виведення результату
#define PRINT_RESULT(w) cout << "w = " << (w) << endl;
