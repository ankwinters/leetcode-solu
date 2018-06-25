
#include <iostream>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // One node
        if(head->next==NULL)
            return head;
        // More than one node
        ListNode* last_group_end = NULL;
        auto group_begin = head;

        auto returned_ptr = head->next;

        while(group_begin != NULL)
        {
            auto item1 = group_begin;
            auto item2 = group_begin->next;
            // One node situation
            if(item2 ==NULL)
                break;
            // Swap the first & second in the group
            ListNode* tmp = item2->next;
            item2->next = item1;
            item1->next = tmp;
            // Swap ptr
            tmp = item2;
            item2 = item1;
            item1 = tmp;
            // Update last group next ptr
            if(last_group_end != NULL)
                last_group_end->next = item1;
            // update group
            last_group_end = item2;
            group_begin = item2->next;

        }
        return returned_ptr;

    }
};

// List node utility
ListNode* create_list_node(int *values, int length)
{
    if(length<=0)
        return NULL;
    // begin node
    ListNode* node_list = new ListNode(values[0]);
    ListNode* node_ptr = node_list;
    for(int i=1;i<length;i++)
    {
        ListNode* node = new ListNode(values[i]);
        node_ptr->next = node;
        node_ptr = node;
    }
    return node_list;
}

void clean_list_node(ListNode *node_list)
{
    ListNode *cleaner = node_list;
    while(cleaner != NULL)
    {
        cleaner = node_list->next;
        delete(node_list);
        node_list = cleaner;
    }
}

// Debug
void print_list_node(ListNode *node_list)
{
    ListNode *node_ptr = node_list;
    cout<<"List:";
    while(node_ptr != NULL)
    {
        cout<<node_ptr->val;
        if(node_ptr->next != NULL)
            cout << "->";
        else
            cout<<endl;
        node_ptr = node_ptr->next;
    }

}

int main()
{
    const int len = 6;
    int values[len] = {1, 2, 3,4,5,6};
    ListNode *list = create_list_node(values, len);
    print_list_node(list);
    //clean_list_node(list);

    // do something
    Solution solu;
    auto list_ptr = solu.swapPairs(list);
    print_list_node(list_ptr);
    clean_list_node(list_ptr);

    return 0;
}