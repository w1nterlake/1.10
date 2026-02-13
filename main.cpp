#include "header.h"


int main(int argc, char *argv[]){
    int p = argc - 1;
    pthread_t *th = (pthread_t*)malloc((p - 1) * sizeof(pthread_t));
    Args *args = (Args*)malloc(p * sizeof(Args));

    for(int i = 0; i < p; i++){
        args[i].filename = argv[1 + i];
        args[i].num = i + 1;
    }
    double cpu = get_full_time();
    for(int i = 1; i < p; i++){
        pthread_create(th + i - 1, NULL, func, (void*)(args + i));
    }

    func((void*)args);

    for(int i = 1; i < p; i++){
        pthread_join(th[i - 1], NULL);
    }
    
    cpu = get_full_time() - cpu;

    bool flag = true;

    for(int i = 0; i < p; i++){
        if(!args[i].ret2){
            printf("Num file %d is not correct\n", args[i].num);
            continue;
        }
        if(!args[i].ret){
            printf("-%d\n", args[i].num);
        }
        else{
            printf("From %d count is = %d, time = %lf\n", args[i].num, args[i].count, args[i].time);
        }
    }   
    printf("Full CPU time: %lf", cpu);

    free(th);
    free(args);
    return 0;
}