#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
stack < char > oper;
int ranking(char s)
{
	if (s == '(' || s == ')')
	{
		return 1;
	}
	else if (s == '*' || s == '/')
	{
		return 3;
	}
	else if (s == '+' || s == '-')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
int main()
{
	string equation;
	cin >> equation;
	for (int i = 0; i < equation.size(); ++i)
	{
		char c = equation[i];
		if (ranking(c) == 0)
		{
			cout << equation[i];
		}
		else
		{
			if (c == '(')
			{
				oper.push(c);
			}
			else if (c == ')')
			{
				while (!oper.empty()&&oper.top() != '(')
				{
					cout << oper.top();
					oper.pop();
				}
				oper.pop();
			}
			else
			{
				while (!oper.empty()&&ranking(oper.top()) >= ranking(c))
				{
					cout << oper.top();
					oper.pop();
				}
				oper.push(c);
			}
		}
	}
	while (!oper.empty())
	{
		cout << oper.top();
		oper.pop();
	}
}