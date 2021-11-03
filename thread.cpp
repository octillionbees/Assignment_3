// -----------------------------------------------------------
// NAME : Jade Wang                         User ID: jbwang
// DUE DATE : 11/03/2021
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.cpp
// PROGRAM PURPOSE :
//    Implementation file for member functions of class thread.
// -----------------------------------------------------------

#include "thread.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
using namespace std;

// -----------------------------------------------------------
// FUNCTION  thread :
//     constructor for new thread object
// PARAMETER USAGE :
//    pos = position of element k for thread to examine
//    A = pointer to beginning of data array
//    flag = pointer to boolean flag that checks whether a swap
//           has been made on a given iteration.
// FUNCTION CALLED :
//
// -----------------------------------------------------------
thread::thread(int pos, int *A, bool *flag) : i(pos), a(A), swapped(flag)
{
    char buf[100];
    sprintf(buf, "        Thread %d Created\n", pos);
    write(1, buf, strlen(buf));
}

// -----------------------------------------------------------
// FUNCTION  ThreadFunc :
//     implementation of code to be run by thread
// PARAMETER USAGE :
//
// FUNCTION CALLED :
//
// -----------------------------------------------------------
void thread::ThreadFunc() {
    Thread::ThreadFunc(); //required
    int temp;
    char buf[100];

    sprintf(buf, "        Thread %d compares x[%d] and x[%d]\n", i, i-1, i);
    write(1, buf, strlen(buf));

    if (a[i - 1] > a[i]) {
        sprintf(buf, "        Thread %d swaps x[%d] and x[%d]\n", i, i-1, i);
        write(1, buf, strlen(buf));

        temp = a[i-1];
        a[i-1] = a[i];
        a[i] = temp;
        *swapped = true;
    }

    sprintf(buf, "        Thread %d exits\n", i);
    write(1, buf, strlen(buf));

    Exit();
}