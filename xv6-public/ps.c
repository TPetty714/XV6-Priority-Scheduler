#include "types.h"
#include "x86.h"
// #include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "user.h"
#include "proc.h"
#include "uproc.h"

const char* getState(enum procstate state){
  switch (state) {
    case SLEEPING: return "SLEEPING";
    case RUNNING: return "RUNNING";
    case RUNNABLE: return "RUNNABLE";
    case ZOMBIE: return "ZOMBIE";
    case EMBRYO: return "EMBRYO";
    case UNUSED: return "UNUSED";
    default: return "UNKNOWN";
  }
}

int main(int argc, char* argv[])
{
    int max = 64;
    if (argc > 1) {
      printf(1, "%s\n", argv[1]);
      max = atoi(argv[1]);
    }
    if (max > 64) {
      printf(1,"max number of processes is 64, switching to 64\n");
      max = 64;
    }
    int numProc = 0;
    struct uproc table[max];
    numProc = getprocs(max, table);
    printf(1, "pid \t ppid \t state \t size \t name\n");
    for (int p = 0; p < max; p++) {
      if (table[p].pid != 0) {
        printf(1, "%d \t %d \t %s \t %d \t %s\n",
          table[p].pid,
          table[p].ppid,
          getState(table[p].state),
          table[p].sz,
          table[p].name);
      }
      // if ( table[p].state == SLEEPING )
      //   printf(1, "%s\t %d\t SLEEPING\t\n", table[p].name, table[p].pid);
      // else if ( table[p].state == RUNNING )
      //   printf(1, "%s\t %d\t RUNING\t\n", table[p].name, table[p].pid);
      // else if ( table[p].state == RUNNABLE )
      //   printf(1, "%s\t %d\t RUNNABLE\t\n", table[p].name, table[p].pid);
    }
    printf(1, "Total Processes printed: %d\n", numProc);
    // return numProc;
    // return 0;
    exit();
}
