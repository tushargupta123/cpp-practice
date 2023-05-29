#include <iostream>
#include<queue>
#include<stack>
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

void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

void iterativeInorderTraversal(Node *root){
    Node *curr = root;
    stack<Node *> s;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return ((max(height(root->left), height(root->right))) + 1);
    }
}

void kthNode(Node *root,int k){
    if(root == NULL)    return;
    if(k == 0){
        cout<<root->key<<" ";
    }else{
        kthNode(root->left,k-1);
        kthNode(root->right,k-1);
    }
}

void breadthTraversal(Node *root){
    if(root == NULL)    return;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        Node *curr = q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
    }
}

void breadthTraversalLineByLine(Node *root){
    if(root == NULL)    return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(q.size() >1){
        Node *curr = q.front();
        q.pop();
        if(curr == NULL){       // whenever we see NULL we print a new line and also push another NULL bcs children of previous node has been already pushed to queue.
            cout<<endl;
            q.push(NULL);
            continue;
        }
        cout<<curr->key<<" ";
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
    }
}

int size(Node *root){
    if(root == NULL)    return 0;
    return 1+size(root->left)+size(root->right);
}

int getMax(Node *root){
    if(root == NULL)    return -1;
    return max(root->key,max(getMax(root->left),getMax(root->right)));
}

int maxLevel = 0;
void leftView(Node *root,int level = 1){
    if(root == NULL)    return;
    if(maxLevel<level){
        cout<<root->key<<" ";
        maxLevel = level;
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}

bool childrenSumProperty(Node *root){   // the sum of every children nodes mus be equal to the parent node
    if(root==NULL)  return true;
    if(root->left==NULL && root->right==NULL) return true;
    int sum=0;
    if(root->left!=NULL){
        sum+=root->left->key;
    }
    if(root->right!=NULL){
        sum+=root->right->key;
    }
    return ((root->key == sum) && childrenSumProperty(root->right) && childrenSumProperty(root->left));
}

int balancedTree(Node *root){        // difference bw height of both side at every node should be less than or equal to 1.
    if(root==NULL)  return true;
    int lh = balancedTree(root->left);
    if(lh==-1) return -1;
    int rh = balancedTree(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh) > 1)  return -1;
    else return max(lh, rh)+1;
}

int maxWidth(Node *root){
    if(root == NULL)    return 0;
    queue<Node *> q;
    q.push(root);
    int res = 0;
    while(q.empty() == false){
        int count  = q.size();
        res = max(res, count);
        for(int i=0; i<count; i++){
        Node *curr = q.front();
        q.pop();
        if(curr->left !=NULL){
            q.push(curr->left);
        }
        if(curr->right !=NULL){
            q.push(curr->right);
        }
        }
    }
    return res;
}

void spiralTraversal(Node *root){
    if(root == NULL)    return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node *temp = s1.top();
            s1.pop();
            cout<<temp->key<<" ";
            if(temp->right){
            s2.push(temp->right);
            }
            if(temp->left){
            s2.push(temp->left);
            }
        }
        while(!s2.empty()){
            Node *temp = s2.top();
            s2.pop();
            cout<<temp->key<<" ";
            if(temp->left){
            s2.push(temp->left);
            }
            if(temp->right){
            s2.push(temp->right);
            }
        }
    }
}

int diameter = 0;           // diameter is longest distance between two leaf nodes
int calcHeigth(Node *root){              // this function normally calculates the heigth but side by side calculates diameter also.
    if(root == NULL) return 0;
    int lh = calcHeigth(root->left);
    int rh = calcHeigth(root->right);
    diameter = max(diameter,lh+rh+1);       // fromula for diameter = leftHeigth + rightHeigth + 1.
    return 1+max(lh,rh);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->right = new Node(5);
    root->left->left = new Node(3);
    root->right->right = new Node(6);
    inorderTraversal(root);
    cout << endl<< height(root)<<endl;
    kthNode(root,1);
    cout<<endl;
    breadthTraversal(root);
    cout<<endl;
    breadthTraversalLineByLine(root);
    cout<<endl<<size(root);
    cout<<endl<<getMax(root)<<endl;
    leftView(root);
    cout<<endl<<childrenSumProperty(root)<<endl;
    if(balancedTree(root)==-1){
        cout<<"No"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    cout<<maxWidth(root)<<endl;
    spiralTraversal(root);
    calcHeigth(root);
    cout<<endl<<diameter;
}