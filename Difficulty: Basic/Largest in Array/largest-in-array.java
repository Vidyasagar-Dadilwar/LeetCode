class Solution {
    public static int largest(int[] arr) {
        // code here
        ArrayList<Integer> l = new ArrayList<>();
        
        for(int it: arr){
            l.add(it);
        }
        
        return l.stream().max(Integer::compare).get();
    }
}
