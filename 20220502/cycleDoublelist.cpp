/**
 * ���һ���㷨�жϴ�ͷ�ڵ��ѭ��˫�����Ƿ�Գ�
 * 
 * ѭ��˫����ͷ�ڵ㻹Ҫָ���β��㣬β�ڵ�ָ��ͷ�ڵ�
 * 
 * ѭ��������β�ڵ�ָ��ͷ�ڵ�
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
  * ѭ��˫���������
  **/
  
  dlinklist createDlinklist(dlinklist &dl,int a[],int length){
  	
  	dl = (dlinklist)malloc(sizeof(dlnode));
  	dl->next = dl;
  	dl->front = dl;
  	dlnode *p = dl; 	//rָ���β���
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
   * ���ѭ��˫�����ֵ
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
    * @brief �ж��Ƿ�ѳ�
    * ˼�룺q��p�����˱�����������ָ��ͬһ��㣬��p = q����������㣩
	* ����p->next = q����q->front = pʱ
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
   
