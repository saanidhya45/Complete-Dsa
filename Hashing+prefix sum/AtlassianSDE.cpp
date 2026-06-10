#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//// in this problem we just have to divide the array in two equal part
int main(){

    vector<int> arr = {0,2,1,-6,6,-7,9,1,2,0,1};
    int n = arr.size();

    int totalSum = accumulate(begin(arr), end(arr), 0);

    // there is multiple ways to solve first one try every pair which n2 second one is for prefix sum and suffix sum which would cost extra space and the third one is just maintain two variable LHS AND RHS if lhs == rhs then increase the counter 

    int cnt = 0;

    if(totalSum % 2 == 0){
        // then only we will be able to divide the array in two equal parts
        int lhs = 0;
        for(int i=0; i<n; i++){
            lhs += arr[i];
            int rhs = totalSum - lhs;
            if(lhs == rhs){
                cnt++;
            }
        }
    }

    // cout << "totalPairs : " << cnt << endl;


    // now here comes the 1st follow --> in which we have to divide the array in three equal parts 

    // first we calculate the totalSum and inorder to divide the array in three equal parts on the basis of the sum then that sum must be divisible by 3 complete then only we will get the correct answer 


    cnt = 0;
    unordered_map<int,int> frequency;
    int presum = 0;
    int LHS = 0;
    
    if(totalSum % 3 == 0){
        for(int i=0; i<n-1; i++){

            LHS += arr[i];
            int x = totalSum / 3;
            int RHS = totalSum - LHS;

            if(LHS == 2*x && RHS == x){
                cnt += frequency[LHS/2];
            }

            frequency[LHS]++;
        }
    }

    cout << "totalPairs << : " << cnt << endl; 
    return 0;
}

