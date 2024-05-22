#include <iostream>
#include <deque>
#include <array>
#include <algorithm>
#include <string>

using namespace std;
constexpr array<char, 4> operators{'*','-','+','/'};

int evaluate(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		return (x + y);

	case '-':
		return (x - y);

	case '*':
		return (x * y);

	case '/':
		return (x / y);

	default: return -1;
	}
}

void solve(deque<int>& arr)
{
	if ((arr[0] == 24) && (arr.size() == 1))
	{
		cout << "Solved";
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr.size() > 1)
		{
			deque<int> l;
			copy(arr.begin(), arr.end(), back_inserter(l));
			int n = evaluate(arr[0], arr[1], operators[i]);
			cout << arr[0] << " " << operators[i] << " " << arr[1] << "\n";
			arr.pop_front();
			arr.pop_front();
			arr.push_back(n);
			solve(arr);
			arr = l;
		}
	}
	return;
}

int main()
{
	deque<int> inputs;
	int x;
	cout << "Type in four integers: \n";
	for (int i = 0; i < 4; i++) { cin >> x; inputs.push_back(x); }
	solve(inputs);
	return 0;
}