#ifndef UPROC_H
#define UPROC_H
#include "types.h"
struct uproc {
    int pid;
    int ppid;
    int state;
    uint sz;
    char name[16];
};
#endif
