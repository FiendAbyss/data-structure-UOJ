#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll N, M;
    cin >> N >> M;
    ll *Hi = new ll[N];
    ll max_H = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> Hi[i];
        max_H = max(max_H, Hi[i]);
    }
    ll lower_bound = 0, upper_bound = max_H, mid, sum_left = 0;
    mid = (lower_bound + upper_bound) / 2;
    for (ll i = 0; i < N; i++)
        sum_left += max((ll)0, Hi[i] - mid);
    while (lower_bound < upper_bound - 1)
    {
        //cout << lower_bound << " " << upper_bound << " " << mid << " " << sum_left << endl;
        if (sum_left >= M)
            lower_bound = mid;
        else
            upper_bound = mid;
        mid = (lower_bound + upper_bound) / 2;
        sum_left = 0;
        for (ll i = 0; i < N; i++)
            sum_left += max((ll)0, Hi[i] - mid);
    }
    cout << mid << endl;
    return 0;
}