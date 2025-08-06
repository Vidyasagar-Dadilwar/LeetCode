class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int bN = baskets.length, fN = fruits.length, fruitsRem = fN;
        int m = (int)Math.sqrt(bN), batchSize = (bN + m - 1) / m;
        int maxInBatch[] = new int[batchSize];
        for(int i = 0; i < bN; i++)    maxInBatch[i / m] = Math.max(maxInBatch[i / m], baskets[i]);
        for(int i = 0; i < fN; i++){
            for(int batch = 0; batch < batchSize && fruits[i] != -1; batch++){
                if(maxInBatch[batch] < fruits[i])   continue;
                maxInBatch[batch] = 0; 
                for(int j = m * batch; j < Math.min(m * (batch + 1), bN); j++){
                    if(fruits[i] <= baskets[j]){
                        fruits[i] = Integer.MAX_VALUE;
                        baskets[j] = 0;
                        fruitsRem--;
                    }else   maxInBatch[batch] = Math.max(maxInBatch[batch], baskets[j]);
                }  
            }
        } 
        return fruitsRem;
    }
}