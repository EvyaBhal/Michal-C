//
// Created by evyat on 7/25/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef
typedef int (*Compare)(void*, void*);
typedef struct s{
    int id;
    char* name;
}Student;
void mybsort(void* a[], int n, Compare cmp) {
    int i, j, k;

    for (i = n-1; i > 0; i--) {
        for (j = 0; j < i; j++) {

            if (cmp(a[j] , a[j + 1])>0) {//to functions the '>'

                void* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

            }
        }
    }
}
int compareInt(void* a, void* b){ //compares 2 ints -1 lvalue is prior. 0 equal, 1 rvalue prior

    if( *((int *) a) < *((int*)b))
        return -1;
    else if( *((int *) a) > *((int*)b))
        return 1;
    return 0;
}
int compareStudents(void* a, void* b){
    Student* A= ((Student*)a);
    Student*  B= ((Student*)b);
    if((A->id < B->id)&&(strcmp(A->name, B->name)<0)){
        return -1 ;
    }

}
void swap(void* a, void* b){
    void* temp = a;
    a = b;
    b = temp;
}
void printList( void* head,int size, (void)(*Print)(void*)){
    for (int i = 0; i < size; ++i){
        Print(head[i]);
    }
}
void printStudent(void* a){
    Student* s = (Student*)a;
    printf("%d",s->id);

}

int main(){

    int i, k, *r;
    void* a[128];

    FILE* f = fopen("integers.dat","r");
    for(i = 0 ; i < 128; ++i){
        fscanf(f,"%d",&k);
        r= (void*) malloc(sizeof(int));
        *r = k;
        a[i] = r;
    }

    //printf("main got here\n");
    mybsort(a, 128, compareInt);
    fclose(f);

    for(i =0 ; i < 128 ;++i){
        printf("%d\n", *((int*)a[i]));
    }
    return 0;
}
// s = 1 2 3 4

// w = 1 2 3 4

void grep(const char* fileName,const char* word){
    FILE* fp = fopen(fileName, "r");
    char line[1024];
    while(fgets(line,1024,fp)){
        if(strstr(line,word)){
            printf("%s",line);
        }
    }
}
