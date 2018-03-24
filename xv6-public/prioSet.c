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
    printf("prio set\n");
    exit();
}
