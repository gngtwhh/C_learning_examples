#include <iostream>
using namespace std;
int main() {
	int i,sum=0;
	cin >> i;
	while (i) {
		if (i & 1)
			sum++;
		i >>= 1;
	}
	cout << sum;
	return 0;
}
//n&=n-1方法
#if 0
#include <iostream>
using namespace std;
int main() {
    int i,sum=0;
    cin >> i;
    while (i) {
        sum++;
        i&=i-1;
    }
    cout << sum;
    return 0;
}
#endif
//常规
#if 0
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int ones, value;
    cin >> value;
    for(ones=0;value;value>>=1){
        if(value%2!=0)
            ones++;
    }
    cout<<ones;
    return 0;
}
#endif