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

void shell_sort(int array[], int length)
{
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1;
    }
    cout<<h<<endl;
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                std::swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }

    printArray(array, length);
}

void create_heap(int array[], int begin, int end)
{
    int son = begin * 2 + 1;
    int dad = begin;
    while(son<=end)
    {
        if (son+1 <= end && array[son] < array[son + 1])
        {
            son++;
        }
        
        if(array[dad] > array[son]) 
            return;
        else
        {
            std::swap(array[dad], array[son]);
            dad = son;
            son = dad*2+1;
        }

    }
}

void heap_sort(int array[], int length)
{
    //参数判断
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        create_heap(array, i, length - 1);
    }

    /**/
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]);
        create_heap(array, 0, i-1);
    }

    printArray(array, length);
}



int main()
{
    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //BubbleSort(arr,10);
    //QuickSort(arr,10);
    heap_sort(arr,10);
    //shell_sort(arr,10);
    //SelectSort(arr,10);
    //InsertSort(arr,10);
    system("pause");
    return 0;
}
