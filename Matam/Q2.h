//
// Created by evyat on 8/27/2020.
//

#ifndef MICHAL_C_Q2_H
#define MICHAL_C_Q2_H
typedef struct DoubleNode{
    void* data;
    struct DoubleNode* next;
    struct DoubleNode* prev
}Node;
typedef Node* pNode;
typedef sturct DoubleLinkedList{
    bool (*Cmp)(void*,void*);
    void* (*Cpy)(void*);
    void(*del)(void*)
    pNode head;
}DLL;
typedef DLL* pDLL;

pDLL Create(bool (*Cmp)(void*,void*), void* (*Cpy)(void*),void(*del)(void*) );
void DestroyDLL(pDLL list);
void AddToDLL(void* elem, pDLL list);
void DeleteElem(void* elem, pDLL list);
bool FindInDLL(void* elem, pDLL list);
unsigned int size(pDLL list);
void* getNval(int n, pDLL list);


#endif //MICHAL_C_Q2_H



pDLL Create(bool (*Cmp)(void*,void*), void* (*Cpy)(void*),void(*del)(void*) ){
    pDLL dll = (pDLL) malloc(sizeof(DLL));
    dll->Cmp = Cmp;
    dll->Cpy = Cpy;
    dll->del = del;
    dll->head = NULL;
    return dll;

}

void DeleteElem(void* elem, pDLL list){

    pNode node;

    for(node = list->head; node != NULL ;node = node->next){
        if(Cmp(node->data, elem))
            break;
    }
    if(!node) return;
    if(node == list->head){
        list->head = node->next;
        // check something.. - if we had only 1 element in the list - node->head = NULL. we cant access ->prev.
        if(list->head)
            list->head->prev = NULL;
    }
    else{
        node->prev->next = node->next;
        // if node is the last element in the list.. we cant access node->next->prev
        if(node->next)
            node->next->prev = node->prev;

    }
    list->del(node->data);
    free(node);

}

typedef unsigned int uint;
uint compress_uint(char* arr, int size){
    uint res = 0;
    int i;
    for( i=0 ; i <size; ++i){
        if(arr[i]=='1'){
            res <<=1;
        }
        else{
            res<<=0;
        }
    }
    return res;
}

//arr = [ '0', '1', '1', '1',0 0 0 0  ..] = size = 20
//res =000000000000 0111....
//1. res = 0000000000000000000000000000000000000000001110000 (assumed 32)


uint* compress_array(char* arr, int size){
    int IntSize = size / sizeof(uint)*8;
    if(size % sizeof(uint)*8 != 0){
        IntSize++;
    }
    uint* res = (uint*) malloc(sizeof(uint)*IntSize);
    int i;
    for(i = 0; i < IntSize; ++i){
        int n = (size-(i*32) > 32? 32 : (size-(i*32);
        res[i] = compress_uint(arr+(i*32),n);
    }
    return res;
}
//size = 210;


void wc(const char* fileName){
    FILE* fp = fopen(fileName, "r");

    uint lines =0,words = 0,characters = 0;
    char* buff;
    int size;
    while(getline(buff, &size, fileName)>0){
        ++lines;
        characters+= strlen(buff);
        char* p;
        for(p = buff; *p != '\0'; ++p) {

            if (isspace(*p)) {
                ++words;
            }
        }
    }
    fclose(fp);
    printf(all the stuff);
}