void ReverseString(char* start, char* end){
    if(!start || !end) return;
    while(start<end){
        swap(*start++,*end--);
    }
}

char* ReverseSentence(char* strings){
    if(strings== nullptr)
        return nullptr;
    char *start = strings, *end = strings;
    while(*end!='\0')
        end++;
    end--;
    ReverseString(start,end);
    end = strings;
    while(*start!='\0'){
        if(*start==' '){ // 用来应对出现两个空格的异常情况
            start++,end++;
        } else if(*end==' ' || *end=='\0'){
            ReverseString(start,--end);
            start=++end;
        } else{
            end++;
        }
    }

    return strings;
}
