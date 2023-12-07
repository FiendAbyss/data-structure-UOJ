#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int people_sum;
    int cost;
    Node *leftchild;
    Node *rightchild;
    Node() : people_sum(0), cost(0), leftchild(nullptr), rightchild(nullptr) {}
};

void Create_Node(Node *&t, int x)
{ 
    t = new Node;
    t->data = x;
    t->leftchild = NULL;
    t->rightchild = NULL;
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

Node* find_node(Node *&node, int x)
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

int main()
{
    int n, x;
    cin >> n >> x;
    Node *root;
    Create_Level(root);
    if (x == 1 && size_of_tree(root->leftchild) == size_of_tree(root->rightchild))
    {
        cout << "false" << endl;
    }
    else if (x == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        Node *node = find_node(root, x);
        if (size_of_tree(node) < (n + 1) / 2 || size_of_tree(node->leftchild) > (n + 1) / 2 || size_of_tree(node->rightchild) > (n + 1) / 2)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}