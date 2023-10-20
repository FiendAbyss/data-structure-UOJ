#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node* prior;
    struct node* next;
    void pop()
    {
        if (this->prior != NULL)
            this->prior->next = this->next;
        if (this->next != NULL)
            this->next->prior = this->prior;
    }
};

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    node* po;
    char* poss = new char[m];

    node* head = new node;
    if (n == 1)
    {
        head->next = head;
        head->prior = head;
    }
    po = head;
    char x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (i > 1 && i < n)
        {
            node* p_temp = new node;
            p_temp->data = x;
            po->next = p_temp;
            p_temp->prior = po;
            po = p_temp;
        }
        else if (i == 1)
        {    
            head->data = x;
            po = head;
        }
        else
        {
            node* p_temp = new node;
            p_temp->data = x;
            po->next = p_temp;
            p_temp->prior = po;
            p_temp->next = NULL;
            head->prior = NULL;
        }
    }
    po = head;
    while (p > 1)
    {
        po = po->next;
        p--;
    }


    node* temp;
    for (int i = 0; i < m; i++)
    {
        cin >> poss[i];
    }
    for (int i = 0; i < m; ++i)
    {
        if (poss[i] == 'R')
        {
            po = po->next;
        }
        if (poss[i] == 'L')
        {
            po = po->prior;
        }
        if (poss[i] == 'D')
        {
            int count = 1;
            if (po->data == '(')
            {
                while (count)
                {
                    temp = po->next;
                    if (temp->data == ')')
                    {
                        count--;
                        temp->pop();
                    }
                    else
                    {
                        count++;
                        temp->pop();
                    }
                }
            }
            else
            {
                while (count)
                {
                    temp = po->prior;
                    if (temp->data == '(')
                    {
                        count--;
                        temp->pop();
                    }
                    else
                    {
                        count++;
                        temp->pop();
                    }
                }
            }

            if (po->next != NULL)
            {
                po = po->next;
                po->prior->pop();
            }
            else
            {
                po = po->prior;
                po->next->pop();
            }

        }
    }

    while (po->prior != NULL)
        po = po->prior;
    while (po != NULL)
    {
        cout << po->data;
        po = po->next;
    }
    cout << endl;
    return 0;
}