#include <stdio.h>
#include "count.h"


int main(void) {
	double x, res;
	printf("Input x: ");
	scanf("%lf", &x);
	res = f(x);
	printf("%s%lf\n", "res = ", res);
	res = g(x);
	printf("%s%lf\n", "res = ", res);
}
