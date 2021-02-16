#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>

typedef void (sighandler_t)(int); /* type definition for return handler */
static jmp_buf return_to_level;            /* setup as global/static for sigsetjmp and siglongjmp */

/* signal handler */
void myhandler(int signo)
{
    siglongjmp (return_to_level, 1);
}


int safeWrite(int* ptr, int val)
{
  signal(SIGSEGV, myhandler);
  /* call signal and keep old handler */
  if (setjmp (return_to_level) == 0){
    if(ptr == NULL){
    return(1);
      }
    *ptr = val;
    return(0);
    }
    return(1);
}