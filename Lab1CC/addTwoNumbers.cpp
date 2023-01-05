#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr, *temp = head;
    int val = 0, carry = 0;
    while (l1 && l2)
    {
        val = (l1->val + l2->val + carry);
        carry = val / 10;
        ListNode *a = new ListNode(val % 10);
        if (!head)
        {
            head = a;
            temp = head;
        }
        else
        {
            temp->next = a;
            temp = temp->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1)
    {
        if (carry == 0)
        {
            temp->next = l1;
            l1 = nullptr;
        }
        else
        {
            val = l1->val + carry;
            carry = val / 10;
            val %= 10;
            temp->next = new ListNode(val);
            temp = temp->next;
            l1 = l1->next;
        }
    }
    while (l2)
    {
        if (carry == 0)
        {
            temp->next = l2;
            l2 = nullptr;
        }
        else
        {
            val = l2->val + carry;
            carry = val / 10;
            val %= 10;
            temp->next = new ListNode(val);
            temp = temp->next;
            l2 = l2->next;
        }
    }
    while (carry)
    {
        val = carry % 10;
        carry /= 10;
        temp->next = new ListNode(val);
        temp = temp->next;
    }
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(8);
    // l1->next->next = new ListNode(3);
    ListNode *l2 = new ListNode(0);
    // l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);
    ListNode *l3 = addTwoNumbers(l1, l2);
    while (l3)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    return 0;
}