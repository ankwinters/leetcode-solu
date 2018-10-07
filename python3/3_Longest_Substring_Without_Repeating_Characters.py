class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        longest = 0
        length = len(s)
        # Brute Force, O(n^3)
        """
        while i < length:
            str_map = {}
            sub_len = 0
            for j in range(i, length):
                char = s[j]
                if char not in str_map.keys():
                    #print(str_map)
                    sub_len += 1
                    str_map[char] = 1
                else:
                    break
            if longest<sub_len:
                longest = sub_len
        """
        # more quick
        sub_str = ""
        for i in range(0, length):
            for j in range(i+len(sub_str), length):
                if s[j] not in sub_str:
                    sub_str += str(s[j])
                else:
                    break

            if longest < len(sub_str):
                longest = len(sub_str)
            sub_str = sub_str[1:]

        return longest



    def longestsubstr(self, s):
        if len(s) == 0 or len(s) == 1:
            return s

        max_sub = ""

        for i in range(0, len(s)):
            #
            s1 = self.spread(s, i, 0)
            s2 = self.spread(s, i, 1)
            if len(s1) > len(max_sub):
                max_sub = s1
            if len(s2) > len(max_sub):
                max_sub = s2

        return max_sub

    def spread(self, s, center, offset):
        l = center
        r = center + offset

        while (l>=0 and r<len(s) and s[l]==s[r]):
            l -= 1
            r += 1

        l += 1
        return s[l:r]





def main():
    solu = Solution()
    str_list = ["d", "", "dvdf", "abcabcbb"]

    for item in str_list:
        print(solu.longestsubstr(item))





if __name__ == '__main__':
    main()