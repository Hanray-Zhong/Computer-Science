void Insertion_Sort(int a[],int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        int temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; --j)
            a[j] = a[j - 1];
        a[j] = temp;
    }
}

void Pubble(char a[], int m)
{
    int i,j;
    char t;
    for(i = 0; i < m - 1; i++)
    {
        for(j = 0; j < m - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
               t = a[j + 1];
               a[j + 1] = a[j];
               a[j] = t;
            }
        }
    }
    return;
}

void SelectionSort(int *num,int n)
{
    int i = 0;
    int min = 0;
    int j = 0;
    int tmp = 0;
    for(i = 0;i < n-1;i++)
    {
 	    min = i;
        for(j = i;j < n;j++) 
        {
	        if(num[min]>num[j])
	        {
	            min = j;
	        }
	    }
	    if(min != i) 
	    {
	        tmp = num[min];
	        num[min] = num[i];
	        num[i] = tmp;
	    }
    }
}


//构建大顶堆
void Heap(int a[], int i, int length)
{
	int Child;
	int temp;
	for( ; 2 * i + 1 < length; i = Child)
	{
		Child = 2 * i + 1;
		//得到子结点中大的结点
		if(Child < length - 1 && a[Child + 1] > a[Child])
				++Child;
		//把较大的子结点往上移动
		if(a[i] < a[Child])
		{
			temp = a[i];
			a[i] = a[Child];
			a[Child] = temp;
		}
		else
			break;
	}
}
//堆排序算法
void HeapSort(int a[], int length)
{
	int i;
	for(i = length/2 - 1; i >= 0; --i)
			Heap(a, i, length);
	//把第一个元素和当前的最后一个元素交换
	for(i = length - 1; i > 0; --i)
	{
		int t;
        t = a[0];
        a[0] = a[i];
        a[i] = t;
		Heap(a, 0, i);						//递归调整
	}
}
 