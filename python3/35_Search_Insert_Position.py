#!/usr/bin/python3

class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # Original version
        if target < nums[0]:
            return 0

        if target > nums[-1]:
            return len(nums)

        for i in range(0, len(nums)):
            if target == nums[i]:
                return i

        for i in range(0, len(nums)-1):
            if nums[i] < target < nums[i+1]:
                return i+1





def main():
    numbers = [1]
    search = input('input an number:')
    solu = Solution()
    print(solu.searchInsert(numbers, int(search)))


if __name__ == '__main__':
    while(1):
        main()
