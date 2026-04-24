class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        int t = 0;
        List<String> ans = new ArrayList<>();
        for(String s1: queries){
            for(String s2: dictionary){
                int diff = 0;
                for(int i=0; i<s1.length(); i++){
                    if(s1.charAt(i) != s2.charAt(i)) 
                        diff++;
                    if(diff > 2)
                        break;
                }
                if(diff <= 2){
                    ans.add(s1);
                    break;
                }
            }
        }
        return ans;
    }
}