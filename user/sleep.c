#include "kernel/types.h"
#include "user/user.h"


int check(char *c)
{
    const char *p = c;
    for(;*p;p++)
    {
        if(*p <'0' || *p >'9')
            return -1;
    }
    return atoi(c);
}

int
main(int argc, char *argv[])
{
  if (argc != 2)
  {
    fprintf(2,"usage:sleep<time>\n");
    exit(1);
  }
  sleep(check(argv[1]));
  exit(0);
}