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







def main():
    solu = Solution()
    str_list = ["d", "", "dvdf", "abcabcbb"]

    for item in str_list:
        print(solu.lengthOfLongestSubstring(item))





if __name__ == '__main__':
    main()