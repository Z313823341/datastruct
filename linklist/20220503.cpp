/**
 * ���һ���㷨��ʹ�õ������в������ظ���Ԫ��
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
  	
  	int a[] = {1,2,3,4,4,5,5,6,6,6,7,8,8,8,8};
  	
  	int len = sizeof(a) / sizeof(a[0]);
  	
  	Linklist LA = createListEnd(LA,a,len);
  	
  	prinList(LA);
  	
  	delece_same(LA);
  	
  	prinList(LA);
  }
