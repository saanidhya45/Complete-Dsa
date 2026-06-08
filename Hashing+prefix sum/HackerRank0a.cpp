// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
    // we got our earliestTime no we have to return in the hh::mm format
using namespace std;

int main() {
    int k = 60;
    vector<string> events = {
        "00:00 08:00",
        "07:00 13:00",
        "12:30 13:59"
    };
    
    // at max our time can go upto 1440 minutes then create an temp array  of exact same size 
    
    vector<int> temp(1401, 0);
    
    // now go for every even

    
    for(auto event : events){
        // first we have to get the start
        int hh = stoi(event.substr(0,2));
        int mm = stoi(event.substr(3,2));
        
        int start = (hh*60)+mm;
        temp[start] += 1;
        
        
        hh = stoi(event.substr(6,2));
        mm = stoi(event.substr(9,2));
        
        int end = (hh*60)+mm;
        temp[end+1] -= 1;
        
    }
    for(int i=1; i<temp.size(); i++){
        temp[i] += temp[i-1];
    }
    
    // now we would traverse the temp array and find out the earlliest time possible
    int earliestTime = 0;
    int count = 0;
    for(int i=0; i<temp.size(); i++){
        
        if(temp[i] == 0){
            count++;
        }
        else{
            count = 0;
        }
        
        if(count == k){
            /// then we got our earliest time 
            earliestTime = (i-count)+1;
            break;
        }
    }
    
    cout << earliestTime << endl;

    // we got our earliestTime no we have to return in the hh::mm format
    
   int hh = (earliestTime/60);
   int mm = (earliestTime%60);
   // we got separeted hh and minutes
   
   string early = (hh < 10 ? "0"+to_string(hh) : to_string(hh)) + ':';
  
   early += (mm < 10 ? "0"+to_string(mm) : to_string(mm));
   
  cout << early << endl;
    return 0;
}