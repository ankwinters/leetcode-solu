#!/usr/bin/python3


class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # # Brute force, O(k*n)
        # for i in range(k):
        #     last= nums[-1]
        #     tmp = nums[0]
        #     for j in range(1, len(nums)):
        #         tmp, nums[j] = nums[j], tmp
        #     nums[0] = last

        # More pythonic
        step =  k - len(nums) * (k // len(nums))
        head = nums[-step:]
        head.extend(nums[0:-step])
        for i in range(len(head)):
            nums[i] = head[i]

        return nums






def main():
    numbers = [1,4,2,8,5,7]
    k=10
    solu = Solution()
    print(solu.rotate(numbers,k))
    print(numbers)


if __name__ == '__main__':
    main()