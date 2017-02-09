#include "test.h"

#include <numeric>
#define SIZE 12

template <typename T>
void sort(T* arr) {
    for (int gap = SIZE/2; 0<gap; gap/=2) 
        for (int i=gap; i<SIZE;i++)
            for (int j=i-gap; 0<=j; j-=gap)
                if (arr[j+gap]<arr[j]) 
                    std::swap(arr[j], arr[j+gap]);
}

int main(int argc, char const *argv[])
{
    int nums[SIZE] = {23,12,56,87,34,99,22,23,59};
    sort(nums);
    for (int& i: nums) std::cout << i << '\t';
    return 0;
}