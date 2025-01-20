class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int row = 0, col = 0;
        int[] rows = new int[n];
        int[] cols = new int[m];
        Map<Integer, int[]> mp = new HashMap();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp.put(mat[i][j], new int[]{i, j});
            }
        }

        for(int i=0; i<arr.length; i++){
            if(mp.containsKey(arr[i])){
                row = mp.get(arr[i])[0];
                col = mp.get(arr[i])[1];
            }
            rows[row]++;
            cols[col]++;
            if(rows[row]==m || cols[col]==n)
                return i;
        }
        return -1;
    }
}