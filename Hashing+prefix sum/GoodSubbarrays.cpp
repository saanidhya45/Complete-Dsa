#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {3,1,4,3,2,2,4};
    // int n = arr.size();
    int k = 2;

     int GoodSubarrays = 0;
        int n = arr.size();
        unordered_map<int,int>mp;
        int left = 0, right = 0;
        int pairs = 0;
        while(right < n){
            
            cout << pairs << endl;

            if(mp.find(arr[right]) != mp.end()){
                pairs += mp[arr[right]];
            }

            mp[arr[right]]++;

            for(int i=1; i<=pairs; i++){
                cout << "valid pairs" << pairs << " ";
            }

            cout << endl;
            while(left < right && pairs >= k){
                GoodSubarrays += n-right;
                cout << GoodSubarrays << endl;
                pairs -= mp[arr[left]] - 1;
                mp[arr[left]]--;
                left++;
            }

            
            right++;
        }
        cout << "total good ones are :: " << GoodSubarrays << endl;;
    
}