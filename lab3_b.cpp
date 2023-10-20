#include <iostream>
using namespace std;

struct node
{ 
    int data;
    struct node *prior;
    struct node *next;
    void pop()
    {
        this->prior->next = this->next;
        this->next->prior = this->prior;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    node *po;
    node *head = new node;
    head->data = 1;
    if (n == 1)
    {
        head->next = head;
        head->prior = head;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i > 1 && i < n)
        {
            node *p_temp = new node;
            p_temp->data = i;
            po->next = p_temp;
            p_temp->prior = po;
            po = p_temp;
        }
        else if (i == 1)
        {
            po = head;
        }
        else
        {
            node *p_temp = new node;
            p_temp->data = i;
            po->next = p_temp;
            p_temp->prior = po;
            p_temp->next = head;
            head->prior = p_temp;
        }
    }


    bool flag_is_forward = true;
    po = head;
    node *temp;
    int count = 1;
    while (po->next != po)
    {
        while (count < m)
        {
            if (flag_is_forward) po = po->next;
            else po = po->prior;
            count++;
        }
        cout << po->data << " ";
        temp = po;
        if (po->data % k == 0) flag_is_forward = 1 - flag_is_forward;
        if (flag_is_forward) po = po->next;
        else po = po->prior;
        temp->pop();
        count = 1;
    }
    cout << po->data << endl;
    return 0;
}