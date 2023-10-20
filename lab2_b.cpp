#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int *res = new int[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        int hour;
        cin >> n;
        int *rec = new int[n];
        int *rec_rolling = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> hour;
            if (hour >= 8)
            {
                rec[j] = 1;
                rec_rolling[j] = 1;
            }
            else{
                rec[j] = -1;
                rec_rolling[j] = 1;
            }
        }
    
        int max_num = rec_rolling[0];
        for (int q = 0; q < n; q++)
        {
            int sum = rec[q];
            int days = 1;
            while(q + days < n)
            {
                sum += rec[q + days];
                rec_rolling[q]++;
                days++;
                if (sum > 0)
                {
                    if (rec_rolling[q] > max_num) max_num = rec_rolling[q];
                }
            }
        }
        res[i] = max_num;
    }
    for (int i = 0; i < t; i++) cout << res[i] << endl;
    return 0;
}