class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int num : nums){
            if(even(num)){
                count++;
            }
        }
        return count;
    }
    boolean even(int num){
        if(num < 0)
            num *= -1;
        int t = (int)(Math.log10(num)) + 1;
        return t % 2 == 0;
    }
}