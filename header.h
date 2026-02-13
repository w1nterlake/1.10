#include <cstdio>
#include <cstdlib>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>


double get_cpu_time();

double get_full_time();



struct Args{
    int size = 0;
    int count = 0;
    char *filename = nullptr;
    bool ret = false;
    bool ret2 = false;
    int num = 0;
    double time = 0;
};


void *func(void *arg);
