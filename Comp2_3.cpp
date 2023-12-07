#include <bits/stdc++.h>
using namespace std;

struct Node //树的结点
{
    int data;
    Node *leftchild;
    Node *rightchild;
    Node(int d) : leftchild(nullptr), rightchild(nullptr), data(d) {}
};

int N;
vector<int> post;
vector<int> middle;

Node *head;

void makedata(Node *&root, int midleft, int midright, int pleft, int pright)
{
    if (midleft > midright || pleft > pright)
    {
        root = nullptr;
        return;
    }
    int x = post[pleft];
    int mid = midleft;
    while (mid <= midright)
    {
        if (middle[mid] == x)
        {
            break;
        }
        mid++;
    }
    int leftchild_size = mid - midleft;
    int rightchild_size = midright - mid;
    root = new Node(x);
    makedata(root->leftchild, midleft, mid - 1, pleft + 1, pleft + leftchild_size);
    makedata(root->rightchild, mid + 1, midright, pleft + leftchild_size + 1, pright);
}

vector<int> ans;

int maxdepth = 0;

void vision(Node *root, int depth)
{
    if (depth > maxdepth)
    {
        ans.push_back(root->data);
        maxdepth = depth;
    }
    if (root->leftchild)
        vision(root->leftchild, depth + 1);
    if (root->rightchild)
        vision(root->rightchild, depth + 1);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        post.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        middle.push_back(temp);
    }
    makedata(head, 0, N - 1, 0, N - 1);
    vision(head, 1);
    int asz = ans.size();
    for (int i = 0; i < asz; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}