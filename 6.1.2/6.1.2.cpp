#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int* P, const int size, const int Low, const int High, int i)
{
    P[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(P, size, Low, High, i + 1);
}

void Print(int* P, const int size, int i)
{
    cout << setw(4) << P[i];
    if (i < size - 1)
        Print(P, size, i + 1);
    else
        cout << endl;
}

int Sum(int* P, const int size, int i, int S)
{
    if ((P[i] > 0) || (i % 2 == 0))
        S += P[i];
    if (i < size - 1)
        return Sum(P, size, i + 1, S);
    else
        return S;
}

void Replacing(int* P, const int size, int i)
{
    if ((P[i] > 0) || (i % 2 == 0))
        cout << 0 << "  ";
    else
        cout << P[i] << "  ";
    if (i < size - 1)
        return Replacing(P, size, i + 1);
}

int Count(int* P, const int size, int i, int j)
{
    if ((P[i] > 0) || (i % 2 == 0))
        j++;
    if (i < size - 1)
        return Count(P, size, i + 1, j);
    else
        return j;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    int P[n];

    int Low = -10;
    int High = 14;

    Create(P, n, Low, High, 0);
    cout << "Original masive" << endl;
    Print(P, n, 0);
    cout << endl;

    cout << "Calculating sum" << endl;
    cout << "S = " << Sum(P, n, 0, 0) << endl;
    cout << endl;

    cout << "Calculating count" << endl;
    cout << "j = " << Count(P, n, 0, 0) << endl;
    cout << endl;

    cout << "Replaced elements" << endl;
    Replacing(P, n, 0);
    cout << endl;

    system("pause");
    return 0;
}