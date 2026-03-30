class Solution {
    public boolean checkStrings(String s1, String s2) {
        StringBuilder e1 = new StringBuilder();
        StringBuilder e2 = new StringBuilder();
        StringBuilder o1 = new StringBuilder();
        StringBuilder o2 = new StringBuilder();

        for(int i=0; i<s1.length(); i++){
            if(i%2 == 0){
                e1.append(s1.charAt(i));
                e2.append(s2.charAt(i));
            }
            else{
                o1.append(s1.charAt(i));
                o2.append(s2.charAt(i));
            }
        }

        char[] a1 = e1.toString().toCharArray();
        char[] a2 = e2.toString().toCharArray();
        char[] a3 = o1.toString().toCharArray();
        char[] a4 = o2.toString().toCharArray();

        Arrays.sort(a1);
        Arrays.sort(a2);
        Arrays.sort(a3);
        Arrays.sort(a4);

        return Arrays.equals(a1, a2) && Arrays.equals(a3, a4);
    }
}