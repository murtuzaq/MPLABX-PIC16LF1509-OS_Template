/*
 * File:   main.c
 * Author: mquaizar
 *
 * Created on January 31, 2017, 10:30 AM
 */

#include <pic.h>
#include "projectOS.h"

//sample task functions;
void task1 (void);
void task2 (void);
void task3 (void);
void task4 (void);

//Task run counter;
int i = 0;
int j = 0;
int k = 0;
int l = 0;

//OS Semaphores to unlock task;
int8_t sema1 = 0;
int8_t sema2 = 0;
int8_t sema3 = 0;
int8_t sema4 = 0;


void main(void) {
    
    OS_AddThreads(task1, task2, task3, task4);
    
    OS_Launch();
    
    while(1)
    {
        OS_Scheduler();
    }
}

void task1(void)
{ 
    i++;
    
    if ( (i % 0x10) == 0)
        OS_Signal(&sema1);
}

void task2(void)
{ 
    if(OS_Wait(&sema1))
        return;
    
    if ( (j % 0x10) == 0)
        OS_Signal(&sema2);
    
    j++;
}

void task3(void)
{
    if(OS_Wait(&sema2))
        return;
    
    if ( (k % 0x10) == 0)
        OS_Signal(&sema3);
    k++;
}

void task4(void)
{   
    if(OS_Wait(&sema3))
        return;
    
    l++;
}
