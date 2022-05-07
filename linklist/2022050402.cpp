/**
 * LA和LA是两个单链表递增有序 要求从LA和LB中公共2元素产生单链表LC
 * 
 * 要求不破坏LA和LB的结点
 * 
 **/
 #include<stdio.h>
 #include<iostream>
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
	 * 
	 * 寻找两个链表的公共元素
	 * 思想：递增有序，
	 * 
	 **/
	 
	 Linklist search_same(Linklist LA,Linklist LB,Linklist &LC){
	 	
	 	lnode * PA = LA->next,*PB = LB->next,*r,*s;
	 	
	 	LC = (Linklist)malloc(sizeof(lnode));
	 	
	 	r = LC;
	 	
	 	while(PA&&PB){
	 		
	 		if(PA->data<PB->data){
			 	
			 	PA = PA->next;
			 }
			if(PA->data>PB->data){
				
				PB = PB->next;
			} 
			if(PA->data == PB->data){
				
				s = (lnode*)malloc(sizeof(lnode));
				
				s->data = PA->data;
				
				r->next= s;
				
				r = s;
				
				PA = PA->next;
				
				PB = PB->next;
			}
			
			r->next = NULL;
		 
		 }
	 	return LC;
	 }
    
   int main(){
   	Linklist LA,LB,LC;
    int a[] = {1,3,5,6,7,8,9};
   	int b []= {2,5,6,8,9,10,11};
   	LA = createListEnd(LA,a,sizeof(a)/sizeof(a[0]));
   	LB = createListEnd(LB,b,sizeof(b)/sizeof(b[0]));
   	prinList(LA);
   	prinList(LB);
   	LC = search_same(LA,LB,LC);
   	prinList(LC);
   }
