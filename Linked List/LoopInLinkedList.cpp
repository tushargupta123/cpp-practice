#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// DETECTION

// using hashing        => O(n) time + 0(n)auxiliary space
bool checkLoop(Node *head)
{
    if (head == NULL)
        return false;
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}

// using floyd cycle detection algorithm        => O(n) time + O(1)auxiliary space
bool isLoop(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}
// concept
// let distance bw slow and fast be k. at the when slow and fast both has entered the loop .now as fast move 2 steps and slow moves 1 step hence the distance
// will keep on increasing by one in each step and let size of loop be n . then there will be some time when k+1+1+1 will become equal to n and at that time
// slow and fast will be at same position .so hence it finds a loop.

// REMOVAL
void removeLoop(Node *head)
{
    if (head == NULL)
        return;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (slow != fast)
        return;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
// concept
// if they meet again at same speed then it will the starting of loop . and we want to remove loop so we have to be at end of loop so we compare slow->next and fast->next
//  and not slow and fast bcs at that point we will be in center of ll.

// Length of loop
int loopLength(Node *head)
{
    if (head == NULL)
        return 0;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    int res = 1;
    fast = fast->next;
    while (slow != fast)
    {
        fast = fast->next;
        res++;
    }
    return res;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = head->next; // loop
    if (isLoop(head))
    {
        cout << "Loop" << endl;
        cout << loopLength(head) << endl;
        // removeLoop(head);
    }
    else
        cout << "No loop";
    // printList(head);
}