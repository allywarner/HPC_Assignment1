#include <iostream>

using namespace std;
size_t partition(void*,size_t,size_t,int(*)(const void*, const void*));
void swap(void*,void*,size_t);
//int compare(const void*, const void*);

void quickSort (void* arrayBase, size_t arraySize, size_t elementSize, int (*compar)(const void*,const void*)){
    cout << arraySize << endl;
    
    if (arraySize <= 1){
        return;
    }
    
    size_t pivot = partition(arrayBase,arraySize,elementSize,compar);
    //cout << pivot << ", " << arraySize << endl;
    
    char* arrayBaseChar = (char*)arrayBase;
    
    quickSort(arrayBaseChar,pivot-1,elementSize,compar);
    quickSort(arrayBaseChar + (pivot+1)*elementSize,arraySize - (pivot+1),elementSize,compar);
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

int compareInt(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    return(*(int*)a - *(int*)b);
}

int compareDouble(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    return(*(double*)a - *(double*)b);
}

int compareLong(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    return(*(long*)a - *(long*)b);
}

int compareFloat(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    return(*(float*)a - *(float*)b);
}

//int compareStructure

int main(int argc, char* argv[]){

    int intArray[] = {2,5,8,1,9,4,7,3,6};
    size_t intArraySize = sizeof(intArray)/sizeof(int);
    quickSort(intArray,intArraySize,sizeof(int),compareInt);
    
    for(auto n:intArray){
        cout << n << " ";
    }
    cout << endl;
    
}