#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr ={4,6,8};

    int n = arr.size();
    int x = 2;

    int maximum = *max_element(arr.begin(), arr.end());
    //** here is the important edge case of handling -index range when we are doing num - x then in this case range could be start from negetive index
    // then it would definately be a invalid index accessing right we just do not need the actual valuses right so inorder to make this valid shift every index to the positiive side with equal amount overlapp will reamain same  */
    
    int offset = x;

    vector<int> temp(maximum + x + 2, 0);

    for(int i = 0; i < arr.size(); i++){

        int num = arr[i];

        int start = (num - x) + offset;
        int end = (num + x) + offset;

        temp[start] += 1;
        temp[end + 1] -= 1;
    }

    for(int i = 1; i < temp.size(); i++){
        temp[i] += temp[i - 1];
    }

    int maximumOverLap = INT_MIN;

    for(int i = 0; i < temp.size(); i++){
        maximumOverLap = max(maximumOverLap, temp[i]);
    }

    cout << maximumOverLap;

    return 0;
}