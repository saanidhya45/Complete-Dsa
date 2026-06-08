#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {23, 45, 76, 45, 76, 87, 23};
     int X = 23, Y = 45, Z = 76;


     map<pair<int,int>, int>mp;

     int c1 = 0; // freq of x;
     int c2 = 0; // freq of y;
     int c3 = 0; // freq of z;

     mp[{0,0}] = 1;

     int total = 0;

     for(int i=0; i<arr.size(); i++){

        if(arr[i] == X) c1++;
        else if(arr[i] == Y) c2++;
        else if(arr[i] == Z) c3++;

        total += mp[{c1 - c2, c2 - c3}];
        mp[{c1 - c2, c2 - c3}]++;

     }

     cout << total;

    
    return 0;
}