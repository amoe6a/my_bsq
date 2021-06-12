//
// Created by amoeba on 21.05.21.
//

#ifndef MY_BSQ_MY_BSQ_H
#define MY_BSQ_MY_BSQ_H


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

void my_bsq(char* grid, int size, int row_num, int row_size);
int my_positive_atoi(char * str);
int ** turn_into_int_string(char * grid, int row_num, int row_size);


#endif //MY_BSQ_MY_BSQ_H