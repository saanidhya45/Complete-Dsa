#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {34,3,12,-1,2,-2,0,15,50};

    /// we have to find the maximum sum subarray

    // using the extra space
    vector<int> prefix(arr.size());
    prefix[0] = max(arr[0],0);

    int maximum = INT_MIN;
    maximum = max(maximum, prefix[0]);
    
    for(int i=1; i<arr.size(); i++){
        prefix[i] = max({prefix[i-1] + arr[i], arr[i], 0});
        maximum = max(maximum, prefix[i]);
    }

    cout << maximum;


    return 0;
}