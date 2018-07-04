#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedArray(vector<int>& a, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<int> tempL(n1, 0), tempR(n2, 0);
    for (int i = 0; i < n1; i++)
        tempL[i] = a[start + i];
    for (int i = 0; i < n2; i++)
        tempR[i] = a[mid + 1 + i];
    int i = start, p = 0, q = 0;
    while (p < n1 && q < n2) {
        if (tempL[p] < tempR[q]) {
            a[i++] = tempL[p++];
        } else {
            a[i++] = tempR[q++];
        }
    }
    while (p < n1) {
         a[i++] = tempL[p++];
    }
    while (q < n2) {
         a[i++] = tempR[q++];
    }
}

void mergeSort(vector<int>& a, int start, int end) {
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);
    mergeTwoSortedArray(a, start, mid, end);
}

int main() {
    vector<int> a = {12, 3, 33, 0, 8, 23, 88, 13, 9, 1};
    mergeSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
