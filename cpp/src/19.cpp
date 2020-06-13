#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {};
};

int main()
{
    vector<int> list = { 1,2,3,4,5 };
    ListNode* head = convertVectorToListNode(list);

    removeNthFromEnd(head, 2);
 }

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return head;

    ListNode* p = head, * q = head;

    while (p->next)
    {
        p = p->next;
        if (n > 0) n--;
        else q = q->next;
    }
    if (p == q) return NULL;

    q->next = q->next->next;

    return head;
}

ListNode* removeNthEndMy(ListNode* head, int n) {
    ListNode* p = head;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    n = len - n - 1;
    p = head;
    if (n < 0) return head->next;
    while (n--) p = p->next;
    p->next = p->next->next;
    return head;
}

ListNode* convertVectorToListNode(vector<int> list)
{
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

