#include "master.h"

static inline 
void checkParam(int arr[], int size)
{

    if (arr == nullptr || size == 0)
        return;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "第" << i << "个: " << arr[i] << endl;
    }
    return ;
}
void swapElement(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void BubbleSort(int arr[], int size)
{

    checkParam(arr, size);
    for(int i=0; i<size; i++)
    {
        /*每次都找一个最值，放到队尾*/
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j] < arr[j+1]) 
                swapElement(arr[j], arr[j+1]);
        }
    }
    printArray(arr,size);
}

void QuickHelp(int arr[], int begin, int end)
{
    if (begin<end)
    {
        int flag  = begin;
        int right = end;
        int x = arr[begin];

        /*找到标志位flag,使得左边的都小于x，右边的都大于x*/
        while (flag < right)
        {
            while (flag < right && arr[right] >= x)
                right--;
            if (flag < right)
            {
                arr[flag] = arr[right];
                flag++;
            }
            while (flag < end && arr[flag] < x)
                flag++;
            if (flag < right)
            {
                arr[right] = arr[flag];
                right--;
            }
        }

        arr[flag] = x;
        QuickHelp(arr, begin, flag - 1);
        QuickHelp(arr, flag + 1, end);
    }
    return;
}

void QuickSort(int arr[], int size)
{
    checkParam(arr, size);
    QuickHelp(arr, 0, size-1);
    printArray(arr, size);
}

void SelectSort(int arr[], int size)
{
    checkParam(arr, size);

    for(int i=0; i<size; i++)
    {
        /*找到最值的下标，然后互换位置*/
        int min = i;
        for(int j= i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }

        swapElement(arr[min], arr[i]);
    }

    printArray(arr, size);
}

void InsertSort(int arr[], int size)
{
    checkParam(arr, size);

    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j=i-1;

        /*维护已经排好序的数组*/
        while(j>=0 && arr[j]>cur)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=cur;
    }

    printArray(arr, size);
}

int commonHelper(int arr[], int value, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    /*没有找到*/
    if (low > high)
    {
        return -1;
    }
}
/*有序数组*/
int BinarySearch(int arr[], int length, int value)
{
    if (arr == NULL || length == 0)
        return -1;
    int low = 0;
    int high = length - 1;
    int ret = commonHelper(arr, value, low, high);
    ret = ret > 0 ? ret + 1 : -1;
    return ret;
}



int main()
{
    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //BubbleSort(arr,10);
    QuickSort(arr,10);
    //SelectSort(arr,10);
    //InsertSort(arr,10);
    system("pause");
    return 0;
}
