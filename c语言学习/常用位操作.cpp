#include <iostream>
using namespace std;
int main() {
	int x, bit_number;
	cin >> x;

	cout << (x & 1)<<endl;//取出x的最低位
	
	cin >> bit_number;//t的范围:[0,整型值的位数-1]
	x = x | 1 << bit_number;//将指定位置1 注意优先级!---可以写为 |=
	cout << x << endl;

	cin >> bit_number;//t的范围:[0,整型值的位数-1]
	x = x & ~ (1 << bit_number);//将指定位置0 注意优先级!---可以写为 &=
	cout << x << endl;

	cin >> bit_number;
	if(x & 1 << bit_number)//该表达式检查x的指定位是否为1,若是则返回非0值
		cout <<"yes";
	return 0;
}