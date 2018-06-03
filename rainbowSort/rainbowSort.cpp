#include <iostream>
#include <vector>
using namespace std;

void rainbowSortHelper(vector<int>& colors, int left, int right, int colorFrom, int colorTo) {
    if (colorFrom == colorTo || left >= right) {
        return;
    }
    int colorMid = colorFrom + (colorTo - colorFrom) / 2;
    int l = left, r = right;
    while (l <= r) {
        while (l <= r && colors[l] <= colorMid) // find first larger than colorMid 
            l++;
        while (l <= r && colors[r] > colorMid) // find first less than or equal to colorMid 
            r--;
        if (l <= r) {
            int temp = colors[l];
            colors[l] = colors[r];
            colors[r] = temp;
            l++;
            r--;
        }
    }
    rainbowSortHelper(colors, left, r, colorFrom, colorMid);
    rainbowSortHelper(colors, l, right, colorMid + 1, colorTo);
}

void rainbowSort(vector<int>& colors, int k) {
    if (colors.empty() || k <= 1)
        return;
    rainbowSortHelper(colors, 0, colors.size() - 1, 1, k);
}

int main() {
    vector<int> colors = {1, 2, 3, 1, 1, 5, 4, 5, 2, 3, 4, 2};
    rainbowSort(colors, 5);
    for (int c : colors)
        cout << c << " ";
    cout << endl;
    return 0;
}
