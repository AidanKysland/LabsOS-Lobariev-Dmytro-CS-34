#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main (void) {
	int status;
/* Child */
	if (!fork ()) {
		execlp("ls", "ls", NULL);
		fprintf (stderr, "Exec error\n");
		exit(0);
	}
/* Parent */
	sleep(40);
	wait(&status);
	if (WIFEXITED (status)) {
		printf ("Code=%d\n", WEXITSTATUS(status));
	}
	return 0;
}
