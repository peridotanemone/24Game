#include <iostream>
#include <deque>
#include <array>
#include <algorithm>
#include <string>

#include "Fraction.h"

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

void solve(deque<int>& arr, deque<string>& moves)
{
	if ((arr[0] == 24) && (arr.size() == 1))
	{
		cout << "Solved \n";
		for (auto e : moves) { cout << e; }
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr.size() > 1)
		{
			deque<int> l;
			copy(arr.begin(), arr.end(), back_inserter(l));
			int n = evaluate(arr[0], arr[1], operators[i]);
			string output = to_string(arr[0]) + " " + operators[i] + " " + to_string(arr[1]) + " = " + to_string(n) + "\n";
			moves.push_back(output);
			arr.pop_front();
			arr.pop_front();
			arr.push_back(n);
			solve(arr, moves);
			arr = l;
			moves.pop_back();
		}
	}
	return;
}

void createPermutations(deque<int>& in, deque<deque<int>>& out, int l, int r)
{
	if (l == r)
	{
		out.push_back(in);
		return;
	}
	for (int i = l; i < r; i++)
	{
		swap(in[l], in[i]);

		createPermutations(in, out, l + 1, r);

		swap(in[i], in[l]);
	}
}

int main()
{
	deque<int> inputs;
	deque<deque<int>> permutations;
	inputs.resize(4);
	deque<string> moves{};
	cout << "Type in four integers: \n";
	for (int i = 0; i < 4; i++) { cin >> inputs[i]; }
	createPermutations(inputs, permutations, 0, 3);
	for (auto e : permutations) { solve(e, moves); }
	return 0;
}