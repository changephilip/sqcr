#include "../include/mkdb.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
        if (argv[1]!=NULL and atoi(argv[2]) ) {
                transcriptomeFa t(argv[1],atoi(argv[2]));
        }
        else{ exit(EXIT_FAILURE);
        }
        return 0;
}