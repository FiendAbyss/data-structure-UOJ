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

int n;
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
int k;
void dfs(Node *&node, vector<int> &people);
int main()
{
    cin >> n >> k;
    Node *root;
    Create_Level(root);
    vector<int> people(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }
    dfs(root, people);
    cout << root->cost << endl;
    return 0;
}

void dfs(Node *&node, vector<int> &people)
{
    node->cost = 0;
    node->people_sum = people[node->data];
    if (node->leftchild != NULL)
    {
        dfs(node->leftchild, people);
        node->people_sum += node->leftchild->people_sum;
        node->cost = node->leftchild->cost + node->leftchild->people_sum / k + (node->leftchild->people_sum % k == 0 ? 0 : 1);
    }
    if (node->rightchild != NULL)
    {
        dfs(node->rightchild, people);
        node->people_sum += node->rightchild->people_sum;
        node->cost += node->rightchild->cost + node->rightchild->people_sum / k + (node->rightchild->people_sum % k == 0 ? 0 : 1);
    }
    return;
}