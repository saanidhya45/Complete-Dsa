#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> arr = {{1,7},{5,11},{7,9}};
    vector<int> points = {7,1,5,10,9,15};

    int maximum = INT_MIN;
    

    for(auto it : arr){
        for(auto c : it){
            maximum = max(maximum, c);
        }
    }

    maximum = max(maximum, *max_element(points.begin(), points.end()));
    
    cout << maximum << endl;

    vector<int> temp(maximum + 1, 0);

    for(int i=0; i<arr.size(); i++){
        int start = arr[i][0];
        int end = arr[i][1];

        temp[start] += 1;
        temp[end+1] -= 1;
    }

    for(int i=1; i<temp.size(); i++){
        temp[i] += temp[i-1];
    }
    
    // for(auto it : temp){
    //     cout << it << " ";
    // }
 
    
    vector<int> lampPoints(points.size(),0);

    for(int i=0; i<points.size(); i++){
        lampPoints[i] = temp[points[i]];
    }

    for(auto it : lampPoints){
        cout << it << " ";
    }
    cout << endl;




    return 0;
}