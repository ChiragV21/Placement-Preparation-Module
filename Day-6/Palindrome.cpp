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

// Naive Approach
bool isPalindrome(Node *head)
{
    vector<int> res;
    Node *temp = head;
    while (temp)
    {
        res.push_back(temp->data);
        temp = temp->next;
    }

    int n = res.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (res[i] != res[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool OptimisedPalindrome(Node* head){
    Node* fast=head;
    Node* slow=head;
    //calculate mid, if even first mid
    while(fast->next!=NULL and fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=Reverse(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(head->data!=slow->data)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}

void Display(Node *&head)
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
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Insert(head, val);
    }

    if(OptimisedPalindrome(head))
        cout<<"Palindrome List"<<endl;
    else    
        cout<<"Not a Palindrome"<<endl;
    return 0;
}