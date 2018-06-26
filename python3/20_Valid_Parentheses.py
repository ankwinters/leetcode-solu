#!/usr/bin/python3


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s=='':
            return True
        else:
            par_stack = []
            for char in s:
                if char == '(' or char == '{' or char == '[':
                    par_stack.append(char)
                else:
                    # Validation check
                    if len(par_stack) == 0:
                        return False
                    # Check
                    last = par_stack[-1]
                    if last == '(' and char == ')':
                        par_stack.pop()
                    elif last == '[' and char == ']':
                        par_stack.pop()
                    elif last == '{' and char == '}':
                        par_stack.pop()
                    else:
                        return False
            if len(par_stack) == 0:
                return True
            else:
                return False









def main():
    samples = ['','({{}}[])', '({[][]})', "([)]"]
    solu = Solution()

    #solu.isValid(samples[1])
    for sample in samples:
        print(solu.isValid(sample))


if __name__ == '__main__':
    main()