class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        i=0
        j=len(skill)-1
        t=skill[i] + skill[j]
        pro = 0
        while(i<j):
            if(skill[i] + skill[j] == t):
                pro += skill[i] * skill[j]
            else:
                return -1
            i+=1
            j-=1
        return pro