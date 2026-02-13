#include "header.h"

double get_cpu_time()
{
  struct rusage buf;
  getrusage(RUSAGE_THREAD, &buf);
  return buf.ru_utime.tv_sec + buf.ru_utime.tv_usec /1.e6;
}

double get_full_time()
{
  struct timeval buf;
  gettimeofday(&buf, 0);
  return buf.tv_sec + buf.tv_usec / 1.e6;
}



void *func(void *arg){
    double t = get_cpu_time();
    Args *tmp = (Args *)arg;
    FILE *fin = fopen(tmp->filename, "r");
    int current, last, last_last;
    int count = 0, size = 0;
    bool ok = true;
    bool fl = true;
    if(fin == nullptr){
        ok = false;
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
        if(!feof(fin)){
            fl = false;
        }
    }
    tmp->count = count;
    tmp->size = size;
    tmp->ret = ok;
    tmp->ret2 = fl;
    if(ok){
        fclose(fin);
    }
    t = get_cpu_time() - t;
    tmp->time = t;
    return nullptr;
}