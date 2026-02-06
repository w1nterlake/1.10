#include "header.h"


int main(int argc, char *argv[]){
    int p = argc - 1;
    pthread_t *th = (pthread_t*)malloc(p * sizeof(pthread_t));
    Args *args = (Args*)malloc(p * sizeof(Args));

    for(int i = 0; i < p; i++){
        args[i].filename = argv[1 + i];
        args[i].num = i + 1;
    }

    for(int i = 0; i < p; i++){
        pthread_create(th + i, NULL, func, (void*)(args + i));
    }

    for(int i = 0; i < p; i++){
        pthread_join(th[i], NULL);
    }

    for(int i = 0; i < p; i++){
        if(!args[i].ret){
            printf("-%d\n", args[i].num);
        }
        else{
            printf("From %d count is = %d", args[i].num, args[i].count);
        }
    }


    free(th);
    free(args);
    return 0;
}