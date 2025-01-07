class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        l = set([])
        for i in range(len(words)):
            for j in range(len(words)):
                if(i!=j and words[i] in words[j]):
                    l.add(words[i])
        l = list(l)
        return l