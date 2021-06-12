//
// Created by amoeba on 30.05.21.
//
#include "my_bsq.h"

int my_positive_atoi(char * str){ //returns -1 for an ill input
    if (str == NULL)
        return 0;
    int output = 0;
    char * pntr = str;
    while(pntr){
        if(*pntr == '\0')
            break;
        if(*pntr < '0' || *pntr > '9'){
            return -1;
        }
        else
            output = output * 10 + (*pntr - '0');
        pntr++;
    }
    return output;
}


int ** turn_into_int_string(char * grid, int row_num, int row_size){
    int ** int_grid = (int**)malloc( row_num * sizeof(int*) );

    for (int i = 0; i < row_num; ++i) {
        int * tmp = (int*) malloc( row_size * sizeof(int) );
        int_grid[i] = tmp;
        for (int j = 0; j < row_size; ++j) {
            if (grid[i * (row_size + 1) + j] == 'o')
                int_grid[i][j] = 0;
            else if (grid[i * (row_size + 1) + j] == '.')
                int_grid[i][j] = 1;
        }
    }
    return int_grid;
}

//int main(){
//    printf("%i", my_positive_atoi("39"));
//}
