/**
 * 非循环双链表，每当执行locate（L,x）时，将freq加1，并使链表按freq递减排列
 **/
 
 
  #include<stdio.h>
  #include<iostream>
  #include<stdlib.h>
  #include <random>
  
  
  typedef int elemtype;
  typedef int freq;
  typedef struct dlnode{
  	elemtype data;
  	dlnode *front;
  	dlnode *next;
  	elemtype  freq;//访问频率
  }dlnode,*dlinklist;
  
  /**
   * 循环双链表建表操作
   **/
   
   dlinklist createDlinklist(dlinklist &dl,int a[],int length){
   	
   	dl = (dlinklist)malloc(sizeof(dlnode));
   	dl->next = dl;
   	dl->front = dl;
   	dlnode *p = dl; 	//r指向表尾结点
   	for(int i=0;i<length;i++){
 	  	dlnode *s = (dlnode *)malloc(sizeof(dlnode)); 
 	  	s->freq = 0;
 	  	s->data = a[i];
 	  	s->front = p;
 	  	p->next = s;
 	  	p = s;
 	  }
 	  p->next = NULL; //非循环双链表尾结点不指向表头，表头前驱不指向表尾
 	  //dl->front = p;
   	
   	return dl;
   }
   
   /**
    * 输出循环双链表的值
    **/
    void printfdlist(dlinklist dl){
    	dlnode *p = dl->next;
    	while(p!= NULL){
 	   	
 	   	printf("%d",p->data);
 	   	printf("%d ",p->freq);
 	   	p = p->next;
 	   }
    	printf("\n");
    }
    /**
	 * locate函数
	 **/
	 
	 dlnode* locate(dlinklist dl,int x){
	 	dlnode *p = dl->next;
	 	while(p){
		   if(p->data == x){
		   	
		   	  p->freq++;
		   	  
		      return p;
		   	
		   }
		   else p = p->next;
		 }
	 	return dl;
	 }
	 
	 /**
	  * @brief 思想：查到值为x的p结点后，将p摘下，
	  * 后顺着该结点的前驱结点查找插入位置，
	  * 判断条件是p的前驱结点q->freq小于或者等于p->freq;
	  * 
	  **/
	 void sortFreq(dlinklist &dl){
	 	  dlnode *p,*q;
	 	  int x;
		  for(int i= 0 ; i <10 ; i++){
			 	x = rand()%12;
			    p = locate(dl,x);
			    //将p结点摘下
			    p->next->front = p->front;
			    p->front->next = p->next;
			    q = p->front;
			    while(q!=dl&&q->freq<=p->freq){
					q = q->front;
				}
				p->next = q->next;
				q->next->front = p;
				q->next = p;
				p->front = q;
			 	
		   }
		 	 
	 	
	 }
  
     int main(){
       	
       	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
       	//int a[] = {1,2,3,2,1};
       
       	dlinklist dl = createDlinklist(dl,a,sizeof(a)/sizeof(a[0]));
       	
       	printfdlist(dl);
       	sortFreq(dl);
       	printfdlist(dl);
      
     }
