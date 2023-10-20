#include <iostream>

using namespace std;

class Stack 
{
	public:
		Stack(int size);// constructor
		~Stack();
		bool IsEmpty() { return top == -1; }
		bool IsFull() { return top == maxTop; }
		char Top();
		void Push(const char x);
		char Pop();
		void DisplayStack();
	private:
		int maxTop;// max stack size = size -1
		int top;// current top of stack
		char* values;// element array
};

Stack::Stack(int size) 
{
	maxTop = size -1;
	values = new char[size];
	top = -1;
}

Stack::~Stack() 
{ 
	delete[] values; 
}
		
void Stack::Push(const char x) 
{
	if (IsFull())
		cout<< "Error: the stack is full." << endl;
	else 
		values[++top] = x;
}

char Stack::Pop() 
{
	if (IsEmpty()) 
	{
		cout<< "Error: the stack is empty." << endl;
		return -1;
	}
	else 
	{
		return values[top--];
	}
}

char Stack::Top() 
{
	if (IsEmpty()) 
	{
		cout<< "Error: the stack is empty." << endl;
		return -1;
	}
	else
		return values[top];
}

void Stack::DisplayStack() 
{
	cout<< "top -->";
	for (int i= top; i>= 0; i--) 
		cout<< "\t|\t" << values[i] << "\t|" << endl;
	cout<< "\t|---------------|" << endl;
}

int main(void) 
{
	int n;
    cin >> n;
    Stack input(n);
    int *res = new int[n];
    char x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x == '(' || input.IsEmpty())
        {
            input.Push(x);
            res[i] = 0;
        }
        else if (input.Top() == '(')
        {
            input.Pop();
            int j = i;
            res[j] = 1;
            while (res[j] > 0) j--;
            res[j] = 1;
        }
        else
        {
            input.Push(x);
            res[i] = 0;
        }
    }
    int sum = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (res[i] == 1) sum++;
        else sum = 0;
        if (sum > num) num = sum;
    }
    cout << num << endl;
    return 0;
}


