#include "Polynomial.h"
#include <assert.h>

Polynomial::Polynomial(const vector<int> &coefficients)
{ 
    coefficients_ = coefficients;
}

Polynomial::Polynomial(const Polynomial &other)
{
    this->coefficients_ = other.coefficients_;
}

void Polynomial::output() const
{
    // TODO
    for (size_t i = 0; i < coefficients_.size(); i++)
    {
        if (coefficients_[i])
            cout << coefficients_[i] << '(' << coefficients_.size() - i - 1 << ')' << ' ';
    }
    cout << endl;
}

Polynomial add(const Polynomial &p1, const Polynomial &p2)
{
    // TODO
    vector<int> add_res;
    int l1 = p1.coefficients_.size();
    int l2 = p2.coefficients_.size();
    if (l1 > l2)
    {
        for (int i = 0; i < l1; i++)
        {
            if (i < l1 - l2)
                add_res.push_back(p1.coefficients_[i]);
            else
                add_res.push_back(p1.coefficients_[i] + p2.coefficients_[i + l2 - l1]);
        }
    }
    else
    {
        for (int i = 0; i < l2; i++)
        {
            if (i < l2 - l1)
                add_res.push_back(p2.coefficients_[i]);
            else
                add_res.push_back(p2.coefficients_[i] + p1.coefficients_[i + l1 - l2]);
        }
    }
    return Polynomial(add_res);
}

Polynomial derivate(const Polynomial &p) 
{
    // TODO
    int len = p.coefficients_.size();
    vector<int> add_res(len - 1, 0);
    for (int i = 0; i < len - 1; i++)
    {
        add_res[i] = p.coefficients_[i] * (len - i - 1);
    }
    return Polynomial(add_res);
}

int main()
{
    Polynomial poly({3, 2, 1});
    poly = poly + 2;                    
    poly.output();                       
    int result = poly(2);                
    cout << "P(2) = " << result << endl; 
    return 0;
}