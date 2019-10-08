int Partition(int* array, int start, int end){
    int left = start, right = end;
    int pivot = array[end];
    while(left<right){
        while(left<right && array[left]<pivot)
            left++;
        while(left<right && array[right]>=pivot)
            right--;
        if(left<right)
            swap(array[left],array[right]);
    }
    swap(array[right],array[end]);
    return right;
}

int MedianOfArray(int* array, int length){
    int k = (length-1)/2;
    int left = 0, right = length-1;
    int res = 0;
    while(true){
        int q = Partition(array, left, right);
        if(q==k){
            res = array[q];
            break;
        }else if(q<k){
        	left = q+1;
        }else{
            right = q-1;
        }
    }

    return res;
}


// C++优先队列默认是大顶堆，也就是队头元素最大，这里将其变为小顶堆

int MedianOfArray(int* array, int length){
    int half = (length-1)/2;
    priority_queue<int, vector<int>, greater_equal<int>> q;

    for(int i=0;i<half;i++)
        q.push(array[i]);
    for(int i=half;i<length;i++){
        if(array[i]>q.top()){
            q.pop();
            q.push(array[i]);
        }
    }
    
    return q.top();
}