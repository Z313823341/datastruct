/**
 * LA��LBԪ�ص������򣬽�LA��LB���Ϊһ���ݼ�����ĵ�����
 * Ҫ����ԭ��������Ľ���Ź鲢��ĵ�����
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
  /**
     * ͷ�巨����������
     **/
  Linklist createListHead(Linklist &L, int a[],int length){
  	
  		L = (Linklist)malloc(sizeof(lnode));
	    
		for(int i=0;i<length;i++){
			
			lnode *s = (lnode *)malloc(sizeof(lnode));
			
			s->data = a[i];
			
			s->next = L->next;
			
			L->next = s;
		
		}	
  	
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
   * �鲢���ı� 
   * ˼�룺ͷ�巨���룬ȥ��
   **/
  
  Linklist merge(Linklist &LA,Linklist &LB){
  	
  	lnode *R,*A = LA->next;
  	lnode *B = LB->next;
  	LA->next = NULL;
  	
  	
  	while(A && B){
  		
	  	if(A->data<=B->data){
	  	
	  	R = A->next;
	  		
		A->next = LA->next;
		  
		LA->next = A;
		
		A = R;
		}
		else{
			
		R = B->next;
			  	
		B->next = LA->next;
				  		  
		LA->next = B;
				  		
		B = R;
		  	
		  }
		  
	  }
	  
	if(A){
		
		B= A;
		
	}
    while(B){
    	
	    R = B->next;
	   			  	
	   	B->next = LA->next;
	   				  		  
	   	LA->next = B;
	   				  		
	   	B = R;
	  			  		  
	  }
  	
  	free(B);
  	
  	return LA;
  }
  
  
    /**
     **ɾ����ͬ��Ԫ��
     **/
     
     void delece_same(Linklist &L){
     	
     	lnode *pre = L;
     	
     	lnode *p = pre->next;
     	
     	lnode *q ;
     	
     	while(p-> next != NULL){
  	   	
  	   	if(p->data == p->next->data ){
  		   	
  		   	q = p;
  		   	
  		   	pre ->next = p->next;
  		   	
  		   	p = p->next;
  		   	
  		   	free(q);
  		   	
  		   }
  		   
  	   	else{
  		   	
  		   	pre = pre->next;
  		   	
  		   	p = pre->next;
  		   	
  		   }
  	   
     		}
     }
  int main(){
  	Linklist LA,LB;
  	int a[] = {1,3,5,6,7,8,9};
  	int b []= {2,5,6,8,9,10,11};
  	LA = createListEnd(LA,a,sizeof(a)/sizeof(a[0]));
  	LB = createListEnd(LB,b,sizeof(b)/sizeof(b[0]));
  	prinList(LA);
  	prinList(LB);
  	LA = merge(LA,LB);
  	prinList(LA);
  	delece_same(LA);
  	prinList(LA);
  	
  }
