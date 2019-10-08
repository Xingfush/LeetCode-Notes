void Heapify(int* array, int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(left<n && array[left]>array[largest])
        largest = left;
    if(right<n && array[right]>array[largest])
        largest = right;
    if(largest!=i){
        swap(array[i],array[largest]);
        Heapify(array, n, largest);
    }
}

void HeapSort(int* array, int length){
    if(array==nullptr || length<1)
        return;
    for(int i=length/2;i>=0;i--)
        Heapify(array, length, i);
    for(int n=length;n>0;n--){
        swap(array[n-1],array[0]);
        Heapify(array, n-1, 0);
    }
}