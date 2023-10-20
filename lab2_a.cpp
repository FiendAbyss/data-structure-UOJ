#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int *Arr_in = new int[n];
        int p;
        int num_in = 0;
        int head = 0;
        int tail = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> p;
            if (p == 1)
                head++;
            else if (p == 0)
                tail++;
            else
            {
                Arr_in[num_in] = p;
                num_in++;
            }
        }

        while (head)
        {
            cout << "1 ";
            head--;
        }

        for (int q = 0; q < num_in; q++)
        {
            cout << Arr_in[q] << " ";
        }

        while (tail)
        {
            cout << "0 ";
            tail--;
        }
    }
    return 0;
}