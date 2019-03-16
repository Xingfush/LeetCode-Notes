def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
    # construct dictionary using list 1 
    dic1={s:i for i,s in enumerate(list1)}
    dic2={}
    
    res_sum = len(list1)+len(list2)
    
    for i,s in enumerate(list2):
        if s in dic1:
            temp_sum=dic1[s]+i
            dic2[temp_sum]=dic2.get(temp_sum,[])+[s]
            res_sum=min(temp_sum,res_sum)
    
    return dic2[res_sum]