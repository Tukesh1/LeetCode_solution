class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        Sum = sum(nums)
        n= len(nums)
        acc, cnt=0,0
        for i in range(n-1):
            acc+= nums[i]
            cnt += (2*acc >= Sum)
        
        return cnt
        