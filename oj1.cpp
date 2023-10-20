#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    int *data_input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        data_input[i] = x;
    }
    bool flag = false;
    do
    {
        flag = false;
        for(int i = 0; i < n; i++)
        {
            if (data_input[i] == -2) continue;
            else{
                int j = 0;
                do j++;
                while (i + j < n && data_input[i + j] == -2);
                if (data_input[i + j] - data_input[i] == 2)
                {
                    data_input[i] = -2;
                    data_input[i+j] = -2;
                    flag = true;
                }
            }
        }
    } while(flag);
    for (int i = 0; i < n; i++)
        if (data_input[i] != -2) {cout << "false" << endl; return 0;}
    cout << "true" << endl;
    return 0;
}