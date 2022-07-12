#include <bits/stdc++.h>
using namespace std;
// Linked List-Reverse k Group
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

Node* ReversekGroup(Node* head,int k){
    if(head==NULL){
        return NULL;
    }

    Node* prev=NULL;
    Node* curr=head;
    Node* next;
    int count=0;
    //Reverse k Nodes
    while(curr!=NULL and count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    //Recursion handles Remaining Nodes
    if(next!=NULL){
        head->next=ReversekGroup(next,k);
    }
    return prev;
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
    //Node *head1 = NULL;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Insert(head, num);
    }

    Node* res=ReversekGroup(head,k);
    Display(res);
    return 0;
}