#include <bits/stdc++.h>
using namespace std;
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

// Remove nth node from the end

int Length(Node *head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

Node *removeNthFromEnd(Node *head, int n)
{
    int len = Length(head);
    Node *temp = head;
    if (n == len)
    {
        Node *todelete = head;
        head = head->next;
        return head;
    }

    else
    {
        int cnt = 0;
        int k = len - n;
        while (temp != NULL)
        {
            cnt++;
            if (cnt == k)
                temp->next = temp->next->next;
            temp = temp->next;
        }
        // temp->next=temp->next->next;
    }
    return head;
}

// Optimise Code

Node *OptimiseremoveNthFromEnd(Node *head, int n)
{
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *fast = dummy;
    Node *slow = dummy;

    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
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
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Insert(head, num);
    }

    Display(head);
    Node *ans = OptimiseremoveNthFromEnd(head, d);
    Display(ans);
    return 0;
}