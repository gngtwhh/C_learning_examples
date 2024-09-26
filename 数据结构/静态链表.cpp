#include <stdio.h>
#include <iostream>
using namespace std;
int a[100], mnext[100] = { 0 }, n;
void init()
{
	cin >> n;
	mnext[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		mnext[i] = i + 1;
	}
	mnext[n] = 0;
}
void print()
{
	//print
	int now = 0;
	int index = 1;
	while (mnext[now] != 0)
	{
		cout << "the value of " << index << " node is " << a[mnext[now]] << endl;
		now = mnext[now];
		++index;
	}
}
void insert()
{
	int key_index, now = 0, value;
	cout << "where?";
	cin >> key_index;
	if (key_index > n)
	{
		cout << "error,the node doesn\'t exist";
		return;
	}
	int index = 1;
	while (mnext[now] != 0 && index != key_index)
	{
		++index;
		now = mnext[now];
	}
	int temp = mnext[now];
	mnext[now] = n + 1;
	++n;
	cout << "value?";
	cin >> a[n];
	mnext[n] = temp;
	return;
}
int main()
{
	init();
	print();
	insert();
	print();
	return 0;
}