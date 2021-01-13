#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int> > arr;
void display(vector<vector<int> > &arr)
{
	//cout << "sdf";
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
bool isValid(vector<vector<int> > &arr, int i, int j, int po)
{
	//cout << "b" << endl;
	for (int x = 0; x < arr[0].size() - 1; ++x)
	{
		if (arr[i][x] == po)
			return 0;
	}
	for (int x = 0; x < arr.size(); ++x)
	{
		if (arr[x][j] == po)
			return 0;
	}

	int smi = (i / 3) * 3;
	int smj = (j / 3) * 3;
	for (int x = 0; x < 3; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			if (arr[smi + x][smj + y] == po)
				return 0;
		}
	}
	return 1;
}
void solve(vector<vector<int> > &arr, int i, int j)
{
	//cout << "a" << endl;
	//cout << "i " << i << " j " << j << endl;
	if (i == arr.size())
	{
		//cout << "display" << endl;
		cout << "Here is your Solved Sudoku..!"
		     display(arr);
	}
	int newi = 0;
	int newj = 0;
	if (j == (arr[0].size() - 1))
	{
		newi = i + 1;
		newj = 0;
		//cout << "new row" << endl;
	}
	else
	{
		newi = i;
		newj = j + 1;
		//cout << "new coll" << endl;
	}

	if (arr[i][j] != 0)
	{
		//cout << "not zero" << endl;
		solve(arr, newi, newj);
	}
	else
	{
		for (int po = 1; po < 10; ++po)
		{
			if (isValid(arr, i, j, po) == 1)
			{
				arr[i][j] = po;
				//cout << "bingo !" << endl;
				solve(arr, newi, newj);
				//cout << "backtrack" << endl;
				arr[i][j] = 0;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	int n;
	cout << "Enter the size of board" << endl;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i)
	{
		arr[i].resize(n);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	//cout << arr[0].size();
	//for debugging !
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	solve(arr, 0, 0);
	return 0;
}
