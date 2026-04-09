class Solution {
    public int search(int arr[], int x) {
        // code here
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int it: arr){
            res.add(it);
        }
        
        int t = res.indexOf(x);
        return t;
    }
}
