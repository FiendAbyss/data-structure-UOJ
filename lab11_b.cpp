#include <bits/stdc++.h>
using namespace std;

#ifndef MYQUEUE
#define MYQUEUE
#include <cassert>

template <typename T>
class Deque
{

    struct Node
    {
        T val;
        Node *prev;
        Node *next;
    };

    Node *head;
    size_t _size;

public:
    Deque()
    {
        head = new Node();
        head->prev = head;
        head->next = head;
        _size = 0;
    }

    ~Deque()
    {
        Node *pt = head->next;
        while (pt != head)
        {
            pt = pt->next;
            delete pt->prev;
        }
        delete pt;
        head = nullptr;
    }

    void push_front(T v)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->prev = head;
        temp->next = head->next;
        head->next = temp;
        temp->next->prev = temp;
        _size++;
    }

    void push_back(T v)
    {
        Node *temp = new Node();
        temp->val = v;
        temp->next = head;
        temp->prev = head->prev;
        head->prev = temp;
        temp->prev->next = temp;
        _size++;
    }

    T front()
    {
        assert(_size > 0);
        return head->next->val;
    }

    T back()
    {
        assert(_size > 0);
        return head->prev->val;
    }

    void pop_front()
    {
        assert(_size > 0);
        Node *old = head->next;
        head->next = old->next;
        head->next->prev = head;
        delete old;
        _size--;
    }

    void pop_back()
    {
        assert(_size > 0);
        Node *old = head->prev;
        head->prev = old->prev;
        head->prev->next = head;
        delete old;
        _size--;
    }

    bool empty()
    {
        return _size == 0;
    }

    size_t size()
    {
        return _size;
    }
};

#endif

struct node
{
    int data;
    node *left;
    node *right;
    node *parent;
    void insert(int x) // 插入一个节点
    {
        if (x < data)
        {
            if (left == NULL)
            {
                left = new node;
                left->data = x;
                left->left = NULL;
                left->right = NULL;
                left->parent = this;
            }
            else
                left->insert(x);
        }
        else
        {
            if (right == NULL)
            {
                right = new node;
                right->data = x;
                right->left = NULL;
                right->right = NULL;
                right->parent = this;
            }
            else
                right->insert(x);
        }
    }
    node *search_max_data() // 返回以当前节点为根的子树中值最大的节点
    {
        if (right == NULL)
            return this;
        else 
            return right->search_max_data();
    }
    void remove(int x) // 删除一个节点
    {
        if (x < data)
        {
            if (left != NULL)
                left->remove(x);
        }
        else if (x > data)
        {
            if (right != NULL)
                right->remove(x);
        }
        else
        {
            if (left == NULL && right == NULL)
            {
                if (parent->left == this)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                delete this;
            }
            else if (left == NULL)
            {
                if (parent->left == this)
                {
                    parent->left = right;
                    right->parent = parent;
                }
                else
                {
                    parent->right = right;
                    right->parent = parent;
                }
                delete this;
            }
            else if (right == NULL)
            {
                if (parent->left == this)
                {
                    parent->left = left;
                    left->parent = parent;
                }
                else
                {
                    parent->right = left;
                    left->parent = parent;
                }
                delete this;
            }
            else // 替换成左子树中值最大的节点
            {
                node *temp = left->search_max_data();
                data = temp->data;
                temp->remove(temp->data);
            }
        }
    }
};
int main()
{
    int len_N, len_M;
    cin >> len_N >> len_M;
    int *N = new int[len_N];
    int *M = new int[len_M];
    for (int i = 0; i < len_N; i++)
        cin >> N[i];
    for (int i = 0; i < len_M; i++)
        cin >> M[i];
    // 建立二叉搜索树
    node *root = new node;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    root->data = N[0];
    for (int i = 1; i < len_N; ++i)
    {
        root->insert(N[i]);
    }
    // 删除节点
    for (int i = 0; i < len_M; ++i)
    {
        if (root->data != M[i])
            root->remove(M[i]);
        else if (root->left != NULL && root->right != NULL)
        {
            root->data = root->left->search_max_data()->data;
            root->left->remove(root->data);
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
    }
    // 输出（层次遍历）
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
    return 0;
}