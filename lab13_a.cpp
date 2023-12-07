#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *leftchild;
    Node *rightchild;
    int height;
    bool avl_balance;
    bool is_binary_search_tree;
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

void calculate_height(Node *&node)
{
    if (node == NULL)
        return;
    else
    {
        calculate_height(node->leftchild);
        calculate_height(node->rightchild);
        if (node->leftchild == NULL && node->rightchild == NULL)
            node->height = 0;
        else if (node->leftchild == NULL)
            node->height = node->rightchild->height + 1;
        else if (node->rightchild == NULL)
            node->height = node->leftchild->height + 1;
        else
            node->height = max(node->leftchild->height, node->rightchild->height) + 1;
    }
}

void calculate_is_binary_search_tree(Node *&node)
{
    if (node == NULL)
        return;
    else
    {
        calculate_is_binary_search_tree(node->leftchild);
        calculate_is_binary_search_tree(node->rightchild);
        if (node->leftchild == NULL && node->rightchild == NULL)
            node->is_binary_search_tree = true;
        else if (node->leftchild == NULL)
        {
            if (node->rightchild->data > node->data)
                node->is_binary_search_tree = true;
            else
                node->is_binary_search_tree = false;
        }
        else if (node->rightchild == NULL)
        {
            if (node->leftchild->data < node->data)
                node->is_binary_search_tree = true;
            else
                node->is_binary_search_tree = false;
        }
        else
        {
            if (node->leftchild->data < node->data && node->rightchild->data > node->data)
                node->is_binary_search_tree = true;
            else
                node->is_binary_search_tree = false;
        }
    }
}

void calculate_avl_balance(Node *&node)
{
    if (node == NULL)
        return;
    else
    {
        calculate_avl_balance(node->leftchild);
        calculate_avl_balance(node->rightchild);
        if (node->leftchild == NULL && node->rightchild == NULL)
            node->avl_balance = true;
        else if (node->leftchild == NULL)
        {
            if (node->rightchild->height == 0)
                node->avl_balance = true;
            else
                node->avl_balance = false;
        }
        else if (node->rightchild == NULL)
        {
            if (node->leftchild->height == 0)
                node->avl_balance = true;
            else
                node->avl_balance = false;
        }
        else
        {
            if (abs(node->leftchild->height - node->rightchild->height) <= 1 && node->leftchild->avl_balance && node->rightchild->avl_balance)
                node->avl_balance = true;
            else
                node->avl_balance = false;
        }
        if (node->avl_balance && node->is_binary_search_tree)
            node->avl_balance = true;
        else
            node->avl_balance = false;
    }
}

int main()
{
    int n;
    cin >> n;
    Node *root;
    Create_Level(root);
    calculate_height(root);
    calculate_is_binary_search_tree(root);
    calculate_avl_balance(root);
    cout << (root->avl_balance ? "yes" : "no") << endl;
    return 0;
}