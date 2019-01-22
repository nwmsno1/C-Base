#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
        FILE *pf;
        int errnum;
        pf = fopen("unexist.txt", "rb");
        if(pf==NULL)
        {
                errnum = errno;
                fprintf(stderr, "errnum: %d\n", errno);
                perror("Output error through perror");
                fprintf(stderr, "open file error: %s\n", strerror(errnum));
        }
        else
        {
                fclose(pf);
        }
        return 0;
}
