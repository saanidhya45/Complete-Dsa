#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

        vector<int> arr = {34,3,12,-1,2,-2,0,15,50};

        int n = arr.size();

        vector<int> maxSuffix(arr.size());
        
        maxSuffix[n-1] = max(arr[n-1], 0);
        int prev = maxSuffix[n-1];
    
        for(int i=n-2; i>=0; i--){
            int current = max({arr[i]+prev, arr[i], 0});
            prev = current;
            maxSuffix[i] = current;
        }

        // now we have to get the two maximum sum subbarray which is not overlapping each other
        int maximum = INT_MIN;
         prev = max(arr[0], 0);

         // current only stores the current best maxsubbaray not the left best

         int leftBest = INT_MIN;

        for(int i=1; i<n-1; i++){
            int current = max({arr[i] + prev, arr[i], 0});
            prev = current;
            leftBest = max(leftBest, current);
            maximum = max(maximum, leftBest + maxSuffix[i+1]);
        }

        cout << maximum;
    return 0;
}