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
    
    int sortedFlag = 1;
    double time = 0;
    
    //error message if there are less than two inputs
    if (argc < 2) {
        cerr << "Error. Please input the length of the array and the datatype. :)" << endl;
        return 1;
    }
    
    //set a flag if "run" is input
    int flag = 0;
    if (argc == 4){
        flag = 1;
    }
    
    //generate a random array of a given length
    int arrayLength = atoi(argv[1]);
    string arrayType = argv[2];
    
    //for integers
    if(arrayType.compare("int")==0){
        int *intArray = new int[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            intArray[i] = rand();
        }
        clock_t startTime = clock();
        quickSort(intArray,arrayLength,sizeof(int),compareInt);
        clock_t endTime = clock();
        time = double(endTime - startTime)/(CLOCKS_PER_SEC);
        
        //want to check sortedness before deleting
        if (flag == 1) {
            for (int j = 0; j < arrayLength-1; j++) {
                if (intArray[j] > intArray[j+1]){
                    sortedFlag = 0;
                }
            }
        }
        
        delete [] intArray;
    }
    
    //for doubles
    else if(arrayType.compare("double") == 0){
        double *doubleArray = new double[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            doubleArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(doubleArray,arrayLength,sizeof(double),compareDouble);
        clock_t endTime = clock();
        time = double(endTime - startTime)/(CLOCKS_PER_SEC);
        
        delete [] doubleArray;
    }
    
    //for floats
    else if(arrayType.compare("float") == 0){
        float *floatArray = new float[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            floatArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(floatArray,arrayLength,sizeof(float),compareFloat);
        clock_t endTime = clock();
        time = double(endTime - startTime)/(CLOCKS_PER_SEC);

        delete [] floatArray;
    }
    
    //for longs
    else if(arrayType.compare("long") == 0){
        long *longArray = new long[arrayLength];
        for (int i = 0;i < arrayLength; i++){
            longArray[i] = rand()/RAND_MAX;
        }
        clock_t startTime = clock();
        quickSort(longArray,arrayLength,sizeof(long),compareLong);
        clock_t endTime = clock();
        time = double(endTime - startTime)/(CLOCKS_PER_SEC);

        delete [] longArray;
    }
    //for coordinate points structure
    
    else  {
        cout << "Error. Please input a correct datatype." << endl;
    }
    
    if (argc == 3) {
        string thirdParameter = argv[3];
        if (thirdParameter.compare("test") == 0) {
            cout << "It took " << time << " seconds to sort " << arrayLength << " items in an array with datatype " << arrayType << endl;
        }
        else if (thirdParameter.compare("run") == 0){
            if (sortedFlag == 0) {
                cout << "This array is not sorted. :(" << endl;
            }
            else if (sortedFlag == 1){
                cout << "This array is sorted! :)" << endl;
            }
        }
    }
    
}