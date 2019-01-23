#include <iostream>
using namespace std;

int *multiply(int M[], int N[], int m, int n)
{
   int *product = new int[m+n-1];

   for (int i = 0; i<m+n-1; i++)
     product[i] = 0;


   for (int i=0; i<m; i++)
   {
     // Multiply the current term of first polynomial with the term on the second
     for (int j=0; j<n; j++)
         product[i+j] += M[i]*N[j];
   }

   return product;
}

void printPoly(int poly[], int n)
{
    //Goes through the array and prints the polynomial
    for (int i=0; i<n; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != n-1)
       cout << " + ";
    }
}

// Driver program to test polynomial multiplier
int main(void) {

    //2x+1
    int M[] = {2,1};

    //2x+1
    int N[] = {2,1};

    //sets integer to size of each polynomial
    int m = sizeof(M)/sizeof(M[0]);
    int n = sizeof(N)/sizeof(N[0]);

    cout << "First polynomial is ";

    printPoly(M, m);

    cout << endl << "Second polynomial is ";

    printPoly(N, n);

    cout << endl;

    int *product = multiply(M, N, m, n);

    cout << "Product polynomial is ";
    printPoly(product, m+n-1);

    cout << endl;

    return 0;
}
