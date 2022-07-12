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

Node *Reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void createcycle(Node* &head,int pos){
    Node* temp=head;
    Node* startingPoint;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startingPoint=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startingPoint;
}

int StartingNode(Node* head){
    Node* fast=head;
    Node* slow=head;
    Node* entry=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return slow->data;
        }
    }
    return -1;
}

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        break;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Insert(head, val);
    }

    createcycle(head,4);
    int ans=StartingNode(head);
    if(ans==-1)
        cout<<"There is a No Cycle"<<endl;
    else
        cout<<ans<<" ";
    return 0;
}