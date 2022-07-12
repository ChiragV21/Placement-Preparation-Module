#include <bits/stdc++.h>
using namespace std;
// Linked List-Intersection Point of Two Linked List
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Insert(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void Intersact(Node *&headA, Node *&headB, int pos)
{
    Node *temp1 = headA;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    Node *temp2 = headB;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

// Intesection Point of Two Linked List
int Length(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int getIntersectionNode(Node *&headA, Node *&headB)
{
    int n1 = Length(headA);
    int n2 = Length(headB);
    Node *l1;
    Node *l2;
    int d = 0;
    if (n1 > n2)
    {
        d = n1 - n2;
        l1 = headA;
        l2 = headB;
    }

    else
    {
        d = n2 - n1;
        l1 = headB;
        l2 = headA;
    }

    while (d--)
    {
        l1 = l1->next;
        if (l1 == NULL)
        {
            return -1;
        }
    }

    while (l1 != NULL and l2 != NULL)
    {
        if (l1 == l2)
        {
            return l1->data;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}

void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *head1 = NULL;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Insert(head, num);
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        Insert(head1, num);
    }

    Display(head);
    Display(head1);
    Intersact(head, head1, 3);
    int ans = getIntersectionNode(head, head1);
    cout << ans << endl;
    return 0;
}