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

static void *child(void *ignored) {
    int x = 1;

    while (x == 1) {
        sleep(5);
        printf("Child is done sleeping 5 seconds. \n");
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int y = 1;
    pthread_t child_thread;
    int code;
    char ch;

    code = pthread_create(&child_thread, NULL, child, NULL);

    if (code) {
        fprintf(stderr, "pthread_create failed with code %d\n", code);
    }

    while (y == 1) {
        scanf("%c", &ch);
        if (ch == '\n') {
            printf("Canceled");
            pthread_cancel(child);
            y = 0;
        }
    }
    return 0;
}