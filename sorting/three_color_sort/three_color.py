
class Solution:
    def sort(self, nums):
        i = j = 0
        for k, v in enumerate(nums):
            nums[k]=2
            if v < 2:
                nums[j]=1
                j+=1
            if v == 0:
                nums[i]=0
                i+=1


s = Solution()
s.sort([2,1,1,0,2])