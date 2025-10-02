#include"../includes/utils.h"

#include<stdio.h>
#include<stdlib.h>

void raise_error(char* messege){
    fprintf(stderr,"%s\n",messege);
    exit(EXIT_FAILURE);
}

void raise_success(char *messege){
    fprintf(stdout,"%s\n",messege);
}
