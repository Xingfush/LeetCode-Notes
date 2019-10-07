/* 求数组中逆序对的个数 */

int InversePairsCore(int* array, int* copy, int start, int end){
    if(end-start<=1){
        copy[start] = array[start];
        return 0;
    }

    int mid = start + (end-start)/2;
    int left_half = inverse_pairs_core(copy, array, start, mid);
    int right_half = inverse_pairs_core(copy, array, mid, end);

    int count = 0, i = start, j = mid, k = start;
    while(i<mid && j<end){
        if(array[i]>array[j]){
            count += j-i;
            copy[k++] = array[j++];
        }
        else{
            copy[k++] = array[i++];
        }
    }

    while(i<mid){
        copy[k++] = array[i++];
    }
    while(j<end){
        copy[k++] = array[j++];
    }

    return left_half + right_half + count;
}

int CountInversePairs(int* array, int length){
    if(array==nullptr || length<=0)
        return 0;

    int* copy = new int[length];
    for(int i=0;i<length;i++){
        copy[i] = array[i];
    }

    int pairs = inverse_pairs_core(array, copy, 0, length);
    delete []copy;

    return pairs;
}
