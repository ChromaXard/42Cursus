#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"

int main() {
    int fd = open("lorem.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line); 
    }

    close(fd);
    return EXIT_SUCCESS;
}