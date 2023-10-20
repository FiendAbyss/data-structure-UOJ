#include <iostream>
#include <math.h>
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

bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '~')
        return true;
    return false; // 否则返回false
}
 
// 获取优先级
int getPriority(char ch) {
    int level = 0; // 优先级
    
    switch(ch) {
        case '(':
            level = 1;
            break;
        case '+':
        case '-':
            level = 2;
            break;
        case '*':
        case '/':
            level = 3;
            break;
        case '^':
            level = 4;
            break;
        case '~':
            level = 5;
            break;
        default:
            break;
    }
    return level;
}
 
// 进行相应的计算
long long int Calculate(char ch, long long int a, long long int b) {
    long long int result = 0;
    
    switch(ch) {
        case '+':
            result = b + a;
            break;
        case '-':
            result = b - a;
            break;
        case '*':
            result = b * a;
            break;
        case '/':
            if(a == 0) {
                cerr << "除数不能为0。\n";
                exit(1); // 强制终结程序
            }
            else
                result = b / a;
            break;
        case '^':
            result = pow(b, a);
        default:
            break;
    } // switch结束
    
    return result; // 返回计算得到的结果
}
 
int main() {
    stack<long long int> mynumbers; // 数栈
    stack<char> op; // 操作符栈
    char ch, c; // ch存储输入的字符,c存储操作符栈顶的元素
    long long int num, result, a, b; // result存储计算的结果,a,b存储从数栈中取出的两个数
    
        cin.get(ch);
        while(ch != '\n') {
            if(isdigit(ch)) { // 如果是数字
                num = (ch - '0'); // ch - '0'根据ASCAII码，字符与数字之间的转换关系
                cin.get(ch);
                mynumbers.push(num); // 存到数栈中
            } else if(ch == '(') { // (:左括号
                op.push(ch);
                cin.get(ch); // 读取下一个字符
            } else if(isOperator(ch)) { // 操作符
                if(op.empty()) {// 如果栈空，直接压入栈
                    op.push(ch);
                    cin.get(ch); // 读取下一个字符
                }
                else {
                    // 比较栈op顶的操作符与ch的优先级
                    // 如果ch的优先级高，则直接压入栈
                    // 否则，推出栈中的操作符，直到操作符小于ch的优先级，或者遇到（，或者栈已空
                    if (ch == '~' && op.top() == '~')
                        op.pop();
                    else {
                        while(!op.empty()) {
                        c = op.top();
                        if (c == '~')
                        {
                            result = -mynumbers.top();
                            mynumbers.pop();
                            mynumbers.push(result);
                            op.pop();
                        }
                        else if(getPriority(ch) <= getPriority(c)) {
                            // 优先级低或等于
                            // 取出栈中操作符和数栈中两个数进行运算，再将结果放回数栈
                            result = 0;
                            a = mynumbers.top(); // 第二个操作数,因为栈是后进先出
                            mynumbers.pop();
                            b = mynumbers.top(); // 第一个操作数
                            mynumbers.pop();
                            
                            result = Calculate(c, a, b); // 计算
                            
                            mynumbers.push(result); // 把计算结果压入栈中
                            op.pop(); // 操作符出栈
                        } else // ch优先级高于栈中操作符
                            break;
                    } // while结束
                    op.push(ch); // 防止不断的推出操作符，最后空栈了;或者ch优先级高了
                    }
                    cin.get(ch);
                } // else
            } else if(ch == ')') { // 如果是右括号，一直推出栈中操作符，直到遇到左括号(
                while(op.top() != '(') {
                    c = op.top();
                        if (c == '~')
                        {
                            result = -mynumbers.top();
                            mynumbers.pop();
                            mynumbers.push(result);
                            op.pop();
                        }
                        else if(getPriority(ch) <= getPriority(c)) {
                            // 优先级低或等于
                            // 取出栈中操作符和数栈中两个数进行运算，再将结果放回数栈
                            result = 0;
                            a = mynumbers.top(); // 第二个操作数,因为栈是后进先出
                            mynumbers.pop();
                            b = mynumbers.top(); // 第一个操作数
                            mynumbers.pop();
                            
                            result = Calculate(c, a, b); // 计算
                            
                            mynumbers.push(result); // 把计算结果压入栈中
                            op.pop(); // 操作符出栈
                        }
                }
                op.pop(); // 把左括号(推出栈
                cin.get(ch);
            } else // 如果是空白符，就进行下一个字符的处理
                cin.get(ch);
        } // 第二个while结束
        while(!op.empty()) { // 当栈不空，继续取出操作符进行计算]
        c = op.top(); // 取出栈顶操作符
        if (c == '~')
        {
            result = -mynumbers.top();
            mynumbers.pop();
        }
        else {
            result = 0;
            a = mynumbers.top(); // 第二个操作数,因为栈是后进先出
            mynumbers.pop();
            b = mynumbers.top(); // 第一个操作数
            mynumbers.pop();
            
            result = Calculate(c, a, b); // 计算
        }
        mynumbers.push(result); // 把计算结果压入栈中
        op.pop(); // 把操作符推出栈}
        }
        cout << mynumbers.top() << endl;
        mynumbers.pop();
    
    return 0;
}
 
