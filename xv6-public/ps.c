#include "types.h"
#include "fs.h"
#include "stat.h"
#include "user.h"
#include "uproc.h"

int main(int argc, char* argv[])
{
    // int i;
    //
    // if(argc < 2){
    //   ls(".");
    //   exit();
    // }
    // for(i=1; i<argc; i++)
    //   ls(argv[i]);
    struct uproc table[64];
    getprocs(48,table);
    exit();
}
