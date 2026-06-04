class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int total = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int preodds = 0;
        for(int i=0; i<n; i++){
            if(nums[i] & 1) preodds++;
            int need = preodds - k;
            total += mp[need];
            mp[preodds]++;
        }
        return total;
    }
};

// in which just we have to count the how many previous predodds - k are there then there will be a valid subbary at index i 

