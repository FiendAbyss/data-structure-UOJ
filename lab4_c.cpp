#include <iostream>
using namespace std;
template <class T>
class Node {
public:
	T val;
	Node* next;
	Node* prev;
	Node(T x)
	{
		val = x;
		next = NULL;
		prev = NULL;
	}
};
template <class T>
class stack{
	Node<T>* tail;
public:
	stack()
	{
		tail = NULL;
	}
	bool push(T x)
	{
		Node<T>* temp = new Node<T>(x);
		if (tail == NULL)
			tail = temp;
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		return true;
	}
	T pop()
	{
		T i=tail->val;
		if (tail->prev == NULL)
			tail = NULL;
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		return i;
	}
	bool empty()
	{
		return (tail == NULL);
	}
	T top()
	{
		T i = tail->val;
		return i;
	}
};

int main()
{
    int n, x;
    cin >> n;
    int *heights = new int[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        heights[i] = x;
    }
    int maxArea = 0; // 修改初始值为0
    s.push(-1); // 为了方便计算，将-1作为栈的初始值
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && heights[i] < heights[s.top()])
        {
            int tmp = s.top();
            s.pop();
            maxArea = max(maxArea, heights[tmp] * (i - s.top() - 1));
        }
        s.push(i);
    }
    while (s.top() != -1)
    {
        int tmp = s.top();
        s.pop();
        maxArea = max(maxArea, heights[tmp] * (n - s.top() - 1));
    }
    cout << maxArea << endl;
    
    delete[] heights; // 释放内存
    return 0;
}
