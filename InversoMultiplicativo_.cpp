#include <iostream>
using namespace std;

// Funcion euclides extendido
int euclidesExt(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = euclidesExt(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}


// Funcio para hayar el inverso multiplicativo 
//o notificar si no existe 
void inversoMult(int a, int n)
{
    int x, y;
    int g = euclidesExt(a, n, &x, &y);
    if (g != 1)
        cout << "No existe inverso multiplicativo" << endl;
    else
    {
        int resto = (x % n + n) % n;
        cout << "El inverso multiplicativo es: " << resto << endl;
    }
}

int main()
{
    //ingresamos a y N para hayar el inverso
    int a, N;
    cout << "ingresa a: "; cin >> a;
    cout << "ingresa N: "; cin >> N;

    inversoMult(a, N);




    return 0;
}
