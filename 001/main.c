#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arguments {
	unsigned int files_count;
	char **files;
} arguments;

void parse_arguments(int argc, char **argv, arguments *args) {
	args->files = malloc(argc * sizeof(char)); //  (*args).files
	int index = 0;

	for (int i; i < argc; i++) {
		if (strcmp(argv[i], "--help")) {
			printf("./main <files> [--help]");
		} else {
			args->files[index] = argv[i];
			index += 1;
		}
	}

	args->files_count = index;
}

int main(int argc, char **argv) {
	arguments args = {0};
	parse_arguments(argc, argv, &args);

	return 0;
}

