//P8813
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int a, b;//题目要求设置a,b
	int ans = 1;
	cin >> a >> b;//输入a,b
	if (a == 1) {
		cout << 1;
		return 0;
	}
	while (b > 0 && ans <= 1e9 && ans > 0) { //ans>0保证longlong没炸,<=1e9题目要求,如果
		//ans不满足条件直接结束
		if (b & 1) { //b的当前最后一位为1---也就是说当前b的这一位需要乘
			//if(b&1)等价于if(b%2==1)
			ans *= a;//那么就乘a的当前的2*k幂
		}
		a *= a;//将a平方
		b >>= 1;//舍弃这次循环使用过的这一位,下次循环使用下一个位
		//b>>=1等价于b/=2
	}
	if (ans <= 1e9 && ans > 0) //ans>0保证longlong没炸,<=1e9题目要求
		cout << ans;
	else cout << -1;
	return 0;
}