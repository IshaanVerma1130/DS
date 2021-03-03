#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int data;
};

class DoublyLL
{
public:
    Node *head;
    Node *tail;

    DoublyLL(Node *start)
    {
        head = start;
        tail = NULL;
    }

    Node *returnHead()
    {
        return head;
    }

    void insertBack(int val)
    {
        Node *newNode = new Node;
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->prev = NULL;
            tail = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void traverse()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

Node *split(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    fast = slow->next;
    slow->next = NULL;
    return fast;
}

Node *merge(Node *first, Node *second)
{
    if (!first)
    {
        return second;
    }

    if (!second)
    {
        return first;
    }

    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }

    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

int main()
{
    int n;
    cin >> n;

    Node *head = NULL;

    DoublyLL DLL(head);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        DLL.insertBack(x);
    }

    head = DLL.returnHead();
    head = mergeSort(head);
    DLL.head = head;
    DLL.traverse();
}