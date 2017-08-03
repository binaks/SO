#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t pidf1, pidf12, pidf2, pidf22;
	pidf1 = fork();

	if (pidf1 < 0) {
		printf("Erro ao criar processo\n");
		return 1;
	}

	else if (pidf1 == 0) {
		printf("Esta é a execução do filho 1\n");
		pidf12 = fork();
		
		if (pidf12 == 0) {
			printf("Esta é a execução do filho do filho 1\n");
			exit(0);
		} else {
			exit(0);
		}	
	}

	else {
		pidf2 = fork();
		
		if (pidf2 == 0) {
			printf("Esta é a execução do filho 2\n");
			pidf22 = fork();
			
			if (pidf22 == 0) {
				printf("Esta é a execução do filho do filho 2\n");
				exit(0);
			} else { 
				exit(0);
			}
		} else {
				wait(NULL);
				exit(0);
		}
	}

	return 0;
}
