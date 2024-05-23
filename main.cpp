#include <iostream>
#include <deque>
#include <array>
#include <algorithm>
#include <string>

#include "Fraction.h"

using namespace std;
constexpr array<char, 4> operators{'+','-','*','/'};

Fraction evaluate(Fraction x, Fraction y, char op)
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
	}
}

void solve(deque<Fraction>& arr, deque<string>& moves)
{
	if ((arr[0].getIntValue() == 24) && (arr.size() == 1))
	{
		cout << "Solved \n";
		for (auto e : moves) { cout << e; }
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr.size() > 1)
		{
			deque<Fraction> l;
			copy(arr.begin(), arr.end(), back_inserter(l));
			Fraction n = evaluate(arr[0], arr[1], operators[i]);
			string output = arr[0].stringify() + " " + operators[i] + " "
				+ arr[1].stringify() + " = " + n.stringify() + "\n";
			cout << output;
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

void createPermutations(deque<Fraction>& in, deque<deque<Fraction>>& out, int l, int r)
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
	deque<int> inputs{};
	deque<Fraction> inputsF{};
	deque<deque<Fraction>> permutations{};
	inputs.resize(4);
	deque<string> moves{};
	cout << "Type in four integers: \n";
	for (int i = 0; i < 4; i++) { cin >> inputs[i]; }
	for (auto e : inputs)
	{
		Fraction tmp(e, 1);
		inputsF.push_back(tmp);
	}
	createPermutations(inputsF, permutations, 0, 3);
	for (auto e : permutations) { solve(e, moves); }
	return 0;
}