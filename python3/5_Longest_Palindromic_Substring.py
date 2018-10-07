class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if length==0 or length==1:
            return s

        longest = str(s[0])

        # Brute force
        # for i in range(length):
        #     for j in range(1, length+1):
        #         sub_str = s[i:j]
        #         is_palindrome = True
        #         middle = int(len(sub_str) / 2)
        #         for k in range(0, middle):
        #             if sub_str[k]!=sub_str[-k-1]:
        #                 is_palindrome = False
        #                 break
        #         if is_palindrome and len(sub_str)>len(longest):
        #             longest = sub_str

        # Dynamic
        # Find from middle
        for i in range(1, length):

            sub_str = ""
            # compare s[:i] & s[i+1:], s[i] as middle
            #is_palindrome = True
            left = s[:i]
            right = s[i+1:]
            for k in range(0, min(len(left), len(right))):
                if left[-k-1] != right[k]:
                    #is_palindrome = False
                    break
                sub_str = s[i-k-1:i+k+2]
            if len(sub_str) > len(longest):
                longest = sub_str

            # compare s[:i] & s[i:], no middle
            is_palindrome = True
            left = s[:i]
            right = s[i:]
            for k in range(0, min(len(left), len(right))):
                if left[-1-k] != right[k]:
                    #is_palindrome = False
                    break
                sub_str = s[i-k-1:i+k+1]
            if len(sub_str) > len(longest):
                longest = sub_str


        return longest









def main():
    solu = Solution()
    str_list = ["babac", "cbbcd", "accav", "abcabcecb", "abcdc", "bd"]

    #str_list = ["cbbd"]
    for item in str_list:
        print(solu.longestPalindrome(item))





if __name__ == '__main__':
    main()