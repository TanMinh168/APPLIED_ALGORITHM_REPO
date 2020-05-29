#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int noOfRoad, typeOfAsphalt;
    int count=0;
    int road[n];
    int check[n]={0};
    for (int i=0; i<n; i++) {
        cin >> road[i];
    };
    int changes; cin >> changes;

    for (int i=0; i<n; i++) {
        if (i==0) check[i]=1;
        else if (road[i]!=road[i-1]) check[i]=1;
    }
    for (int i=0; i<n; i++) {
        count+=check[i];
    }

    for (int i=0; i<changes; i++) {
        cin >> noOfRoad; cin >> typeOfAsphalt;
        // Remove the old values
        count-=check[noOfRoad-1];
        if (noOfRoad!=n) count-=check[noOfRoad];

        //Update the current values
        road[noOfRoad-1] = typeOfAsphalt;
        if (noOfRoad==1) {
            check[0]=1;
            check[1]=road[1]!=road[0]?1:0;
        }
        else {
            check[noOfRoad-1]=road[noOfRoad-1]!=road[noOfRoad-2]?1:0;
            check[noOfRoad]=road[noOfRoad]!=road[noOfRoad-1]?1:0;
        }

        count+=check[noOfRoad-1];
        if (noOfRoad!=n) count +=check[noOfRoad];

        cout << count << endl;
    }
}

