class MyQueue
{
public:
	MyQueue()
	{
	}

	void push(int x)
	{
		if (stack.empty())
		{
			stack.push(x);
			return;
		}

		std::stack<int> tempStack;
		while (!stack.empty())
		{
			tempStack.push(stack.top());
			stack.pop();
		}
		stack.push(x);
		while (!tempStack.empty())
		{
			stack.push(tempStack.top());
			tempStack.pop();
		}
	}

	int pop()
	{
		auto res = stack.top();
		stack.pop();
		return res;
	}

	int peek()
	{
		return stack.top();
	}

	bool empty()
	{
		return stack.empty();
	}

private:
	std::stack<int> stack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */