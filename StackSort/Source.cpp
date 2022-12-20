#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

void PushBackAllFromStackToAnother(stack<int>& fromStack, stack<int>& toStack)
{
	while (!fromStack.empty())
	{
		toStack.push(fromStack.top());
		fromStack.pop();
	}
}

stack<int> StackSort(stack<int> unsortedStack)
{
	stack<int> sortedST;
	stack<int> helpingST;
	while (!unsortedStack.empty())
	{
		int val = unsortedStack.top();
		if (sortedST.empty())
		{
			sortedST.push(val);
			unsortedStack.pop();
			PushBackAllFromStackToAnother(helpingST, sortedST);
		}
		else if (val >= sortedST.top())
		{
			sortedST.push(val);
			unsortedStack.pop();
			PushBackAllFromStackToAnother(helpingST, sortedST);
		}
		else
		{
			helpingST.push(sortedST.top());
			sortedST.pop();
		}
	}
	return sortedST;
}

void PrintStack(stack<int> st)
{
	while (!st.empty())
	{
		cout << st.top()<<endl;
		st.pop();
	}
}

int main()
{

//will sort stack using stack

 	stack<int> st;
	st.push(5);
	st.push(10);
	st.push(4);
	st.push(3);
	st.push(0);
	st.push(5);
	st.push(20);
	st.push(21);
	st.push(25);

		cout << "Before sort";
	PrintStack(st);
	
	st = StackSort(st);
		cout << "After sort\n\n\n";
	PrintStack(st);

}