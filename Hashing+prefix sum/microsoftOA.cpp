#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int getDigitSum(int n){
    int sum = 0;
    while(n != 0){
        int ld = n % 10;
        sum += ld;
        n = n / 10;
    }

    return sum;
}
int main(){

    vector<int> arr = {42, 33, 60};
    int n = arr.size();

    unordered_map<int, int> mp;

    int maximumSum = INT_MIN;


    for(int i=0; i<n; i++){
        int current = arr[i];
        int digitSum = getDigitSum(current);
        if(mp.find(digitSum) != mp.end()){
            
            maximumSum = max(maximumSum, current + arr[mp[digitSum]]);
            
                    if(current > arr[mp[digitSum]]){
                        mp[digitSum] = i;
                    }
        }
        else{
            mp[digitSum] = i;
        }
        
    }

    cout << maximumSum;

    return 0;
}