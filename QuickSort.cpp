#include <vector>
using namespace std;

#define vInt vector<int>

void quirkSort(vInt &nums, int pivot, int low, int high, int len){
    int i, j, greaterSus, lowerSus, temp, tempIdx;
    i = low;
    j = high;
    if(high > pivot){
        lowerSus = low;
        greaterSus = high;
        while(i <= high){
            if(nums[i] > nums[pivot]){
                greaterSus = i;
                break;
            }
            i++;
        }
        while(j >= low){
            if(nums[j] < nums[pivot]){
                lowerSus = j;
                break;
            }
            j--;
        }
        if(i < j){
            temp = nums[greaterSus];
            nums[greaterSus] = nums[lowerSus];
            nums[lowerSus] = temp;
            quirkSort(nums, pivot, greaterSus+1, lowerSus-1, len);
        }
        else{
            if(nums[pivot] > nums[j]){
                temp = nums[pivot];
                nums[pivot] = nums[j];
                nums[j] = temp;
                tempIdx = pivot;
                pivot = j;
                low = tempIdx;
            }
            quirkSort(nums, low, low+1, pivot-1, pivot-1);
            quirkSort(nums, pivot+1, pivot+2, len, len);
        }
    }
}