#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int total = 0;
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        if(arr[i] >= n){
            cout << 0;
            break;
        }
        int req = arr[arr[arr[i]]];
        if(mp.find(req) != mp.end()){
            total += mp[req];
        }
        mp[arr[i]]++;
    }

    cout << total << endl;

    return 0;
}