//
// Created by A on 6/16/2020.
//
#include <stdio.h>
#include <stdlib.h>
#define NUM_ARGS 4

typedef enum r{A,C,G,T} RNA;
int main(int argc, char* argv[]){
    if(argc != NUM_ARGS){
        printf("Error: wrong number of arguments.\n");
        exit(1);
    }
    if(strcmp(argv[1],"--zip")==0){
        zip(argv[2],argv[3]);
        exit(1);
    }
    else if(strcmp(argv[1],"--unzip")==0){
        unzip(argv[2],argv[3]);
    }
    printf("Error: wrong flag\n");
    exit(2);
    return 0;

}