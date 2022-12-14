#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	pid_t pid1, pid2, pid3, pid4, pid5, pid6;
	int value = 0;
	printf("0.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
	printf("--------------------------------\n");
	pid1 = fork();
	value++;
	printf("1.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
	printf("--------------------------------\n");
	if (pid1 > 0) {
		pid2 = fork();		
		value++;
		printf("2.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
		printf("--------------------------------\n");
	}

	if (pid1 == 0) {			
		pid3 = fork();
		value++;
		printf("3.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
		printf("--------------------------------\n");
		if (pid3 > 0) {
			pid5 = fork();
			value++;
			printf("4.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
			printf("--------------------------------\n");
		}	
	}
	
	if (pid2 == 0) {
		pid4 = fork();
		value++;
		printf("5.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);
		printf("--------------------------------\n");
		if (pid4 > 0) {
			pid6 = fork();
			value++;	
			printf("6.My id: %d.\n Parent id: %d.\n Value: %d.\n Address of value: %p.\n", getpid(), getppid(), value, &value);	
			printf("--------------------------------\n");
		}
	}
	return EXIT_SUCCESS;
}