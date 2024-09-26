#include<stdio.h>
#include<math.h>
int main() {
	float x1, y1, x2, y2, x3, y3, a, b, c, p, area;
	scanf("%f,%f%f,%f%f,%f", &x1, &y1, &x2, &y2, &x3, &y3);
	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));

	if (a + b > c && a + c > b && b + c > a) {
		p = 1.0 / 2 * (a + b + c);
		area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("primeter=%.2f,area=%.2f\n", a + b + c, area);
	} else {
		printf("Impossible\n");
	}
	return 0;
}