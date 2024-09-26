//洛谷P3375
//另见https://www.bilibili.com/video/BV1234y1y7pm/?spm_id_from=333.337.search-card.all.click&vd_source=33f14fc7c332288da6dec7ab745ca78b
//https://www.bilibili.com/video/BV1jb411V78H/?spm_id_from=333.337.search-card.all.click
//https://www.bilibili.com/video/BV16X4y137qw/?spm_id_from=333.337.search-card.all.click
#include <bits/stdc++.h>
#define MAX 1000003
using namespace std;
char str[MAX], p[MAX];
int Next[MAX],match[MAX],n;
int len1, len2;
void KMP();
void getNext(int);
void print();
void KMP() {
	len1 = strlen(str+1), len2 = strlen(p+1);
	getNext(len2);
	int j = 0;
	for (int i = 0; i < len1; ++i) {
		while (j > 0 && str[i + 1] != p[j + 1])
			j = Next[j];
		if (str[i + 1] == p[j + 1])
			++j;
		if (j == len2)//j未自增前,比较p[j+1],如果成立则此次j自增后j==len2
			match[++n] = i-len2+2;//i-len2+2==(i+1)-len2+1
	}
	return;
}
void getNext(int len) {
	int j = 0;
	Next[1] = 0;
	for (int i = 2; i <= len; ++i) {
		while (j > 0 && p[i] != p[j + 1])
			j = Next[j];
		if (p[i] == p[j + 1])
			j++;
		Next[i] = j;
	}
	//for (int i = 1; i <= len; ++i)
	//	cout << Next[i];
	return;
}
void print() {
	for (int i = 1; i <= n; ++i)
		cout << match[i] << ' ';//'\n'换为' '---'\n'->洛谷要求
	/*for (int i = 1; i <= len2; ++i)
		cout << Next[i]<<' ';*/
}
int main() {
	cin >> str+1 >> p+1;
	KMP();
	print();
	return 0;
}