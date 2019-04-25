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
/*
ð���������Ҫ˼����һ�˱Ƚϣ�����Ԫ��֮����жԱȣ�����һ�飬���Խ�һ����ֵԪ�س��ס�
�ռ临�Ӷ�ΪO(n^2)
*/

void BubbleSort(int arr[], int size)
{
    checkParam(arr, size);
    for(int i=0; i<size; i++)
    {
        /*����Ԫ�ؽ��бȽϣ�ÿ�ζ���һ����ֵ���ŵ���β*/
        for(int j=0; j<size-1-i; j++)
        {
            if(arr[j] < arr[j+1]) 
                swapElement(arr[j], arr[j+1]);
        }
    }
    printArray(arr,size);
}

/*
ѡ��������ð������Աȣ������������٣���һ��ֻ��Ҫһ�ν���  
��Ϊѡ��������һ�˵�Ŀ����Ϊ���ҵ�һ����ֵ��Ȼ����н�����  
ʱ�临�Ӷ�O(n^2)  
*/

void SelectSort(int arr[], int size)
{
    checkParam(arr, size);

    for (int i = 0; i < size; i++)
    {
        /*�ҵ���ֵ���±�*/
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        /*���Ž���λ��*/
        swapElement(arr[min], arr[i]);
    }

    printArray(arr, size);
}

/*
����������ð�ݺ�ѡ����ȣ��������򲻽���ֵ��ֻ��ѡ����ʵ�λ�á�  
ά��ǰ���˳������  
�ռ临�Ӷ�O(n^2)  
*/

void InsertSort(int arr[], int size)
{
    checkParam(arr, size);

    for (int i = 1; i < size; i++)
    {
        int cur = arr[i];
        int j = i - 1;

        /*ά���Ѿ��ź��������*/
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
���������ҵ�һ����־λ��ʹ����ߵ����ݶ�С�������־���ݣ��ұߵ����ݶ����������־���ݡ�  
Ȼ�����ߵ����ݣ����ұߵ����ݽ��д���
ʱ�临�Ӷȣ��������£�O(n^2)��ƽ��ʱ�临�Ӷȣ�O(NlogN,2Ϊ��)��ƽ�����Ӷȣ�1.3NlogN  
�ռ临�Ӷȣ��������£�O(n)��ƽ��ʱ�临�Ӷȣ�O(logN,2Ϊ��)  
*/

void QuickHelp(int arr[], int begin, int end)
{
    if (begin<end)
    {
        int flag  = begin;
        int right = end;
        int x = arr[begin];

        /*�ҵ���־λflag,ʹ����ߵĶ�С��x���ұߵĶ�����x*/
        while (flag < right)
        {
            while (flag < right && arr[right] >= x)
                right--;

            /*��С��X�ķ������*/
            arr[flag] = arr[right];

            while (flag < right && arr[flag] < x)
                flag++;

            /*�Ѵ���X�ķ����ұ�*/
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
�����򣺴󶥶ѣ�����С���󣩣�С���ѣ����򣬴�С����  
�󶥶ѣ�arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  
С���ѣ�arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  
Ȼ�����ߵ����ݣ����ұߵ����ݽ��д���
ʱ�临�Ӷȣ�ƽ�� O(NlogN,2Ϊ��)  
�ռ临�Ӷȣ�O(1)  
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
    //�����ж�
    //1.�����󶥶�
    for (int i = length / 2 - 1; i >= 0; i--)
    { 
        //�����һ����Ҷ�ӽ��������ϣ�������������ṹ
        create_heap(array, i, length - 1);
    }

    //2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
    for (int i = length - 1; i > 0; i--)
    {
        std::swap(array[0], array[i]); //���Ѷ�Ԫ����ĩβԪ�ؽ��н���
        create_heap(array, 0, i - 1);  //���¶Զѽ��е���
    }

    printArray(array, length);
}

/*
ϣ�����򣺴󶥶ѣ�����С���󣩣�С���ѣ����򣬴�С����  
Ȼ�����ߵ����ݣ����ұߵ����ݽ��д���
ʱ�临�Ӷȣ��������£�O(n^2)��ƽ��ʱ�临�Ӷȣ�O(NlogN,2Ϊ��)��ƽ�����Ӷȣ�1.3NlogN  
�ռ临�Ӷȣ��������£�O(n)��ƽ��ʱ�临�Ӷȣ�O(logN,2Ϊ��)  
*/

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




int main()
{
    int arr[10] = {23, 12, 31, 45, 32, 1, 4, 13, 45, 90};
    //BubbleSort(arr,10);
    QuickSort(arr,10);
    //heap_sort(arr,10);
    //shell_sort(arr,10);
    //SelectSort(arr,10);
    //InsertSort(arr,10);
    system("pause");
    return 0;
}
