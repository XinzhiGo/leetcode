#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *l; //head
    ListNode *r; //tail
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    if (l1 == nullptr && l2 != nullptr)
        return l2;
    if (l1 != nullptr && l2 == nullptr)
        return l1;
    if (l2->val <= l1->val)
    {   // 指針訪問要小心，涉及到訪問，就有可能為空！！
        l = new ListNode(l2->val);
        r = l;
        l2 = l2->next;
    }
    else
    {
        l = new ListNode(l1->val);
        r = l;
        l1 = l1->next;
    }
    while (l1 != nullptr && l2 != nullptr)
    {
        while (l1 != nullptr && l2 != nullptr && l1->val < l2->val)
        {
            r->next = new ListNode(l1->val);
            r = r->next;
            l1 = l1->next;
        }
        while (l1 != nullptr && l2 != nullptr && l1->val >= l2->val)
        {
            r->next = new ListNode(l2->val);
            r = r->next;
            l2 = l2->next;
        }
    }
    if (l1 != nullptr)
    {
        r->next = l1;
    }
    if (l2 != nullptr)
    {
        r->next = l2;
    }
    return l;
}

ListNode *createList(vector<int> vi)
{
    ListNode *p, *q;
    if (vi.size() == 0)
        return nullptr;
    p = new ListNode(vi[0]);
    q = p;
    for (int i = 1; i < vi.size(); i++)
    {
        q->next = new ListNode(vi[i]);
        q = q->next;
    }
    return p;
}

void printList(ListNode *l)
{
    while (l != nullptr)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    vector<int> num1 = {1, 3, 4};
    vector<int> num2 = {1, 2, 4};
    ListNode *l1 = createList(num1);
    ListNode *l2 = createList(num2);
    printList(l1);
    printList(l2);
    ListNode *l = mergeTwoLists(l1, l2);
    printList(l);
}