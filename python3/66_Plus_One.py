#!/usr/bin/python3


class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        # Plus 1
        digits[-1] += 1
        # [-len+1, -1]
        for i in range(1, len(digits)):
            if digits[-i] == 10:
                digits[-i] = 0
                digits[-i-1] += 1
            else:
                break

        # Check head
        if digits[0] == 10:
            result = [1, 0]
            if len(digits) > 1:
                result.extend(digits[1:])

            return result
        else:
            return digits




def main():
    numbers = [3,2]
    solu = Solution()
    print(solu.plusOne(numbers))


if __name__ == '__main__':
    main()