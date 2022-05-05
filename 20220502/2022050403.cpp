/**
 * LA��LBԪ�ص�������A��B�Ľ������������A��4   
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
    * β�巨����������
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
   
   //��ӡList�Ľڵ�
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
   * �����������Ԫ�ز���ͬ�����ͷŽ��
   * 
   **/
 	Linklist delete_dif(Linklist &LA,Linklist &LB){
 		
 		lnode *pa = LA->next,*pb = LB->next,*q;
 		lnode *pc = LA;
 		
 		while(pa&&pb){
		 	
		 	if(pa->data == pb->data){
		 		q = pb;
		 		pc->next = pa;
		 		pc = pa;
			 	pa = pa->next;
			 	pb = pb->next;
			 	free(q);
			 }
			 else if(pa->data<pb->data){
			 	q = pa;
			 	free(q);
			 	pa = pa->next;
			 }
			 else {
			 	q = pb;
				free(q);
			 	pb= pb->next;
			 }
		 }
 		while(pa){
 			
		 	q = pa;
		 	
		 	pa = pa->next;
		 	
		 	free(q);
		 }
		 
		 while(pb){
		 	
		 	q = pb;
		 	
		 	pb = pb->next;
		 	
		 	free(q);
		 }
		 pc->next = NULL;
		 free(LB);
 		return LA;
	 	
	 }
     
    int main(){
    	Linklist LA,LB;
        int a[] = {1,3,6,7,8,9,11};
    	int b []= {8,9,10,11};
    	LA = createListEnd(LA,a,sizeof(a)/sizeof(a[0]));
    	LB = createListEnd(LB,b,sizeof(b)/sizeof(b[0]));
    	prinList(LA);
    	prinList(LB);
    	LA = delete_dif(LA,LB);
    	prinList(LA);
    	prinList(LB);
    
    }
