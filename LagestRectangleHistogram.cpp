#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int h, pos, tmpH, tmpPos, tmpSize = 0, maxSize = 0;
stack <int> hStack, pStack;

void popThatShit() {
    tmpH = hStack.top();
    hStack.pop();
    tmpPos = pStack.top();
    pStack.pop();
    tmpSize = tmpH * (pos - tmpPos);
    maxSize = max(tmpSize, maxSize);
}

void findLargestRecHist(int size){
    int hist[size];
    for (int i = 0; i < size; i++) {
        cin >> hist[i];
    }

    for (pos = 0; pos < size; pos++) {
        h = hist[pos];
        if (hStack.size() == 0 || h > hStack.top()) {
            hStack.push(h); pStack.push(pos);
        } else if (h < hStack.top()) {
            while (hStack.size() && h < hStack.top()) {
                popThatShit();
            }
            hStack.push(h);
            pStack.push(tmpPos);
        }
    }
    while (hStack.size()) {
        popThatShit();
    }
    cout << maxSize << endl;
    maxSize = 0;
}

int main() {
    int size;
    while (cin >> size) {
        if (size == 0) break;
        else findLargestRecHist(size);
    }
    return 0;
}
