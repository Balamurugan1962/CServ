#include"utils.h"

#include<stdio.h>
#include<stdlib.h>

void raise_error(char* messege){
    fprintf(stderr,"%s\n",messege);
    exit(EXIT_FAILURE);
}
