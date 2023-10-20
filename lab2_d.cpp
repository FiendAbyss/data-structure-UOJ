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
        int *map = new int[2 * n + 2]();
        for (int j = 0; j < n; j++)
        {
            cin >> hour;
            if (hour >= 8)
            {
                rec[j] = 1;
            }
            else{
                rec[j] = -1;
            }
        }
        int sum = 0;
        int len = 0;
        for (int j = 0; j < n; j++)
        {
            sum += rec[j];
            if (j - map[n + sum - 1] > len && (map[n + sum - 1] != 0 || sum - 1 == rec[0])) len = j - map[n + sum - 1];
            if (map[n + sum] == 0 && sum != rec[0]) map[n + sum] = j;
        }
        if (sum > 0) len = n;
        res[i] = len;
    }
    for (int i = 0; i < t; i++) cout << res[i] << endl;
    return 0;
}