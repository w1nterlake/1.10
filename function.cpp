#include "header.h"

void *func(void *arg){
    Args *tmp = (Args *)arg;
    FILE *fin = fopen(tmp->filename, "r");
    int current, last, last_last;
    int count = 0, size = 0;
    if(fin == nullptr){
        tmp->ret = false;
    }
    else{
        while(fscanf(fin, "%d", &current) == 1){
            size++; 
            if(size == 1){
                last = current;
            }
            else if(size == 2){
                last_last = last;
                last = current;
            }
            else{
                if(last_last < last && last_last < current){
                    count++;
                }
                last_last = last;
                last = current;
            }
        }
    }
    tmp->count = count;
    tmp->size = size;
    tmp->ret = true;
    fclose(fin);
}