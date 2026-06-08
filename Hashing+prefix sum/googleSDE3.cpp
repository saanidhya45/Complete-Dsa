#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> arr = {4, 2, 5, 1, 3};

    // first we will have to count the number of greater element from the right then left

    vector<int> pre(arr.size()), suff(arr.size(), 0);
    pre[0] = 0;

    for(int i=1; i<arr.size(); i++){
        int cnt = 0;
        for(int j=i-1; j>=0; j--){
            if(arr[j] > arr[i]){
                cnt++;
            }
        }
        pre[i] = cnt;
    }

    suff[arr.size()-1] = 0;

    for(int i=arr.size()-2; i>=0; i--){
        int cnt = 0;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j] < arr[i]){
                cnt++;
            }
        }
        suff[i] = cnt;
    }

    for(auto it : suff){
        cout << it << " ";
    }

    cout << endl;

    int totalPairs = 0;
    
    // follow up problem 

 /// -->> A[i] > A[J] < A[K] > A[l]

    // for(int i=1; i<arr.size()-1; i++){
    //     totalPairs += pre[i] * suff[i];
    // }

    int n = arr.size();
    for(int j=1; j<n-2; j++){
        for(int k=j+1; k<n-1; k++){
            if(arr[k] > arr[j]){
                totalPairs += pre[j]*suff[k];
            }
        }
    }

    cout << totalPairs;
    return 0;
}