#include <cstdio>
#include <cstdlib>
#include <pthread.h>

struct Args{
    int size = 0;
    int count = 0;
    char *filename = nullptr;
    bool ret = false;
    int num = 0;
};


void *func(void *arg);
