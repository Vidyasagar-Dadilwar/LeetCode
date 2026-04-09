class Solution {
    public void reverseArray(int arr[]) {
        // code here
        ArrayList<Integer> l = new ArrayList<>();
        
        for(int it: arr){
            l.add(it);
        }
        Collections.reverse(l);
        
        int i=0;
        for(Integer it: l){
            arr[i++] = it;
        }
    }
}