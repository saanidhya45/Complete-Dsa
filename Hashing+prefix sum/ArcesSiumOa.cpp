#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){

    string a = "abcd";
    string b = "bcda";

    /// create a two hasharray for both the even and the odd index

    int evenHash[26] = {0};
    int oddHash[26] = {0};

    for(int i=0; i<a.length(); i++){
    
        if(i%2 == 0){
            evenHash[a[i]-'a']++;
            evenHash[b[i]-'a']--;
        }
        else{
            oddHash[a[i]-'a']++;
            oddHash[a[i]-'a']--;
        }
    }

    bool flag = true;

    for(int i=0; i<26; i++){
        if(evenHash[i] != 0 || oddHash[i] != 0){
            flag = false;
            cout << "not twins";
            break;
        }
    }
    if(flag)
      cout << "given String are Twins" << endl;
    return 0;
}   