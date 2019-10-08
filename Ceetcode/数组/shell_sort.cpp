void ShellSort(int* array, int length){
    int gap = length/2;
    while(gap){
        for(int i=gap;i<length;i++){
            int temp = array[i];
            while(i>gap && array[i-gap]>temp){
                array[i] = array[i-gap];
                i -= gap;
            }
            array[i] = temp;
        }
        gap /= 2;
    }
}