#include <bits/stdc++.h> 
Node* merge2LinkedList(Node* a,Node* b){
    if(a==NULL)
        return b;
    if(b==NULL)
        return b;
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(a!=NULL and b!=NULL){
        if(a->data<b->data){
            temp->child=a;
            temp=a;
            a=a->child;
        }
        else{
            temp->child=b;
            temp=b;
            b=b->child;
        }
    }
    
    while(a!=NULL){
        temp->child=a;
        temp=a;
        a=a->child;
    }
    
    while(b!=NULL){
        temp->child=b;
        temp=b;
        b=b->child;
    }
    return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL or head->next==NULL){
        return head;
    }
    Node* curr=head;
    curr->next=flattenLinkedList(curr->next);
    curr=merge2LinkedList(curr,curr->next);
    return curr;
}
