#!/usr/bin/python3

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l1_ptr = l1
        l2_ptr = l2
        # Brute force
        n1 = 0
        n2 = 0
        val1 = 0
        val2 = 0
        while l1_ptr is not None:
            val1 += l1_ptr.val * (10**n1)
            n1 += 1
            l1_ptr = l1_ptr.next
        while l2_ptr is not None:
            val2 += l2_ptr.val * (10 ** n2)
            n2 += 1
            l2_ptr = l2_ptr.next

        # tokenize
        add_sum = val1 + val2
        val_list = []
        for item in str(add_sum):
            val_list.append(int(item))
        val_list.reverse()

        node_list = []
        for val in val_list:
            node = ListNode(val)
            node_list.append(node)

        for i in range(len(node_list) - 1):
            node_list[i].next = node_list[i + 1]

        return node_list[0]





def create_list(val_list):
    node_list = []
    for val in val_list:
        node = ListNode(val)
        node_list.append(node)

    for i in range(len(node_list)-1):
        node_list[i].next = node_list[i+1]

    return node_list

def print_list(l):
    l_ptr = l
    val_list = []
    while l_ptr is not None:
        val_list.append(l_ptr.val)
        l_ptr = l_ptr.next
    print("list node:", val_list)




def main():
    vals_1 = [2, 4, 3]
    vals_2 = [5, 6, 4]

    node_list1 = create_list(vals_1)
    node_list2 = create_list(vals_2)
    l1 = node_list1[0]
    l2 = node_list2[0]
    solu = Solution()
    print_list(solu.addTwoNumbers(l1, l2))

    #print_list(node_list1[0])
    #print_list(node_list2[0])




if __name__ == '__main__':
    main()