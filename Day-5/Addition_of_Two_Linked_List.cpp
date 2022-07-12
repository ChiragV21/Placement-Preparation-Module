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

//Addition of Two Linked List

Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* dummy=new Node(-1);
        Node* ptr=dummy;
        Node* ptr1=l1;
        Node* ptr2=l2;
        int carry=0;
        while(ptr1!=NULL or ptr2!=NULL or carry){
            int sum=0;
            if(ptr1!=NULL){
                sum+=ptr1->data;
                ptr1=ptr1->next;
            }
            
            if(ptr2!=NULL){
                sum+=ptr2->data;
                ptr2=ptr2->next;
            }
            
            sum+=carry;
            carry=sum/10;
            Node* n=new Node(sum%10);
            ptr->next=n;
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
    Node *head1 = NULL;
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
    
    //Display(head);
    Node* ans=addTwoNumbers(head,head1);
    Display(ans);
    return 0;
}