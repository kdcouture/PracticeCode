#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	char *token, *string, *tofree;
	if(argc > 1){
		printf("command line args passed\n");
	}
	tofree = string = strdup("abc,def,ghi,jkl");
	token = strtok(string,",");
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, ",");
	}
	free(tofree);

	return 0;
}
