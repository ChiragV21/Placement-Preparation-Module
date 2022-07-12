#include <iostream>
using namespace std;
// Linked List-Detect a Cycle in a Linked List
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

void CreateCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startpoint;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startpoint = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startpoint;
}

bool isCycle(Node *head)
{
    if (head == NULL or head->next == NULL)
        return false;
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        Insert(head, num);
    }

    CreateCycle(head, 2);

    if (isCycle(head))
        cout << "Cycle Present" << endl;
    else
        cout << "Cycle is not Present" << endl;
    return 0;
}