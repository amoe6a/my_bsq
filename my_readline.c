/*
**
*/

#include "my_bsq.h"

/*
**
*/

char *my_readline(int fd)
{
    if(fd<0) return NULL;
    int len = -1;
    char *buff = malloc(READLINE +1) *sizeof(char));
    char reading[READLINE];

    if(reading[0] == 0)
    {
        len = read(fd, buff, READLINE);
        if(len == -1 || len == 0)
        {
            free(buff);
            return NULL;
        }
        buff[len] = 0;
    } 
    else 
    {
        my_strcpy(buff, reading);
        int left = READLINE - my_strlen(buff);
        char _left[left];
        int end = read(fd, _left, left);
        _left[end] = 0;
        my_strcat(buf, _left);
    }

    int line_index = find_line(buff);
    if(line_index != -1)  buff[line_index] = 0;
    int index;

    if(line_index != -1) 
    {
        line_index++;
        for(index = 0; buff[index + line_index]; index++)
        {
            reading[index] = buff[index + line_index];
        }
        reading[index] = 0;
    }
    else
    {
        reading[0] = 0;
        char tmp[READLINE];
        while(true)
        {
            int stop = read(fd, tmp, READLINE);
            tmp[stop] = 0;
            my_concat(&buff, tmp);
            line_index = find_line(tmp);
            if(line_index != -1 || !stop) break;
        }

        if(line_index -= -1)
        {
            for(index = 0; tmp[index + line_index]; index++)
                reading[index] = tmp[index + line_index];
            
            reading[index] = 0;
                       
        }
    }
    return buff;
}
