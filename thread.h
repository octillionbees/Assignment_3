// -----------------------------------------------------------
// NAME : Jade Wang                         User ID: jbwang
// DUE DATE : 11/03/2021
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread.h
// PROGRAM PURPOSE :
//    header file and definition for thread class.
// -----------------------------------------------------------
#include "ThreadClass.h"

#ifndef ASSIGNMENT_3_THREAD_H
#define ASSIGNMENT_3_THREAD_H
class thread : public Thread {
public:

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
    thread(int pos, int* A, bool* flag);

private:
    int i;
    int *a;
    bool *swapped;

// -----------------------------------------------------------
// FUNCTION  ThreadFunc :
//     implementation of code to be run by thread
// PARAMETER USAGE :
//
// FUNCTION CALLED :
//
// -----------------------------------------------------------
    void ThreadFunc();
};


#endif //ASSIGNMENT_3_THREAD_H
