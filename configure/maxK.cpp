#include "master.h"

static inline void checkParam(int arr[], int size)
{

    if (arr == nullptr || size == 0)
        return;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "µÚ" << i << "¸ö: " << arr[i] << endl;
    }
    return;
}

int quickGet(int arr[], int begin, int end)
{
    int ret = 0;
    if(begin<end)
    {
        int flag = begin;
        int right = end;
        int cur = arr[begin];
        while (flag < right)
        {
            while(right > flag && arr[right] >= cur) 
                right--;
            if(right>flag)
            {
                arr[flag] = arr[right];
                flag++;
            } 
            while(flag < end && arr[flag] < cur) 
                flag++;
            if(right > flag)
            {
                arr[right] = arr[flag];
                right--;
            }
        }
        arr[flag] = cur;
        ret = flag;
    }
    return ret;
}

void maxK(int arr[], int size, int k)
{
    checkParam(arr, size);
    if (k == 0)
        return ;
    int arrK[k];
    int index = quickGet(arr, 0, size - 1);
    while(index!=k)
    {
        if(index<k)
            index = quickGet(arr,index+1,size-1);
        else
            index = quickGet(arr,0,index-1);
    }

    /*???????????*/
    printArray(arr, size);

    int j =0;
    for(int i=0;i<k;i++)
    {
        if(arr[i]<arr[index])
        {
            arrK[j] = arr[i];
            j++;
        }
    }

    printArray(arrK, k);
    return ;
}


void maxKbyBubble(int arr[], int size, int k)
{
    int arrK[k];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<size-1-i; j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        arrK[i] = arr[size-1-i];
    }

    printArray(arrK, k);
    return;
}

int main()
{

    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //maxK(arr, 10, 3);
    maxKbyBubble(arr, 10, 3);
    system("pause");
    return 0;
}