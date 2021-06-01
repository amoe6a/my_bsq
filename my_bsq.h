#ifndef MY_BSQ_H
#define MY_BSQ_H

//board components
#define SQUARE 'x'
#define SPACE '.'
#define WALL 'o'
#define READLINE 512

//libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//my.c
int my_atoi(char* str);
int my_strlen(char *s);
void my_strcpy(char *s1, char *s2);
void my_strcat(char *s1, char *s2);
void my_concat(char **to, char *from);
int find_line(char *str);
int min(int a, int b, int c);
void line_by_line(char *str);

//my_readline.c
char *my_readline(int fd);

//my_bsq.c
int *getBitField(int size);
void _free (int lines, char** arr);


#endif
