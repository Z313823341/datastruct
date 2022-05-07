/**
 * ��ѭ��˫����ÿ��ִ��locate��L,x��ʱ����freq��1����ʹ����freq�ݼ�����
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
  	elemtype  freq;//����Ƶ��
  }dlnode,*dlinklist;
  
  /**
   * ѭ��˫���������
   **/
   
   dlinklist createDlinklist(dlinklist &dl,int a[],int length){
   	
   	dl = (dlinklist)malloc(sizeof(dlnode));
   	dl->next = dl;
   	dl->front = dl;
   	dlnode *p = dl; 	//rָ���β���
   	for(int i=0;i<length;i++){
 	  	dlnode *s = (dlnode *)malloc(sizeof(dlnode)); 
 	  	s->freq = 0;
 	  	s->data = a[i];
 	  	s->front = p;
 	  	p->next = s;
 	  	p = s;
 	  }
 	  p->next = NULL; //��ѭ��˫����β��㲻ָ���ͷ����ͷǰ����ָ���β
 	  //dl->front = p;
   	
   	return dl;
   }
   
   /**
    * ���ѭ��˫�����ֵ
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
	 * locate����
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
	  * @brief ˼�룺�鵽ֵΪx��p���󣬽�pժ�£�
	  * ��˳�Ÿý���ǰ�������Ҳ���λ�ã�
	  * �ж�������p��ǰ�����q->freqС�ڻ��ߵ���p->freq;
	  * 
	  **/
	 void sortFreq(dlinklist &dl){
	 	  dlnode *p,*q;
	 	  int x;
		  for(int i= 0 ; i <10 ; i++){
			 	x = rand()%12;
			    p = locate(dl,x);
			    //��p���ժ��
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
