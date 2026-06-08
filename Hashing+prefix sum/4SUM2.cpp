#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

   vector<int> A = {1, -2, 4}, B = {2, -1, -4}, C = {0, 1, -1};

   unordered_map<int, int> mp;

   for(int i=0; i<A.size(); i++){
     mp[A[i]]++;
   }

   int pairs = 0;

   for(int i=0; i<B.size(); i++){
     for(int j=0; j<C.size(); j++){
        int sum = B[i] + C[j];
        if(mp.find(-sum) != mp.end()){
            pairs += mp[-sum];
        }
     }
   }
   cout << pairs << endl;




    return 0;
}