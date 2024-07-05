#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
#elif __linux__
  #include <unistd.h>
  void Sleep(unsigned int d) {
     usleep(d*1000);
  }
#endif

typedef unsigned int uint;
typedef int type;
/* "type" is defined like this
   for ease of change.

   Don't forget to change
   the format specifier in
   the "print_elements" function
   when changing the type!
*/

int is_sorted(type* arr, uint* l) {
    for (uint i=1; i<*l; i++)
        if (arr[i-1] > arr[i]) return 0;
    return 1;
}

void swap(type* a, type* b) {
    type c = *a;
    *a = *b;
    *b = c;
}

void mix_elements(type* arr, uint* l) {
    srand(time(NULL));
    int i1, i2;
    for (uint i=0; i<*l; i++) {
        i1 = rand()%*l;
        i2 = rand()%*l;
        swap(&arr[i1], &arr[i2]);
    }
}

void print_elements_nl(type* arr, uint* l) {
    for (uint i=0; i<*l; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void print_elements_cr(type* arr, uint* l) {
    for (uint i=0; i<*l; i++)
        printf("%d ", arr[i]);
    putchar('\r');
}


//--------------------------------------------

void BogoSort_Verbose(type* arr, uint* l, uint* i) {
    while(!is_sorted(arr, l)) {
        mix_elements(arr, l);
        (*i)++;
        print_elements_cr(arr, l);
        Sleep(300);
    }
}

void BogoSort_Quiet(type* arr, uint* l, uint* i) {
    while (!is_sorted(arr, l)) {
        mix_elements(arr, l);
        (*i)++;
    }
}

//--------------------------------------------

int main(void) {

    type arr[] = {3, 8, 2, 1};
    uint length = sizeof(arr)/sizeof(arr[0]);
    uint iterations = 0;
    printf("Original arrangement: ");
    print_elements_nl(arr, &length);

    BogoSort_Verbose(arr, &length, &iterations);
    //BogoSort_Quiet(arr, &length, &iterations);

    printf("\nDone in %u iterations(s).\nPress Enter to exit.\n", iterations);
    while (getchar()!='\n');
    return EXIT_SUCCESS;
}
