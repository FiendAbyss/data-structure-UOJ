#include <iostream>
#include <vector>
using namespace std;

class Polynomial
{
    friend Polynomial add(const Polynomial &p1, const Polynomial &p2); // ����ʽ���
    friend Polynomial derivate(const Polynomial &p); // ��, ���� 1 + 2x + 3x^2 + 4x^3 �ĵ���Ϊ 2 + 6x + 12x^2

public:
    Polynomial() {}

    explicit Polynomial(const vector<int> &coefficients); 
    Polynomial(const Polynomial &other);

public:
    void output() const; 

public:
    int operator()(int x) 
    {
        int res = 0;
        for (size_t i = 0; i < coefficients_.size(); i++)
        {
            res += coefficients_[i] * pow(x, coefficients_.size() - i - 1); 
        }
        return res;
    };
    Polynomial& operator + (const int x) 
    {
        vector<int> add_res = coefficients_;
        add_res[add_res.size() - 1] += x;
        Polynomial* res = new Polynomial(add_res);
        return *res;
    }

private:
    vector<int> coefficients_; 
};
