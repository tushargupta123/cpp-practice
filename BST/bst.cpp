#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// iterative solution is better than recursive in this case because in recursive solution time complexity is same but space complexity is O(h) becuase we use stack
// to store results of function calls but space complexity of iterative solution is O(1)
bool search(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        else if (root->key > x)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL,
         *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > x)
        {
            curr = curr->left;
        }
        else if (curr->key < x)
        {
            curr = curr->right;
        }
        else
        {
            return root;
        }
    }
    if (parent == NULL)
    {
        return temp;
    }
    else if (parent->key < x)
    {
        parent->right = temp;
    }
    else
    {
        parent->left = temp;
    }
    return root;
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

// for deletion of node we have have three cases :
// 1. if node is leaf node then we delete that node simply and then place NULL in place of it connect to parent node
// 2. if node has only one children then we delete that node and connect parent of that node to children of that node
// 3. if node has both child then we have to search for either closest lower value or higher value then we replace both value and then check again for above cases

// here we have used closest higher value to replace
// to find closest higher value we from parent go to right child and then traverse left of it till we reach end and it will surely be closest higher value.

Node *getSucc(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->key < x)
    {
        root->right = deleteNode(root->right, x);
    }
    else if (root->key > x)
    {
        root->left = deleteNode(root->left, x);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSucc(root);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
}

Node *getFloor(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key > x)
        {
            root = root->left;
        }
        else if (root->key < x)
        {
            res = root;
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    inorderTraversal(root);
    cout << endl
         << search(root, 20);
    root = deleteNode(root, 20);
    cout << endl
         << search(root, 20) << endl;
    inorderTraversal(root);
    root = getFloor(root, 22);
    cout << endl
         << root->key << endl;
}