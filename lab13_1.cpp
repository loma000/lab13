#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int C, double B[])
{

    double sum1 = 0;
    double sum2 = 1;
    double max, min;

    for (int i = 0; i < C; i++)
    {
        sum1 += A[i];
    }
    B[0] = sum1 / C;
    sum1 = 0;
    for (int j = 0; j < C; j++)
    {
        sum1 += pow(A[j] , 2);
    }

    B[1] = sqrt(( sum1  /  C  ) -pow(B[0],2));
    sum1 = 0;
    for (int j = 0; j < C; j++)
    {
        sum2 *= A[j];
    }
    B[2] = pow(sum2,1.0/C);

    for (int j = 0; j < C; j++)
    {
        sum1 += 1 / A[j];
    }

    B[3] = C / sum1;
    sum1 = 0;
    for (int j = 0; j < C; j++)
    {
        if (j < 1)
        {
            max = A[j];
            min = A[j];
        }

        else
        {
            if (max < A[j])
            {
                max = A[j];
            }

            if (min > A[j])
            {
                min = A[j];
            }
        }
    }

    B[4] = max;
    B[5] = min;
}