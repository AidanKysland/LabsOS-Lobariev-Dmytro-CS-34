#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>

#define A 8
#define B 12
#define R 3

int main(int argc, char **argv){
  	pid_t status, childpid;
	int exit_status;
	int n = atoi(argv[1]);
	double m,s;
	printf("%d\n",n);

	status = fork();
	if (status == -1) {
		fprintf (stderr, "Fork Error\n");
		exit(EXIT_FAILURE);
	}

	if (status == 0){
		execl("h", argv[1], NULL);
		fprintf(stderr, "Exec Error\n");
		exit(EXIT_FAILURE);	
	}
	childpid = wait(&exit_status);
  	if (WIFEXITED(exit_status)) {
		m = WEXITSTATUS(exit_status);
		s = (double) (m/n) * (A * B);
		printf("m = %f\n", m);
		printf("S = %f\n", s);
		printf("Значение Пи: %f\n", s/(R*R));
	}
  return 0;
}
