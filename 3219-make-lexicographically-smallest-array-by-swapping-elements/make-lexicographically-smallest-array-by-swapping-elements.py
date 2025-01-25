class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        nums_id = []
        for i, num in enumerate(nums):
            nums_id.append((num, i))
        nums_id.sort()
        ids = [nums_id[0][1]]
        vals = [nums_id[0][0]]
        def rearrange_groups(ids, vals):
            vals = sorted(vals)
            ids = sorted(ids)
            for ix in range(len(ids)):
                nums[ids[ix]] = vals[ix]
        for i in range(len(nums) - 1):
            if nums_id[i+1][0] - nums_id[i][0] <= limit:
                vals.append(nums_id[i+1][0])
                ids.append(nums_id[i+1][1])
            else:
                rearrange_groups(ids, vals)
                vals = [nums_id[i+1][0]] 
                ids = [nums_id[i+1][1]]
        rearrange_groups(ids, vals)
        return nums