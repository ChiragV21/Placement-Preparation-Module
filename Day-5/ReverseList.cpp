#include <bits/stdc++.h>
using namespace std;
// Linked List-Reverse Linked List
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

// Using 2 Pointers
void Reverse(Node *&head)
{
    Node *dummy = NULL;
    while (head != NULL)
    {
        Node *temp = head->next;
        head->next = dummy;
        dummy = head;
        head = temp;
    }
    head = dummy;
}

// Using 3 Pointers
Node *Reversed(Node *head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Insert(head, num);
    }
    // Node* rev=Reversed(head);
    Reverse(head);
    Display(head);
    return 0;
}