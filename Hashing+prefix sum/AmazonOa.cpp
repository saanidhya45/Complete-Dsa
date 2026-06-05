#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr ={1,1,1,2,2,2,2};
    
    unordered_map<int, int> mp;

    for(auto it : arr) mp[it]++;

    // there are some three cases just look at the reminders of the 3 would be [0,1,2]
    // let suppose minimumTrip = 0
    // lef x to be it.second of some element x % 3 == 0  minimumTrip += x / 3;
    // let x to be it.second of some element x % 3 == 2  minimumTrip += x / 3 + 1;
    // let x to be it.second of some element x % 3 == 1 minimumTrip += ((x / 3) - 1) + 2;
    
    int minimumTrip = 0;

    for(auto it : mp){
        
        int freq = it.second;

        if(freq == 1){
            cout << -1 << endl;
            break;
        }

        if(freq % 3 == 0) 
            minimumTrip += freq/3;

        else if(freq % 3 == 1)
            minimumTrip += ((freq / 3) - 1) + 2;

        else 
            minimumTrip += (freq / 3) + 1;

    }

    

    cout << minimumTrip;

    return 0;
}