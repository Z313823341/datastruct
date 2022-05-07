/**
 * 
 * 已知la和lb，判断lb是否是la的连续子序列
 * 
 **/
  
  #include<stdio.h>
  #include<iostream>
  #include <string>
  using namespace std;
  typedef int elemtype;
  
  typedef struct lnode{
  	
  	elemtype data;
  	
  	lnode *next;
  	
  }lnode, *Linklist;

  
  /**
   * 尾插法建立单链表
   **/
  Linklist createListEnd(Linklist &L, int a[],int length){
  	
  	L = (Linklist)malloc(sizeof(lnode));
  	
  	lnode *r = L;
  	
  	for(int i=0;i<length;i++){
  		
  		lnode *s = (lnode *)malloc(sizeof(lnode));
  		
  		s->data = a[i];
  		
  		r->next = s;
  		
  		r = s;
 	 	
 	 }
  	r->next = NULL;
  	
    	return L;
  }
  
  //打印List的节点
  void prinList(Linklist L){
  	lnode *p = L->next;
  	while(p!=NULL){
  		printf("%d ",p->data);
  		p = p->next;
  	}
  	printf("\n");
  } 
  /**
   * 思想：从第一个结点开始比较，若相等，则a和b后移，
   * 若不相等，从A的开始比较结点的下一个结点开始比较，从b的第一个结点开始比较
   * 若b比较到表尾，说明b是a 的连续子序列
   * 否则不是
   * 
   **/
   string search_first(Linklist la,Linklist lb){
   	
   	lnode *pa = la->next,*pre = la->next;
   	lnode *pb = lb->next;
   	while(pb&&pa){
	   	if(pb->data==pa->data){
	   	printf("%d",pa->data);
	   	printf("%d\n",pb->data);
		   	pa = pa->next;
		   	pb = pb->next;
		   } 
		   else{
		   	printf("%d",pa->data);
		   	printf("%d\n",pb->data);
		   	pb = lb->next;
		   	pre = pre->next;
		   	pa = pre;
		   	
		   }
	   }
   	if(pb==NULL){
	   	return "true";
	   }
   	else return "false";
   }
    
   int main(){
   	
   	int a[] = {1,3,5,6,7,8,9,10,11,12};
   	int b[] = {5,6,7,8,9};
   	Linklist la = createListEnd(la,a,sizeof(a)/sizeof(a[0]));
   	Linklist lb= createListEnd(lb,b,sizeof(b)/sizeof(b[0]));
   	prinList(la);
   	prinList(lb);
    cout<<search_first(la,lb);
   	
   }
   
     
