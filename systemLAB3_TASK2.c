#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
	char *istr;

	if (argc == 1){
		printf("Слишком мало аргументов...\n");
	}
	if (argc == 2){	
		istr = strtok(argv[1], ";");
		if (istr != NULL){
			while (istr != NULL){
				system(istr);
				istr = strtok(NULL,";");
			};
		}else system(argv[1]);
	}

	if (argc > 2){
		int i;
		char init_str[] = "";
		strcat(init_str, argv[1]);
		strcat(init_str, " ");
		strcat(init_str, argv[2]);	
		system(init_str);

		// for (i = 1; i < argc; i++){
		// 	strcat(init_str, argv[i]);
		// 	strcat(init_str, " ");
		// }
	}


   return EXIT_SUCCESS;
}