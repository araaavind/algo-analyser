void quick_sort(int a[], int l, int r)
{
	if(l < r)
	{
		int q = lombutoPartition(a, l, r);
		//int q = hoarePartition(a, l, r);
		quick_sort(a, l, q-1);
		quick_sort(a, q+1, r);
	}
}

int lombutoPartition(int a[], int l, int r)
{
	int x = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(a[j] <= x)
		{
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i + 1];
	a[i + 1] = a[r];
	a[r] = temp;
	return i + 1;
}

int hoarePartition(int a[], int l, int r)
{
    int pivot = a[l];
    int i = l - 1, j = r + 1;
  
    while (1)
    {
        // Find leftmost element greater than
        // or equal to pivot
        do
        {
            i++;
        } while (a[i] < pivot);
  
        // Find rightmost element smaller than
        // or equal to pivot
        do
        {
            j--;
        } while (a[j] > pivot);
  
        // If two pointers met.
        if (i >= j)
            return j;
  	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
    }
}
