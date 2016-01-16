//Ally Warner
//Assignment 1
//High Performance Computing

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;
size_t partition(void*,size_t,size_t,int(*)(const void*, const void*));
void swap(void*,void*,size_t);

typedef struct _Point {
    double x;
    double y;
} Point;

void quickSort (void* arrayBase, size_t arraySize, size_t elementSize, int (*compar)(const void*,const void*)){
    
    if (arraySize > 0){
        
        size_t pivot = partition(arrayBase,arraySize,elementSize,compar);
        
        char* arrayBaseChar = (char*)arrayBase;
        
        
        quickSort(arrayBaseChar,pivot,elementSize,compar);
        quickSort(arrayBaseChar + (pivot+1)*elementSize,arraySize - (pivot+1),elementSize,compar);
        
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

int compareStructure(const void* a, const void *b) {
    Point da = *(Point *)a;
    Point db = *(Point *)b;
    if (da.y < db.y) return -1;
    if (db.y < da.y) return 1;
    if (da.y == db.y){
        if (da.x < db.x) return -1;
        if (db.x < da.x) return 1;
    }
    return 0;
}

int main(int argc, char* argv[]){
    
    string arrayLengthInput = " ";
    string arrayType = " ";
    
    cout << "Enter the length of a random array: \n> ";
    getline(cin,arrayLengthInput);
    
    cout << "Please enter the desired data type using the following notation (int, double, float, long or coordinate points: \n> ";
    getline(cin,arrayType);
    
    //generate a random array of length n
    int arrayLength = atoi(arrayLengthInput);
    
    //for integers
    if(arrayType.compare("int")){
        int *intArray = new int[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            intArray[i] = rand();
        }
        clock_t startTime = clock();
        quickSort(intArray,arrayLength,sizeof(int),compareInt);
        clock_t endTime = clock();
        double time = double(endTime - startTime)/(CLOCKS_PER_SEC);
        
        delete [] intArray;
    }
    
    //for doubles
    else if(arrayType.compare("double")){
        double *doubleArray = new double[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            doubleArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(doubleArray,arrayLength,sizeof(double),compareDouble);
        clock_t endTime = clock();
        double time = double(endTime - startTime)/(CLOCKS_PER_SEC);
        
        delete [] doubleArray;
    }
    
    //for floats
    else if(arrayType.compare("float")){
        float *floatArray = new float[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            floatArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(floatArray,arrayLength,sizeof(float),compareFloat);
        clock_t endTime = clock();
        double time = double(endTime - startTime)/(CLOCKS_PER_SEC);

        delete [] floatArray;
    }
    
    //for longs
    else if(arrayType.compare("long")){
        long *longArray = new long[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            longArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(longArray,arrayLength,sizeof(long),compareLong);
        clock_t endTime = clock();
        double time = double(endTime - startTime)/(CLOCKS_PER_SEC);

        delete [] longArray;
    }
    
    else  {
        cout << "Error. Please input a correct datatype." << endl;
    }
    
}