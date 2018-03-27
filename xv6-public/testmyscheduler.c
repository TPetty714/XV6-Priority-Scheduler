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

#define MAXNUMCHILDREN 10

void CleanupChildren();
int FindChild(int);
void PrintTestResult();

int childFinishRank[MAXNUMCHILDREN];
int childPids [MAXNUMCHILDREN];

int main(int argc, char* argv[])
{
    
    printf(1, "prioSet made it\n");
    
    
    // int status = -1;
    for(int i = 0; i < MAXNUMCHILDREN;i++){
        if((childPids[i] = fork() )> 0){
            // printf(1,"parent waiting; childPid: %d\n", childPids[i]);
            // status = wait(); 
            // printf(1,"parent waited %d\n",status);
            if(i == MAXNUMCHILDREN -1){
                CleanupChildren();
                PrintTestResult();
            }
            continue;
        }else{
            
            setpriority((50+MAXNUMCHILDREN) - i);
            for (int j = 0; j < 100000; j++){
                if(j%1000 == 0)
                    printf(0, "childNum: %d round: %d\n",i, j);
                // int x = 2147483647;
                int x = 1000000000;
                while (x > 0){
                    x = (int)(x/100000000000);
                    // sleep(1);
                    // printf(1,"x:%d", x);
                } 
            }
            printf(2,"FINSHED childNum %d\n", i);
            break;
        }
    }    
    exit();
}

void CleanupChildren(){
    int childReturn = -5;
    for(int i = 0; i <MAXNUMCHILDREN; i++){
        while((childReturn = wait()) < 0);
        printf(1,"Child wait recieved: %d\n", childReturn);
        int childIndex = FindChild(childReturn);
        childFinishRank[i] = childIndex;
    }
}

int FindChild(int childPid){
    int curPid = -12;
    for(int i = 0; i < MAXNUMCHILDREN; i++){
        curPid = childPids[i];
        if (curPid == childPid)
            return i;
    }
    return -12;
}

void PrintTestResult(){
    printf(1,"\n\n=================\n");
    printf(1,"TEST Description:\n");
    printf(1,"\tParent process creates 10 child processes which print to the screen every 1000 iterations.\n");
    printf(1,"\tWhen a child completes its work it gets added to a completition rank array.\n");
    printf(1,"\tResults a printed when all chid processes complete.\n");
    printf(1,"==========================================================\n");
    printf(1,"\n============\n");
    printf(1,"TEST RESULTS\n");
    printf(1,"============\n");
    for(int i = 0; i < MAXNUMCHILDREN; i++){
        printf(1,"Child: %d Rank: %d\n",childFinishRank[i], i);
    }
    printf(1,"========================\n");
}