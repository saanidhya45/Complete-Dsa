#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

int main() { 

    string s =  "LCTLLTCLC";


        ll n = s.length();
        
        ll noOfLCT = 0, L = 0, C = 0, T = 0, LC = 0,CT = 0;


        vector<ll> preffixL(n), suffixT(n);

        for(ll i=0; i<n; i++){
            char ch = s[i];

            if(ch == 'L') L++;
             if(ch == 'C') LC += L;
             if(ch == 'T') noOfLCT += LC;

            if(s[n-i-1] == 'T') T++;
            if(s[n-i-1] == 'C') CT += T;
            
            suffixT[n-i-1] = T;
        }
        ll ans1 = noOfLCT + LC;
        ll ans2 = noOfLCT + CT;

        ll ans3 = INT_MIN;
        L = 0;

        for(ll i=0; i<n; i++){
            if(s[i] == 'L') L++;
            ans3 = max(ans3, noOfLCT + (L*suffixT[i]));
        }
        cout <<  max({ans1, ans2, ans3});
    
    return 0;
}