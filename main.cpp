#include <iostream>

using namespace std;
size_t partition(void*,size_t,size_t,int(*)(const void*, const void*));
void swap(void*,void*,size_t);
//int compare(const void*, const void*);

void quickSort (void* arrayBase, size_t arraySize, size_t elementSize, int (*compar)(const void*,const void*)){
    
    if (arraySize <= 1){
        return;
    }
    
    size_t pivot = partition(arrayBase,arraySize,elementSize,compar);
    
    //quickSort(arrayBase)
    //quickSort(arrayBase)
}

size_t partition(void* arrayBase,size_t arraySize, size_t elementSize, int(*compar)(const void*,const void*)){
    
    char* arrayBaseChar = (char*)arrayBase;
    
    char* pivot = arrayBaseChar + ((arraySize - 1)*elementSize);
    size_t index = 0;
    
    for(int j = 0; j < arraySize;j++){
        if(compar(arrayBaseChar+(j*elementSize),pivot) <= 0){
            swap(arrayBaseChar+(j*elementSize),pivot,elementSize);
            index += 1;
        }
    }
    swap(arrayBaseChar+(index*elementSize),pivot,elementSize);
    return index;
}

void swap(void* a, void* b, size_t size){
    char temp[size];
    // C99, use malloc otherwise
    // char serves as the type for "generic" byte arrays
    //Swap function found at: http://stackoverflow.com/questions/2232706/swapping-objects-using-pointers
    
    memcpy(temp,b,size);
    memcpy(b,a,size);
    memcpy(a,temp,size);
}

int compare(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    return(*(int*)a - *(int*)b);
}

int main(int argc, char* argv[]){

    
}