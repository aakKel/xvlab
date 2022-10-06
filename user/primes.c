#include "kernel/types.h"
#include "user/user.h"

#define RD 0
#define WR 1
#define MAXNUM 35

void neighbor(int *p);

int main(int argc,char *argv[])
{
    int p[2];
    pipe(p);

    if(fork() == 0)
    {
        neighbor(p);
    }
    else
    {
        close(p[RD]);
        for(int i = 2;i <= MAXNUM; ++i)
        {
            write(p[WR],&i,sizeof(int));
        }
    }
}

void neighbor(int *p)
{

}