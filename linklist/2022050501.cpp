/**
 * 
 * ��֪la��lb���ж�lb�Ƿ���la������������
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
   * ˼�룺�ӵ�һ����㿪ʼ�Ƚϣ�����ȣ���a��b���ƣ�
   * ������ȣ���A�Ŀ�ʼ�ȽϽ�����һ����㿪ʼ�Ƚϣ���b�ĵ�һ����㿪ʼ�Ƚ�
   * ��b�Ƚϵ���β��˵��b��a ������������
   * ������
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
   
     
