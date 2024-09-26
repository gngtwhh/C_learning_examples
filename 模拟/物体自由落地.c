/*
一球从100米高度自由落下,每次落地后反跳回原高度的一半,再落下,
求它在第10次落地时,共经过多少米？第10次反弹多高？
 */
#include <stdio.h>
int main() {
	double sn = 100.0, hn = sn / 2;
	for (int n = 2; n <= 10; n++) {
		sn = sn + 2 * hn;/*第n次落地时共经过的米数*/
		hn = hn / 2; /*第n次反跳高度*/
	}
	printf("\n球所经过的路程为:%lf米\n", sn);
	printf("第10次反弹高度为:%lf米\n\n", hn);
	return 0;

}