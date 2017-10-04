#include <iostream>
using namespace std;

void quickSort(int a[], int start, int end) {
  if (start >= end)
    return ;
  int povit = a[start];
  int last = start;
  for (int i = start + 1; i <= end; i++) {
    if (a[i] < povit)
      swap(a[++last], a[i]);
  }
  swap(a[last], a[start]);
  quickSort(a, start, last - 1);
  quickSort(a, last + 1, end);
}

int main() {
  int a[10] = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1};
  quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
  for (int i = 0; i < 10; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
