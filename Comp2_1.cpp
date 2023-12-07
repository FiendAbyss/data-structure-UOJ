#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *leftchild;
    Node *rightchild;

    int s; //子树权值和

    Node() : leftchild(nullptr), rightchild(nullptr), s(-1) {}
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

void cal_S(Node *root) //计算以root为根节点的子树的权值和
{
    root->s = root->data;
    if (root->leftchild != NULL)
    {
        cal_S(root->leftchild);
        root->s += root->leftchild->s;
    }
    if (root->rightchild != NULL)
    {
        cal_S(root->rightchild);
        root->s += root->rightchild->s;
    }
}

void make_data(int arr[], Node* root)
{
    arr[root->s]++;
    if (root->leftchild != NULL)
    {
        make_data(arr, root->leftchild);
    }
    if (root->rightchild != NULL)
    {
        make_data(arr, root->rightchild);
    }
}

int main()
{
    int n;
    cin >> n;
    Node *root;
    Create_Level(root);
    cal_S(root);
    int *arr = new int[root->s + 1];
    for (int i = 1; i <= root->s; i++)
    {
        arr[i] = 0;
    }
    make_data(arr, root);
    int num_c = 0;
    int res;
    for (int i = 1; i <= root->s; i++)
    {
        if (arr[i] > num_c)
        {
            res = i;
            num_c = arr[i];
        }
    }
    cout << res << " " << num_c << endl;
}
