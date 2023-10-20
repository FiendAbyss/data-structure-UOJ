#include <iostream>
#include <deque>
using namespace std;

int main() {
    int x;
    cin >> x;

    for (int l = 0; l < x; l++) {
        int n, k;
        cin >> n >> k;

        int *arr_an = new int[n];
        int *arr_sum = new int[n + 1];
        
        for (int j = 0; j < n; ++j)
        {
            cin >> arr_an[j];
        }
        arr_sum[0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            arr_sum[j] = arr_sum[j - 1] + arr_an[j - 1];
        }

        deque<int> q;
        int res = 1 + n;
        q.push_back(0);
        for(int i = 1; i <= n; i++){
            while(!q.empty() && arr_sum[i] - arr_sum[q.front()] >= k){
                res = min(res, i - q.front());
                q.pop_front();
            }
            while(!q.empty() && arr_sum[i] <= arr_sum[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        if(res == n + 1) res = -1;
        cout << res << endl;
    }

    return 0;
}
