#include <iostream>
using namespace std;


long long int Gcd(int a, int b)
{
	return !b ? a : Gcd(b, a % b);
}
 
long long int Lcm(int a, int b)
{
	return a / Gcd(a, b) * b;
}

int main()
{
    int t;
    cin >> t;
    long long int *res = new long long int[t];
    for (int i = 0; i < t; i++)
    {
        long long int n,x,y;
        cin >> n >> x >> y;
        long long int x_nums = n / x;
        long long int y_nums = n / y;
        long long int xy_nums = n / Lcm(x, y);
        x_nums -= xy_nums;
        y_nums -= xy_nums;
        long long int result = 0;
        for (long long int j = 0; j < x_nums; j++)
        {
            result += (n - j);
        }
        for (long long int q = 1; q <= y_nums; q++)
        {
            result -= q;
        }
        res[i] = result;
    }
    for (int i = 0; i < t; i++) cout << res[i] << endl;
    return 0;
}