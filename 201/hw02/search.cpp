#include <ctime>
#include <iostream>
#include <algorithm>
#include <array>
#include <functional>
bool linearSearch(int arr1[], int arr2[], int size1, int size2){
    bool b;
    for(int i = 0; i < size2; i++){
        b = false;
        for (int j = 0; j < size1; j++){
            if(arr2[i] == arr1[j]){
                b = true;
            }
        }
        if(!b){
            return false;
        }
    }
    return true;
}
//from book page 70
int binarySearch(int arr[], int low, int high, int key){
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || key > arr[mid - 1]) && (arr[mid] == key)){
            return mid;
        }
        else if (key > arr[mid]){
            return binarySearch(arr, (mid + 1), high, key);
        }

        else{
            return binarySearch(arr, low, (mid - 1), key);
        }
    }
    return -1;
}
bool isSubsetByBinarySearch(int arr1[], int arr2[], int size1, int size2){
    bool b = false;
    for(int i = 0; i < size2; i++){
        if(binarySearch(arr1, 0, size1 - 1, arr2[i]) == -1){
            return false;
        }
    }
    return true;
}
int findMaxInArr(int arr[], int size){
    int maxi = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}
bool isSubsetByFrequency(int arr1[], int arr2[], int size1, int size2){
    int maxi = findMaxInArr(arr1, size1);
    int* frequencyTable;
    frequencyTable = new int[maxi + 1]{0};
    for(int i = 0; i < size1; i++){
        frequencyTable[arr1[i]]++;
    }
    for(int i = 0; i < size2; i++){
        frequencyTable[arr2[i]]--;
        if(frequencyTable[arr2[i]] <= -1){
            return false;
        }
    }
    return true;
}




int main(){

    for(int k = 1; k < 11; k++){
        int sizeOfArr1 =100000 * k;
        double duration;
        int arr2[1000];
        int arr2_2[10000];

        //initialize arr2
        for(int i = 0; i < 1000; i++){
            arr2[i] = 10 * i;
        }

        //initialize arr2_2
        for(int i = 0; i < 10000; i++){
            arr2_2[i] = i;
        }

        int* arr1= new int[sizeOfArr1];
        for(int i=0 ; i<sizeOfArr1 ; i++){
          arr1[i]= rand()%10000;
        }


        std::cout<<"Experiment for arr1size = "<<sizeOfArr1<<std::endl;
        clock_t startTime = clock();
        //Code block
        linearSearch(arr1, arr2, sizeOfArr1, 1000);
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;

        startTime = clock();
        //Code block
        linearSearch(arr1, arr2_2, sizeOfArr1, 10000);
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;

        std::sort(arr1, arr1 + sizeOfArr1);

        startTime = clock();
        //Code block
        for(int i = 0; i < 1000; i++){
            isSubsetByBinarySearch(arr1, arr2, sizeOfArr1, 1000);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;

        startTime = clock();
        for(int i = 0; i < 1000; i++ ){
            //Code block
            isSubsetByBinarySearch(arr1, arr2_2, sizeOfArr1, 10000);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;
        startTime = clock();
        //Code block


        for(int i = 0; i < 100; i++){
            isSubsetByFrequency(arr1, arr2, sizeOfArr1, 1000);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;

        startTime = clock();
        //Code block
        for(int i = 0; i < 100; i++){
            isSubsetByFrequency(arr1, arr2_2, sizeOfArr1, 10000);
        }
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        std::cout << "Execution took " << duration << " milliseconds." << std::endl;
        delete[] arr1;
    }
    return 0;
}
