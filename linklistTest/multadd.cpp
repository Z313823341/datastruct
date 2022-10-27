/**
 * 用链表实现多项式的相加和相乘
 * 
 **/
#include <stdio.h>
#include <stdlib.h>
 
 struct PolyNode{
  	int coef; //系数。。。。
  	int excon; //指数
  	struct PolyNode *link;
  };
typedef struct PolyNode *polynominal;
  
   /**
     *输出多项式
    **/
    void printPoly(polynominal p){
    	while(p){
  	  	printf("%d %d ",p->coef,p->excon);
  	  	p = p->link;
  	  }
    	
    }
    /**
	 * 链式存储多项式
	 **/
  void Attach(int coef,int excon,polynominal *prear){
  	polynominal s;        //临时头指针，尾指针
  	s = (polynominal)malloc(sizeof(struct PolyNode));
  	s->coef = coef;
  	s->excon = excon;
  	s->link = NULL;
    (*prear)->link = s;
  	*prear = s;
  }
  
  /**
   * 读入多项式
   **/
  polynominal polyRead(){		
  
 	 polynominal p,rear,t;
 	 int n;                         //多项式的项数
 	 int excon;
 	 int coef;
 	 printf("多项式项数为:");
 	 scanf("%d",&n);
 	 p = (polynominal)malloc(sizeof(struct PolyNode));
 	 p->link = NULL;
 	 rear = p;
 	 printf("输入的多项式为：\r\n");
 	 while(n--){
    	scanf("%d %d",&coef,&excon);
	    Attach(coef,excon,&rear);
	  }
	 t = p;p=p->link;free(t);
	
     return  p;
  }
  
  /**
   * 多项式相乘
   **/
  
  polynominal mult(polynominal p1,polynominal p2){
  	
  	 polynominal  rear,p,s,t;
  	 polynominal t1 = p1,t2 = p2;
  	 int e,c;
  	 p = (polynominal)malloc(sizeof(struct PolyNode));
  	 rear = p;
  	 p->link = NULL;
  	 while(t2){
	   	Attach(t1->coef*t2->coef,t1->excon+t2->excon,&rear);
	   	t2 = t2->link;
	   }
	 t1 = t1->link;
	 
	 while(t1){
	 	t2 = p2;rear = p;
	 	while(t2){
	 		 e = t1->excon+t2->excon;
			  c = t1->coef *t2->coef;
			 while(rear->link&&rear->link->excon>e){
			 	rear = rear->link;
			   }
			   if(rear->link&&rear->link->excon==e){
			   		if(c+rear->link->coef){
					   	rear->link->coef = rear->link->coef + c;
					   }else{
					   	t= rear->link;
					   	rear->link = t->link;
					   	free(t);
					   }
			       }
			   else{
			   		s = (polynominal)malloc(sizeof(struct PolyNode));
			   		s->coef = c;
			   		s->excon = e;
			   		s->link = rear->link;
			   		rear->link = s;
			   		rear = rear->link;
			   		}    
			 t2 = t2->link;
	       }
		t1 = t1->link;
	 }
	 t2 = p;p = p->link;free(t2);
	 return  p;
  }
  
 /**
  * 比较系数
  **/
  int compare(int a,int b){
  	if(a==b) return 0;
  	else if(a<b) return -1;
  	else return 1;  
  }
  
  /**
   * 多项式相加
   **/
  polynominal Add(polynominal p1,polynominal p2){
  	polynominal front,rear,temp;
    polynominal	t1 = p1;
	polynominal t2 = p2;
	rear = (polynominal)malloc(sizeof(struct PolyNode));
	front = rear;
  	int sum;
  	while(t1&&t2){
	  	switch (compare(t1->excon,t2->excon)) {
		  	case 0:
		  		sum = t1->coef+t2->coef;
		  		if(sum)
		  		Attach(sum,t2->excon,&rear);
		  		t1=t1->link;t2=t2->link;
		  		break;
		  	case 1:
		  		Attach(t1->coef,t1->excon,&rear);
		  		t1=t1->link;
		  		break;
		  	case -1:
		  		Attach(t2->coef,t2->excon,&rear);
		  		t2=t2->link;
		  		break;
		  }
	  }
	while(t1){
		Attach(t1->coef,t1->excon,&rear);
		t1=t1->link;	
	}  
	while(t2){
		Attach(t2->coef,t2->excon,&rear);
		t2=t2->link;	
		}  
	temp = front;
	rear->link = NULL;
	front = front->link;
	free(temp);
  	return front;
  	 
  }
 
 int main(){
 	polynominal p1,p2,pp,ps;
 	 
 	p1 = polyRead();//读入多项式
    p2 = polyRead();//读入多项式
 	//pp = Add(p1,p2);
 	//printf("多项式相加的结果是：");
    // printPoly(pp);
    ps = mult(p1,p2);
    printPoly(ps);
 	
 	
 }
