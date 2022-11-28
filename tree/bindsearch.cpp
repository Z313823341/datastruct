
/**
 *  bindsearch
 * 二分查找
 **/

 
typedef int elemtype;

typedef struct{
	int length;
	int elemtype[];	
}*list;

int bindsearch(list tbl,elemtype k){
 	
 	int left,right,mind,notfound = -1;
 	left = 1;
 	right = tbl->length;
 	while(left<=right){  //判断条件，左边界和右边界重合时结束循环
	  mind = (left+right)/2; 
	  if(tbl->elemtype[mind]<k){
	  	left = mind+1;
	  }else if(tbl->elemtype[mind]>k){
	  	right = mind-1;		
	  }else return mind;
	  	
	 }
 	return notfound;
 	
}
