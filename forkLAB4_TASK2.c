#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#define TIME 2	

int main(void) {
	pid_t pid;
	int a = 0;
	time_t t = time(NULL) + TIME;
	pid = fork();
	while (t > time(NULL)) {
		a++;
	}
	if (pid == 0) {
		printf("Процесс потомок выполнился %d раз.\n", a);
	} else if (pid > 0) {
		printf("Родительский процесс выполнился %d раз.\n", a);
	} else {
		printf("Ошибка вызова fork, потомок не создан\n"); 
	}
	return EXIT_SUCCESS;
}
