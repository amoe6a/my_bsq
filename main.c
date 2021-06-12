#include "my_bsq.c"
#include "my_bsq.h"
#include "funcs.c"


int main(int argc, char ** argv) {
    if (argc < 2)
        return 0;
    struct stat buf;
    stat(argv[1], &buf);
    if (!S_ISREG(buf.st_mode)){
        printf("Argument is not a file\n");
        return 0;
    }
    FILE * grid = fopen(argv[1], "r");
    int counter = 0;
    int char_nums_length = 0;
    int row_num;
    int row_size;

    while(!feof(grid) && fgetc(grid) != '\n')
        char_nums_length++;
    while(!feof(grid)) { // Counting the number of chars inside the file, not including the number at the beginning
        fgetc(grid);    // the trailing '\n' and EOF are also counted in counter
        counter++;
    }
    if (counter == 0) {
        printf("Empty file!");
        return 0;
    }
    char* buf_str = (char*)malloc(counter + 1);
    char* char_nums_buffer = (char*) malloc(char_nums_length + 1);

    fseek(grid, 0, SEEK_SET);

    for (int i = 0; i <= char_nums_length; ++i) // Getting the number of rows
        char_nums_buffer[i] = fgetc(grid);
    char_nums_buffer[char_nums_length] = '\0';
    row_num = my_positive_atoi(char_nums_buffer);

    row_size = counter / row_num; // For correct input file, this must be ok!

    for (int i = 0; !feof(grid); ++i) // Copying the file chars into a single string
        buf_str[i] = fgetc(grid);
    buf_str[counter - 1] = '\0';

    my_bsq(buf_str, counter, row_num, row_size);

    return 0;
}
