#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n, prime, m;
    cin >> n >> prime >> m;
    int *a = new int[n];
    int sum_search_success = 0;
    int sum_search_failed = 0;
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        int y = x % prime;
        while (a[y] != 0)
        {
            y++;
            if (y == n)
                y = 0;
            sum_search_success++;
        }
        a[y] = x;
        sum_search_success++;
    }
    for (int i = 0; i < prime; ++i)
    {
        int num = 1;
        int x = i;
        while (a[x] != 0)
        {
            num++;
            x++;
            if (x == n)
                x = 0;
            if (x == i)
            {
                num = 0;
                break;
            }
        }
        sum_search_failed += num;
    }
    cout << fixed << setprecision(3) << (double)sum_search_success / m << ' ' << (double)sum_search_failed / prime << endl;
    return 0;
}
