#include <bits/stdc++.h>
using namespace std;
// Linked List-Merge Two Linked List
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

//Merge 2 sorted List

Node* MergeList(Node* l1,Node* l2){
    Node* ptr1=l1;
    Node* ptr2=l2;
    Node* dummy=new Node(-1);
    Node* ptr=dummy;
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr->next=ptr1;
            ptr1=ptr1->next;
        }
        
        else{
            ptr->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr=ptr->next;
    }
    
    while(ptr1!=NULL){
        ptr->next=ptr1;
        ptr1=ptr1->next;
        ptr=ptr->next;
    }
    
    while(ptr2!=NULL){
        ptr->next=ptr2;
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
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
    cout<<endl;
}

int main()
{
    Node *head = NULL;
    Node* head1=NULL;
    int n,m;
    cin >> n>>m;
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
    Node* merge=MergeList(head,head1);
    Display(merge);
    return 0;
}