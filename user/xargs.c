#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#define MAX_LEN 100

int main(int argc, char *argv[])
{
    char *command = argv[1];
    char bf;
    char param[MAXARG][MAX_LEN];
    char *m[MAXARG];

    while(1)
    {
        cnt == argv.size()
        int cnt = argc - 1;
        memset(param,0,MAX_LEN *MAXARG);
        for(int i = 1;i < argc ;++i)
            strcpy(param[i - 1],argv[i]);

        int cursor = 0;
        int flag = 0;
        int read_res ;
        //read from pipe or ...
        while((read_res = read(0,&bf,1)) > 0 && bf != '\n')
        {
            if(bf == ' ' && flag == 1)
            {
                //add to the last position
                cnt ++;
                cursor = 0;
                flag = 0;
            }
            else if(bf != ' ')
            {
                param[cnt][cursor++] = bf;
                flag = 1;
            }
        }
        // bf == '\n'
        if(read_res <= 0)
            break;
        for(int i = 0;i < MAXARG - 1; ++i)
            m[i] = param[i];
        m[MAXARG - 1] = 0;
        if(fork() == 0)
        {
            exec(command,m);
            exit(0);
        }
        else wait((int*)0);
    }
    exit(0);

}