class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> valToIndex = new HashMap<>();
        int[] ans = new int[2];
        
        for(int i = 0; i < nums.length; i++){
            int newTarget = target - nums[i];
            if(valToIndex.containsKey(newTarget)){
                ans[0] = i;
                ans[1] = valToIndex.get(newTarget);
                break;
            }
            valToIndex.put(nums[i], i);
        }
        return ans;
    }
}