#include <iostream>
#include <deque>
#include <array>

using namespace std;
constexpr array<char, 4> operators{'+','-','*','/'};

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

void solve(deque<int> &arr, int s_index, int l_index)
{
	if ((arr[0] == 24) && (arr.size() == 1))
	{
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr.size() > 0)
			{
				arr[1] = evaluate(arr[s_index], arr[l_index], operators[j]);
				arr.pop_front();
				solve(arr, s_index + i, l_index + i);

			}
		}
	}
}

int main()
{
	deque<int> inputs;
	cout << "Type in four integers: \n";
	for (int i = 0; i < 4; i++) { cin >> inputs[i]; }



	return 0;
}