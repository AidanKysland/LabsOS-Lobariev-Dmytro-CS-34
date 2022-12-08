#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void getProcessInf(void){
	printf("Process IDentifer: %d\n", getpid());
	printf("Parent Process IDentifer: %d\n", getppid());
	printf("Group Process IDentifer: %d\n", getpgrp());
	printf("Real Owner IDentifer: %d\n", getuid());
	printf("Effective Owner IDentifer: %d\n", geteuid());
	printf("Real Group Process IDentifer: %d\n", getgid());
	printf("Effective Group Process IDentifer: %d\n", getegid());
}

int main(int argc, char **argv) {
	if(argc == 1) { 
		printf("Запуск без аргументов...\n");
		printf("Список доступных аргументов:\n");
		printf("-p 0 - вывод полной информации о текущем процессе.\n");
		printf("-p 1 - вывод идентификатора текущего процесса и его родителя.\n");
		printf("-p 2 - вывод реального и эффективного идентификатора владельца текущего процесса.\n");
		printf("-p 3 - вывод реального и эффективного идентификатора группы вызывающего процесса.\n");
		printf("-p 4 - вывод идентификатора группы вызывающего процесса.\n");		
		return 0;
	}
	char *opts = "p:";
	int opt, a; 
	while((opt = getopt(argc, argv, opts)) != -1) {
		
		switch(opt) {
			case 'p': 
			a = optarg[0];
			break;
			case '?': default: {
				printf("Неизвестная команда...\n");
				printf("Список доступных аргументов:\n");
				printf("-p 0 - вывод полной информации о текущем процессе.\n");
				printf("-p 1 - вывод идентификатора текущего процесса и его родителя.\n");
				printf("-p 2 - вывод реального и эффективного идентификатора владельца текущего процесса.\n");
				printf("-p 3 - вывод реального и эффективного идентификатора группы вызывающего процесса.\n");
				printf("-p 4 - вывод идентификатора группы вызывающего процесса.\n");
				break;
			};
		}
		switch(a) {
			case '0': 
				getProcessInf();
				break;
			case '1':
				printf("Process IDentifer: %d\n", getpid());
				printf("Parent Process IDentifer: %d\n", getppid());
				break;
			case '2': 
				printf("Real Owner IDentifer: %d\n", getuid());
				printf("Effective Owner IDentifer: %d\n", geteuid());
				break;
			case '3':
				printf("Real Group Process IDentifer: %d\n", getgid());
				printf("Effective Group Process IDentifer: %d\n", getegid());
				break;
			case '4': 
				printf("Group Process IDentifer: %d\n", getpgrp());
				break;
			case '?': default:{
				printf("Неизвестная команда...\n");
				printf("Список доступных аргументов:\n");
				printf("-p 0 - вывод полной информации о текущем процессе.\n");
				printf("-p 1 - вывод идентификатора текущего процесса и его родителя.\n");
				printf("-p 2 - вывод реального и эффективного идентификатора владельца текущего процесса.\n");
				printf("-p 3 - вывод реального и эффективного идентификатора группы вызывающего процесса.\n");
				printf("-p 4 - вывод идентификатора группы вызывающего процесса.\n");
				break;
			};
				
		}
	}
	return EXIT_SUCCESS;
}