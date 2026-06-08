#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {5, -2, 3, 1, 2};
    int k = 3;

    int n = arr.size();

    int summation = 0;
    for(int i=0; i<k; i++){
        summation += arr[i];
    }

    int maximum = summation;

    int index = n-1;
    for(int i=k-1; i>=0; i--){
        summation += arr[index--];
        summation -= arr[i];
        maximum = max(maximum, summation);
    }
    cout << maximum;
    return 0;
}