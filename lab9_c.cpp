#include <bits/stdc++.h>
using namespace std;
namespace hyx
{
    template <class U, class Container = vector<U>, class Compare = less<U>>

    class priority_queue
    {
        template <class T>
        class less
        {
        public:
            bool operator()(const T &l, const T &r)
            {
                return l < r;
            }
        };
        template <class T>
        class greater
        {
        public:
            bool operator()(const T &l, const T &r)
            {
                return l > r;
            }
        };

    public:
        priority_queue()
        {
        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _con.push_back(*first);
                ++first;
            }
            // ½¨¶Ñ
            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
            {
                adjust_down(i);
            }
        }

        void adjust_up(size_t child)
        {
            Compare com;
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (com(_con[child], _con[parent]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }

        void adjust_down(size_t parent)
        {
            Compare com;
            size_t child = parent * 2 + 1;
            while (child < _con.size())
            {
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
                    ++child;
                if (com(_con[child], _con[parent]))
                {
                    swap(_con[child], _con[parent]);
                    parent = child;
                    child = 2 * parent + 1;
                }
                else
                    break;
            }
        }

        void push(const U &x)
        {
            _con.push_back(x);
            adjust_up(_con.size() - 1);
        }

        void pop()
        {
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            adjust_down(0);
        }
        const U &top()
        {
            return _con[0];
        }
        bool empty() const
        {
            return _con.empty();
        }
        size_t size() const
        {
            return _con.size();
        }

    private:
        Container _con;
    };
}

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> huf;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        huf.push(x);
    }
    int res = 0;
    while (huf.size() > 1)
    {
        int a = huf.top();
        huf.pop();
        int b = huf.top();
        huf.pop();
        huf.push(a + b);
        res += a + b;
    }
    cout << res << endl;
}