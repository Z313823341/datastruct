
/**
 *  bindsearch
 * ���ֲ���
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
 	while(left<=right){  //�ж���������߽���ұ߽��غ�ʱ����ѭ��
	  mind = (left+right)/2; 
	  if(tbl->elemtype[mind]<k){
	  	left = mind+1;
	  }else if(tbl->elemtype[mind]>k){
	  	right = mind-1;		
	  }else return mind;
	  	
	 }
 	return notfound;
 	
}
