#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {3, 6, 7, 8, 3, 6, 7};
     int X = 3, Y = 6, Z = 7;


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

        int first = c1 - c2;
        int second = c2 - c3;

        total += mp[{first, second}];
        mp[{first, second}]++;

     }

     cout << total;

    
    return 0;
}