#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x;
    int max_num = 0;
    deque<int> p;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (p.empty())
        {
            p.push_back(x);
        }
        else
        {
            while (!p.empty() && p.front() >= x)
            {
                p.pop_front();
            }
            p.push_back(x);
            if (p.size() != 1)
            {
                max_num = max(max_num, x - p.front());
            }
        }
    }
    cout << max_num << endl;
}