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
        cout << "��" << i << "��: " << arr[i] << endl;
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
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-1-i;j++)
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

        /*�ҵ���־λflag,ʹ����ߵĶ�С�������ұߵĶ�������*/
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


int main()
{
    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //BubbleSort(arr,0);
    QuickSort(arr,10);
    system("pause");
    return 0;
}
