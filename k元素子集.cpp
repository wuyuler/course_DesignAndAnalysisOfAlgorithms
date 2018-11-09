#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
void choose_k_of_n(const vector<char>& input, int i, int k, vector<string>& output, string& cur)
{
	// generate all k-subsets of {i, i+1, ..., n} stored in array input
	// in descending order of their components
	if (k == 0)
	{
		output.push_back(cur);
	}else
	{
		// j < input.size() - k + 1是为了给剩下的几位留出足够的元素。
		for (int j = i; j < input.size() - k + 1; ++j)
		{
			cur[k-1] = input[j];
			choose_k_of_n(input, j+1, k-1, output, cur);
		}
	}
}
int main()
{
	char temp[5] = {'A', 'B', 'C', 'D', 'E'};
	vector<char> input(temp, temp+5);
	vector<string> output;
	string cur;
	cur.resize(4);
	choose_k_of_n(input, 0, 4, output, cur);
	copy(output.begin(), output.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	system("Pause");
}
