#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

bool ifoperator(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '\\')
		return true;
	else
		return false;
}

string PrefixToPostfix(string prefix)
{
	stack<string> postfix;
	int length = prefix.size();
	for (int i = length-1; i >= 0; i--)
	{
		if (ifoperator(prefix[i]))
		{
			string operand1 = postfix.top();
			postfix.pop();
			string operand2 = postfix.top();
			postfix.pop();
			string pushNew = operand1 + operand2 + prefix[i];
			postfix.push(pushNew);
		}
		else
			postfix.push(string(1, prefix[i]));//Âà´«type,charÂàstring//
	}
	return postfix.top();
}

int main()
{
	string prefix;
	cout << "Please enter the expression:"<<endl;
	cin >> prefix;
	cout << PrefixToPostfix(prefix);
	return 0;
}
