class Solution {
    public int reverse(int n){
        int tmp = 0;
        while(n != 0){
            int t = n%10;
            tmp = tmp*10 + t;
            n = n/10;
        }
        return tmp;
    }
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer, Integer> mp = new HashMap<>();
        int ans = Integer.MAX_VALUE;
        for(int i=0; i<nums.length; i++){
            if(mp.containsKey(nums[i])){
                ans = Math.min(ans, i-mp.get(nums[i]));
            }
            int tmp = reverse(nums[i]);
            mp.put(tmp, i);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}