#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums1 = {2,5}, nums2 = {3,8}, nums3 = {-5,8}, nums4 = {5,10}, nums5 = {-10,100};

    unordered_map<int, int> mp;
    int total = 0;

    for(int i=0; i<nums1.size(); i++){
        for(int j=0; j<nums2.size(); j++){
            int sum = nums1[i] + nums2[j];
            mp[sum]++;
        }
    }

    // (n*2)

    for(int i=0; i<nums3.size(); i++){
        for(int j=0; j<nums4.size(); j++){
            for(int k=0; k<nums5.size(); k++){
                int sum = nums3[i] + nums4[j] + nums5[k];
                if(mp.find(-sum) != mp.end()){
                    total += mp[-sum];
                }
            }
        }

    }

    // (n*3)

    cout << total << endl;


    return 0;
}
