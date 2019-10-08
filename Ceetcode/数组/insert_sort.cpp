void InsertSort(int* array, int length){
    for(int i=1;i<length;i++){
        int temp = array[i];
        while(i>0 && array[i-1]>temp){
            array[i] = array[i-1];
            i--;
        }
        array[i]=temp;
    }
}