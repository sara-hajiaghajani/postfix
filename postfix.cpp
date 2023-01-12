

#include <iostream>
#include<cstring>

using namespace std;


class Stack
{
	
private:
	string* m_Array;
	int m_Len;
	int m_Top;
public:
	Stack(int len):m_Len(len)
	{
		m_Array = new string [m_Len];
		m_Top = 0;
	}

	bool IsEmpty()
	{
		if(m_Top == 0)
			return true;
		else
			return false;
	}

	bool IsFull()
	{
		if(m_Top == m_Len)
			return true;
		else
			return false;
	}

	void Resize()
	{
		string* temp = new string [2*m_Len];
		for(int i=0;i<m_Len;i++)
			temp[i] = m_Array[i];
			
		m_Len *= 2;
		delete[] m_Array;
		m_Array = temp;
	}

	void Push(string value)
	{
		if(IsFull())
			Resize();
		m_Array[m_Top] = value;
		m_Top++;
	}

	void Pop()
	{
		if(!IsEmpty())
			m_Top--;
	}

    string Top()
	{
		if(!IsEmpty())
			return m_Array[m_Top-1];
	}

	void Clear()
	{
		m_Top = 0;
	}

	~Stack()
	{
		delete[] m_Array;
	}
};


		int getweight(string input)
	{

		int weight = 0;

		if (input == "(" || input == ")")
		{
			weight= -1;
		}

		if (input == "+" || input == "-")
		{
			weight = 1;
		}

		if (input == "/" || input == "*")
		{
		weight = 2;
		}

		return weight;
	}
	

int main()
{
	string infix, postfix = "";
	cin >> infix;

	Stack S(20);

	string test;
	int  weight, j = 0;
	
	



	for (int i = 0; i < infix.length(); i++)
	{
		test = infix[i];
		weight = getweight(test);

		if (weight == 0)
		{
			postfix += test;
		}

		if (weight == -1)
		{

			if (test == "(")
			{
				S.Push(test);
			}

			if (test == ")")
			{
				while (!S.IsEmpty() && S.Top() != "(")
				{
					postfix += S.Top();
					S.Pop();
				}

				if (!S.IsEmpty()) {
					S.Pop();
				}
			}
		}

		if (weight == 1 || weight == 2)
		{
			if (S.IsEmpty())
			{
				S.Push(test);
			}

			else
			{
				while (!S.IsEmpty() && S.Top() != "(" && weight <= getweight(S.Top()))
				{
					postfix += S.Top();
					S.Pop();
				}
				
				S.Push(test);
			}
		}
	}

	while (!S.IsEmpty()) {
		postfix += S.Top();
		S.Pop();
	}

	cout << postfix << endl;

		return 0;
}
	



