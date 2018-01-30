class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> numcount;
        unordered_map<int, int> firstindex;
        int order = 0;
        int minLength = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(numcount.count(nums[i])){
                numcount[nums[i]]++;
            } else{
                numcount[nums[i]] = 1;
                firstindex[nums[i]] = i;
            }
            
            if(numcount[nums[i]] > order){
                order = numcount[nums[i]];
                minLength = i +1 - firstindex[nums[i]];
                
            } else if (numcount[nums[i]] == order && i +1 - firstindex[nums[i]] < minLength){
                minLength = i +1 - firstindex[nums[i]];
            }
        }
        
        return minLength;
    }
};