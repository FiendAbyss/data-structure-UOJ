#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *leftchild;
    Node *rightchild;
    bool _is_hospital;
    bool _has_hospital;
};

void Create_Node(Node *&t, int x)
{ 
    t = new Node;
    t->data = x;
    t->leftchild = NULL;
    t->rightchild = NULL;
    t->_is_hospital = false;
    t->_has_hospital = false;
}

void Create_Level(Node *&t) 
{
    queue<Node *> q;
    int x;
    cin >> x;
    if (x != -1)
    {
        Create_Node(t, x);
        q.push(t);
    }
    while (!q.empty())
    {
        Node *s = q.front();
        cin >> x;
        if (x != -1)
        {
            Create_Node(s->leftchild, x);
            q.push(s->leftchild);
        }
        cin >> x;
        if (x != -1)
        {
            Create_Node(s->rightchild, x);
            q.push(s->rightchild);
        }
        q.pop();
    }
}

int size_of_tree(Node *&node) 
{
    if (node == NULL)
        return 0;
    else
        return size_of_tree(node->leftchild) + size_of_tree(node->rightchild) + 1;
}

Node *find_node(Node *&node, int x) 
{
    if (node == NULL)
        return NULL;
    else if (node->data == x)
        return node;
    else
    {
        Node *left = find_node(node->leftchild, x);
        Node *right = find_node(node->rightchild, x);
        if (left != NULL)
            return left;
        else if (right != NULL)
            return right;
        else
            return NULL;
    }
}

int num;
void dfs(Node *node) 
{
    if (node == NULL)
        return;
    dfs(node->leftchild);
    dfs(node->rightchild);
    if ((node->leftchild != NULL && node->leftchild->_is_hospital) || (node->rightchild != NULL && node->rightchild->_is_hospital))
    {
        node->_has_hospital = true;
    }
    if ((node->leftchild != NULL && !node->leftchild->_has_hospital) || (node->rightchild != NULL && !node->rightchild->_has_hospital))
    {
        num++;
        node->_is_hospital = true;
        node->_has_hospital = true;
    }
}

int main()
{
    int n;
    cin >> n;
    Node *root;
    Create_Level(root);
    num = 0;
    dfs(root);
    if (!root->_has_hospital)
        num++;
    cout << num << endl;
    return 0;
}