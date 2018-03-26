#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "uproc.h"


int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_getprocs(void)
{
  return getprocs();
}

int sys_setpriority(void){
  cprintf("setpriority!!!1\n");
  int oldPriority = -23;
  int newPriority = -23;
  oldPriority = proc->priority;
  cprintf("oldpriority of %s: %d\n", proc->name, oldPriority);
  cprintf("newpriority pre-arg: %d\n", newPriority);
  argint(0, &newPriority);
  cprintf("newpriority arg: %d\n", newPriority);
  if(newPriority > 200)
    newPriority = 200;
  else if(newPriority < 0)
    newPriority = 0;
  proc->priority = newPriority;
  cprintf("proc %s priority changed; new priority: %d\n",proc->name, proc->priority);

  return 0;
}