class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { //O(n log n) using sorting 50th day
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};