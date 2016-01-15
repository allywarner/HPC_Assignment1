//Ally Warner
//Assignment 1
//High Performance Computing

#include <iostream>

using namespace std;
size_t partition(void*,size_t,size_t,int(*)(const void*, const void*));
void swap(void*,void*,size_t);

void quickSort (void* arrayBase, size_t arraySize, size_t elementSize, int (*compar)(const void*,const void*)){
    
    if (arraySize > 0){
        
        size_t pivot = partition(arrayBase,arraySize,elementSize,compar);
        
        char* arrayBaseChar = (char*)arrayBase;
        
        if (pivot!= 0){
            quickSort(arrayBaseChar,pivot,elementSize,compar);
            quickSort(arrayBaseChar + (pivot+1)*elementSize,arraySize - (pivot+1),elementSize,compar);
        }
    }
}

size_t partition(void* arrayBase,size_t arraySize, size_t elementSize, int(*compar)(const void*,const void*)){
    
    char* arrayBaseChar = (char*)arrayBase;
    
    char* pivot = arrayBaseChar + ((arraySize - 1)*elementSize);
    size_t index = 0;
    
    for(int j = 0; j < arraySize-1;j++){
        if(compar(arrayBaseChar+(j*elementSize),pivot) <= 0){
            swap(arrayBaseChar+(j*elementSize),arrayBaseChar+(index*elementSize),elementSize);
            index += 1;
        }
    }
    swap(arrayBaseChar+(index*elementSize),pivot,elementSize);
    return index;
}

void swap(void* a, void* b, size_t size){
    // C99, use malloc otherwise
    // char serves as the type for "generic" byte arrays
    //Swap function found at: http://stackoverflow.com/questions/2232706/swapping-objects-using-pointers
    char temp[size];
    memcpy(temp,b,size);
    memcpy(b,a,size);
    memcpy(a,temp,size);
}

int compareInt(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    int da = *(int*)a;
    int db = *(int*)b;
    if (da < db) return -1;
    if (db < da) return 1;
    return 0;
}

int compareDouble(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    double da = *(double*)a;
    double db = *(double*)b;
    if (da < db) return -1;
    if (db < da) return 1;
    return 0;
}

int compareLong(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    long da = *(long*)a;
    long db = *(long*)b;
    if (da < db) return -1;
    if (db < da) return 1;
    return 0;
}

int compareFloat(const void* a, const void* b){
    //compare function found at:http://www.cplusplus.com/reference/cstdlib/qsort/
    float da = *(float*)a;
    float db = *(float*)b;
    if (da < db) return -1;
    if (db < da) return 1;
    return 0;
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
    
    double doubleArray[] = {0.2,0.5,0.8,0.1,0.9,0.4,0.7,0.3,0.6};
    size_t doubleArraySize = sizeof(doubleArray)/sizeof(double);
    quickSort(doubleArray,doubleArraySize,sizeof(double),compareDouble);
    
    for(auto n:doubleArray){
        cout << n << " ";
    }
    cout << endl;
    
    float floatArray[] = {0.2,0.5,0.8,0.1,0.9,0.4,0.7,0.3,0.6};
    size_t floatArraySize = sizeof(floatArray)/sizeof(float);
    quickSort(floatArray,floatArraySize,sizeof(float),compareFloat);
    
    for(auto n:floatArray){
        cout << n << " ";
    }
    cout << endl;
    
    double longArray[] = {9223372036854775807, 5223372036854775807,3223372036854775807,1223372036854775807};
    size_t longArraySize = sizeof(longArray)/sizeof(long);
    quickSort(longArray,longArraySize,sizeof(long),compareLong);
    
    for(auto n:longArray){
        cout << n << " ";
    }
    cout << endl;

    
    
}