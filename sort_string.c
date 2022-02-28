#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf(2, "Usage: sort_string <string>\n");
        exit();
    }
    char* string = argv[1];

    //sort string by character
    int i, j;
    for (i = 0; i < strlen(string); i++) {
        for (j = i + 1; j < strlen(string); j++) {
            if (string[i] > string[j]) {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }

    //write string in a file
    int fd = open("sort_string.txt", O_CREATE | O_WRONLY);
    if (fd < 0) {
        printf(2, "open file error\n");
        exit();
    }
    string[strlen(string)] = '\n';
    if (write(fd, string, strlen(string)) < 0) {
        printf(2, "write file error\n");
        exit();
    }
    close(fd);
    exit();
}