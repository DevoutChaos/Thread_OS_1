/* 
 * File:   main.c
 * Author: 014909269
 *
 * Created on September 2, 2015, 6:02 PM
 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
//#include <stdlib.h>

static void *child(void *ignored)
{
    sleep(3);
    printf("Child is done sleeping 3 seconds. \n");
    return NULL;
}

int main(int argc, char *argv[]) 
{
    char input;
    int x = 1;
    pthread_t child_thread;
    int code;
    
    code = pthread_create(&child_thread, NULL, child, NULL);
    if (scanf("%c"))
    {
    while (x == 1)
    {
        if (code)
        {
            fprintf(stderr, "pthread_create failed with code %d\n", code);
        }
        sleep(5);
        
        printf("Parent is done sleeping (5 Seconds.) \n");
        if (input != NULL)
        {
            x = 2;
        }
    }
    }
    
    return 0;
}

