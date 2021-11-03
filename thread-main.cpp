// -----------------------------------------------------------
// NAME : Jade Wang                         User ID: jbwang
// DUE DATE : 11/03/2021
// PROGRAM ASSIGNMENT 3
// FILE NAME : thread-main.cpp
// PROGRAM PURPOSE :
//    Main program for prog3, meant to handle the execution and
//    Creation of threads to sort an input array with the
//    even-odd sorting algorithm, run concurrently.
// -----------------------------------------------------------
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include "thread.h"

using namespace std;

// -----------------------------------------------------------
// FUNCTION  main :
//     main function, creates all the threads for each set of
//     elements to be considered. Implements the even-odd
//     sorting algorithm.
// PARAMETER USAGE :
//
// FUNCTION CALLED :
//
// -----------------------------------------------------------
int main(int argc, char* argv[]) {
    char buf[100];
    int n;
    bool swapped = true;
    int j;
    int iter = 0;

    cout << "Concurrent Even-Odd Sort\n\n";
    cin >> n;
    cout << "Number of input data = " << n << endl;
    cout << "Input array:\n";

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "   " << A[i];
    }
    cout << endl;

    while(swapped) {
        iter++;
        sprintf(buf, "Iteration %d:\n", iter);
        write(1, buf, strlen(buf));
        swapped = false;
        //even pass
        sprintf(buf, "    Even Pass:\n");
        write(1, buf, strlen(buf));

        thread* even[n/2];
        j = 0;
        for (int i = 1; i < n; i += 2) {
            even[j] = new thread(i, A, &swapped);
            even[j]->Begin();
            j++;
        }
        for (int i = 0; i < j; i++) {
            even[i]->Join();
        }

        //odd pass
        sprintf(buf, "    Odd Pass:\n");
        write(1, buf, strlen(buf));

        thread* odd[n/2];
        j = 0;
        for (int i = 2; i < n; i+= 2) {
            odd[j] = new thread(i, A, &swapped);
            odd[j]->Begin();
            j++;
        }
        for (int i = 0; i < j; i++) {
            odd[i]->Join();
        }

        sprintf(buf, "Result after iteration %d:\n", iter);
        write(1, buf, strlen(buf));

        j = 0;
        for (int i = 0; i < n; i++) {
            sprintf(&buf[j], " %d", A[i]);
            j = strlen(buf);
            if (i % 19 == 0 && i != 0) {
                sprintf(&buf[j], "\n");
                j = strlen(buf);
            }
        }
        sprintf(&buf[j], "\n");
        write(1, buf, strlen(buf));
    }

    j = 0;
    sprintf(buf, "Final result after iteration %d:\n", iter);
    write(1, buf, strlen(buf));

    for (int i = 0; i < n; i++) {
        sprintf(&buf[j], "   %d", A[i]);
        j = strlen(buf);
        if (i % 19 == 0 && i != 0) {
            sprintf(&buf[j], "\n");
            j = strlen(buf);
        }
    }
    sprintf(&buf[j], "\n");
    write(1, buf, strlen(buf));

}