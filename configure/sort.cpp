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
ʱ�临�Ӷ�ΪO(n^2)�������������
�ռ临�Ӷ�ΪO(1)
�Ƚ��ȶ�
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
ʱ�临�Ӷ�ΪO(n^2)�������������  
�ռ临�Ӷ�ΪO(1)  
���鲻�ȶ����漰���룩�������ȶ�  
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
ʱ�临�Ӷ�ΪO(n^2)�������������  
�ռ临�Ӷ�ΪO(1)  
�����ȶ�  
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
���ȶ�  
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
���ȶ�  
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
ϣ�����򣺲��������һ�ָ���Ч�ĸĽ��汾��ϣ�������Ƿ��ȶ������㷨��  
�趨���飬���ڽ��в��������𽥼��ٷ��顣 
ʱ�临�Ӷȣ��������£�O(n^2)��ƽ��ʱ�临�Ӷȣ�O(N logN logN,2Ϊ��)   
�ռ临�Ӷȣ�O(1)  
���ȶ�  
*/

void shell_sort(int array[], int length)
{
    /*�����趨Ϊgap �� ÿ�γ���2������С����*/
    for (int gap = length >> 1; gap > 0; gap >>= 1)
    {
        cout << "gap : " << gap << endl;
        
        /*���飬��������*/
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
�鲢���򣺲��÷��η����ȷ֣��ٺϣ��ϵĹ����н��бȽϡ�  
�鲢�������ȶ�������Ҳ��һ��ʮ�ָ�Ч��������������ȫ���������Ե�����һ�����ܶ�����̫��  
�鲢�������ã����ƽ��ʱ�临�ӶȾ�ΪO(nlogn)  
�ռ临�Ӷ�ΪO(N)  
�ȶ�  
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
    /*��ߵݹ�*/
    merge_sort_recursive(arr, reg, start1, end1);
    /*�ұߵݹ�*/
    merge_sort_recursive(arr, reg, start2, end2);

    /*�ϲ�*/
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

    /*��ֵ����*/
    for (k = start; k <= end; k++)
    {
        arr[k] = reg[k];
    }
}

void merge_sort(int *arr, const int length)
{
    /*�����ڵݹ��У�Ƶ�����ٿռ�*/
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
