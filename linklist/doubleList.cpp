/**
 * ������ѭ��������h1��h2,���һ���㷨��h2���ӵ�h1֮��Ҫ�����Ӻ�������Ա���ѭ��������ʽ
 * 
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
   * ˫���������
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
	    * ���ѭ��˫�����ֵ
	    **/
	    void printfdlist2(dlinklist dl){
	    	dlnode *p = dl->next;
	    	while(p!= NULL){
	 	   	printf("%d ",p->data);
	 	   	p = p->next;
	 	   }
	    	printf("\n");
	    }
	    
	    void dlinklistmerge(dlinklist &l1,dlinklist &l2) {
	    
	    	dlnode *h1 = l1,*p1 = h1;
	    	dlnode *h2 = l2,*p2 = h2;
	    	
	    	while(p1->next!=NULL){
	    		
				p1 = p1->next;	
			}
			while(p2->next!=NULL){
				  	
				p2 = p2->next;	
			}
			h1->front = p2;
			p1->next = h2->next;
			h2->next->front = p1;
			free(h2);
			
		}
    
      int main(){
	      	
	      	//int a[] = {1,3,5,6,7,8,9,10,11,12};
	      	int a[] = {1,2,3,2,1};
	      	int b[] = {7,8,9,10};
	      
	      	dlinklist dl = createDlinklist(dl,a,sizeof(a)/sizeof(a[0]));
	      	dlinklist dl2 = createDlinklist(dl2,b,sizeof(b)/sizeof(b[0]));
	      	
	      	printfdlist2(dl);
	      	printfdlist2(dl2);
	      	dlinklistmerge(dl,dl2);
	      	printfdlist2(dl);
	      	printfdlist2(dl2);
	      
	    }
