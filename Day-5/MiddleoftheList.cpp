#include<bits/stdc++.h>
using namespace std;
//Linked List-Reverse Linked List
class Node{
    public:
        int data;
        Node* next;
        
        Node(int val){
            data=val;
            next=NULL;
        }
};

void Insert(Node* &head,int val){
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

//Naive Approach: Calculate Length of a Linked and print the middle Element
int Length(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

Node *findMiddle(Node *head) {
    int n=Length(head);    //Length of the Linked List
    Node* temp=head;
    for(int i=0;i<n/2;i++){
        temp=temp->next;
    }
    return temp;
}

//Optimise
Node *FindMiddle(Node *head) {
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

void Display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        Insert(head,num);
    }
    
    Node* middle=FindMiddle(head);
    Display(middle);
    return 0;
}