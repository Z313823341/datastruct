/**
 * 循环单链表la，每次输出最小的值，直到链表为空，最后释放表头空间
 * 
 **/
  #include<stdio.h>
   #include<iostream>
   
   
   typedef int elemtype;
   typedef struct dlnode{
   	elemtype data;
   	//dlnode *front;
   	dlnode *next;
   }dlnode,*dlinklist;
   
   /**
    * 循环单链表建表操作
    **/
    
    dlinklist createDlinklist(dlinklist &dl,int a[],int length){
    	
    	dl = (dlinklist)malloc(sizeof(dlnode));
    	dl->next = dl;
    	//dl->front = dl;
    	dlnode *p = dl; 	//r指向表尾结点
    	for(int i=0;i<length;i++){
  	  	dlnode *s = (dlnode *)malloc(sizeof(dlnode)); 
  	  	s->data = a[i];
  	    //s->front = p;
  	  	p->next = s;
  	  	p = s;
  	  }
  	    p->next = dl;
 	  //dl->front = p;
    	
    	return dl;
    }
    
    
     
        /**
 	    * 输出循环单链表的值
 	    **/
 	    void printfdlist2(dlinklist dl){
 	    	dlnode *p = dl->next;
 	    	while(p!= dl){
	 	 	   	printf("%d ",p->data);
	 	 	   	p = p->next;
 	 	  	   }
 	    	printf("\n");
 	    }
 	    /**
		  * 输出循环单链表最小的值
		  **/
 	   void printMinelem(dlinklist &dl){
				dlnode *minpre , *minp ,*pre,*p ;
				
			while(dl->next!=dl){
				p = dl->next;pre = dl;
				minp = p; minpre = pre;
				while(p!=dl){
					if(p->data<minp->data){
						 minp = p;
						 minpre = pre;
					}
				     pre = p;
					 p = p->next;
				}
				printf("%d\n",minp->data);
				minpre ->next = minp->next;
			
				free(minp);
			}
		free(dl);
 	   }
       int main(){
 	      	
 	      	int a[] = {1,3,5,6,7,8,9,10,11,12};
 	      	//int a[] = {1,2,3,2,1};
 	      	//int b[] = {7,8,9,10};
 	       	
 	      	dlinklist dl = createDlinklist(dl,a,sizeof(a)/sizeof(a[0]));
 	      	
 	      	
 	      	printfdlist2(dl);
 	   
 	        printMinelem(dl);
 	        
 	        //printfdlist2(dl);
 	      
 	    }
