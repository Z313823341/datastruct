/**
 * 有两个循环单链表，h1和h2,设计一个算法将h2链接到h1之后，要求链接后的链表仍保持循环链表形式
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
   * 双链表建表操作
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
	    * 输出循环双链表的值
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
