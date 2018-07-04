#include <iostream>
using namespace std;

void bubblesort(int a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool needSwap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                needSwap  = true;
            }
        }
        if (!needSwap)
            break;
    }
}

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++) {
        a[i] = rand() % 100;
        cout << a[i] << " ";
    }
    cout << endl;
    bubblesort(a, 10);
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
