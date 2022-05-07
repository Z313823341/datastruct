/**
 * 设计一个算法判断带头节点的循环双链表是否对称
 * 
 * 循环双链表：头节点还要指向表尾结点，尾节点指向头节点
 * 
 * 循环单链表：尾节点指向头节点
 **/
 #include<stdio.h>
 #include<iostream>
 
 
 typedef int elemtype;
 typedef struct dlnode{
 	elemtype data;
 	dlnode *front;
 	dlnode *next;
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
	  	s->data = a[i];
	  	s->front = p;
	  	p->next = s;
	  	p = s;
	  }
	  p->next = dl;
	  dl->front = p;
  	
  	return dl;
  }
  
  /**
   * 输出循环双链表的值
   **/
   void printfdlist(dlinklist dl){
   	dlnode *p = dl->next;
   	while(p!= dl){
	   	printf("%d ",p->data);
	   	p = p->next;
	   }
   	printf("\n");
   }
   
   /**
    * @brief 判断是否堆成
    * 思想：q和p从两端遍历，当他们指向同一结点，既p = q（奇数个结点）
	* 或者p->next = q而且q->front = p时
    **/
    
    int symmetry(dlinklist dl){
    	
    	dlnode *p = dl->next;
    	dlnode *q = dl->front;
    	while(p!=q&&q->next!=p){
    		
    		if(p->data == q->data){
					
					p = p->next;
					q = q->front;	
				}
			else return 0;
		}
    	
		return 1;
	} 
	
    int main(){
      	
      	//int a[] = {1,3,5,6,7,8,9,10,11,12};
      	int a[] = {1,2,3,2,1};
      
      	dlinklist dl = createDlinklist(dl,a,sizeof(a)/sizeof(a[0]));
      	
      	printfdlist(dl);
      	
      	printf("%d",symmetry(dl));
    }
   
