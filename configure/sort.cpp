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
/*
冒泡排序的主要思想是一趟比较，相邻元素之间进行对比，遍历一遍，可以将一个最值元素沉底。
时间复杂度为O(n^2)，最好最坏都是如此
空间复杂度为O(1)
比较稳定
*/

void BubbleSort(int arr[], int size)
{
    checkParam(arr, size);
    for(int i=0; i<size; i++)
    {
        /*相邻元素进行比较，每次都找一个最值，放到队尾*/
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j] < arr[j+1]) 
                swapElement(arr[j], arr[j+1]);
        }
    }
    printArray(arr,size);
}

/*
选择排序：与冒泡排序对比，交换次数很少，走一趟只需要一次交换  
因为选择排序走一趟的目的是为了找到一个最值，然后进行交换。  
时间复杂度为O(n^2)，最好最坏都是如此  
空间复杂度为O(1)  
数组不稳定（涉及插入），链表稳定  
*/

void SelectSort(int arr[], int size)
{
    checkParam(arr, size);

    for (int i = 0; i < size; i++)
    {
        /*找到最值的下标*/
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        /*最后才交换位置*/
        swapElement(arr[min], arr[i]);
    }

    printArray(arr, size);
}

/*
插入排序，与冒泡和选择相比，插入排序不交换值，只是选择合适的位置。  
维护前面的顺序数组  
时间复杂度为O(n^2)，最好最坏都是如此  
空间复杂度为O(1)  
链表稳定  
*/

void InsertSort(int arr[], int size)
{
    checkParam(arr, size);

    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j = i - 1;

        /*维护已经排好序的数组*/
        while (j >= 0 && arr[j] > cur)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }

    printArray(arr, size);
}

/*
快速排序：找到一个标志位，使得左边的数据都小于这个标志数据，右边的数据都大于这个标志数据。  
然后对左边的数据，和右边的数据进行处理。
时间复杂度，在最坏情况下：O(n^2)，平均时间复杂度：O(NlogN,2为底)，平均复杂度，1.3NlogN  
空间复杂度，在最坏情况下：O(n)，平均时间复杂度：O(logN,2为底)  
不稳定  
*/

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

            /*把小于X的放在左边*/
            arr[flag] = arr[right];

            while (flag < right && arr[flag] < x)
                flag++;

            /*把大于X的放在右边*/
            arr[right] = arr[flag];
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

/*
堆排序：大顶堆（升序，小到大），小顶堆（降序，大到小）。  
大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  
然后对左边的数据，和右边的数据进行处理。
时间复杂度：平均 O(NlogN,2为底)  
空间复杂度：O(1)  
不稳定  
*/

void create_heap(int array[], int begin, int end)
{
    int son = begin * 2 + 1;
    int dad = begin;
    while (son <= end)
    {
        if (son + 1 <= end && array[son] < array[son + 1])
        {
            son++;
        }

        if (array[dad] > array[son])
            return;
        else
        {
            std::swap(array[dad], array[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int array[], int length)
{
    //参数判断
    //1.构建大顶堆
    for (int i = length / 2 - 1; i >= 0; i--)
    { 
        //从最后一个非叶子结点从下至上，从右至左调整结构
        create_heap(array, i, length - 1);
    }

    //2.调整堆结构+交换堆顶元素与末尾元素
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]); //将堆顶元素与末尾元素进行交换
        create_heap(array, 0, i - 1);  //重新对堆进行调整
    }

    printArray(array, length);
}

/*
希尔排序：插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法。  
设定分组，组内进行插入排序，逐渐减少分组。 
时间复杂度，在最坏情况下：O(n^2)，平均时间复杂度：O(N logN logN,2为底)   
空间复杂度：O(1)  
不稳定  
*/

void shell_sort(int array[], int length)
{
    /*步长设定为gap ， 每次除以2，逐渐缩小分组*/
    for (int gap = length >> 1; gap > 0; gap >>= 1)
    {
        cout << "gap : " << gap << endl;
        
        /*分组，插入排序*/
        for (int i = gap; i < length; i++)
        {
            int temp = array[i];
            int j = 0;
            for (j = i - gap; j >= 0 && array[j] > temp; j -= gap)
            {
                array[j + gap] = array[j];
            }

            array[j + gap] = temp;
        }
    }

    printArray(array, length);
}

/*
归并排序：采用分治法。先分，再合，合的过程中进行比较。  
归并排序是稳定排序，它也是一种十分高效的排序，能利用完全二叉树特性的排序一般性能都不会太差  
归并排序的最好，最坏，平均时间复杂度均为O(nlogn)  
空间复杂度为O(N)  
稳定  
*/
void merge_sort_recursive(int *arr, int *reg, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    /*左边递归*/
    merge_sort_recursive(arr, reg, start1, end1);
    /*右边递归*/
    merge_sort_recursive(arr, reg, start2, end2);

    /*合并*/
    int k = start;
    while (start1 <= end1 && start2 <= end2)
    {
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }

    while (start1 <= end1)
    {
        reg[k++] = arr[start1++];
    }

    while (start2 <= end2)
    {
        reg[k++] = arr[start2++];
    }

    /*赋值操作*/
    for (k = start; k <= end; k++)
    {
        arr[k] = reg[k];
    }
}

void merge_sort(int *arr, const int length)
{
    /*避免在递归中，频繁开辟空间*/
    int *reg = new int[length];
    merge_sort_recursive(arr, reg, 0, length - 1);

    printArray(arr, length);
    delete[] reg;
}

int main()
{
    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //BubbleSort(arr,10);
    //QuickSort(arr,10);
    //heap_sort(arr,10);
    //shell_sort(arr,10);
    //SelectSort(arr,10);
    //InsertSort(arr,10);
    merge_sort(arr, 10);
    system("pause");
    return 0;
}
