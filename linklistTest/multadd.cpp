/**
 * ������ʵ�ֶ���ʽ����Ӻ����
 * 
 **/
#include <stdio.h>
#include <stdlib.h>
 
 struct PolyNode{
  	int coef; //ϵ����������
  	int excon; //ָ��
  	struct PolyNode *link;
  };
typedef struct PolyNode *polynominal;
  
   /**
     *�������ʽ
    **/
    void printPoly(polynominal p){
    	while(p){
  	  	printf("%d %d ",p->coef,p->excon);
  	  	p = p->link;
  	  }
    	
    }
    /**
	 * ��ʽ�洢����ʽ
	 **/
  void Attach(int coef,int excon,polynominal *prear){
  	polynominal s;        //��ʱͷָ�룬βָ��
  	s = (polynominal)malloc(sizeof(struct PolyNode));
  	s->coef = coef;
  	s->excon = excon;
  	s->link = NULL;
    (*prear)->link = s;
  	*prear = s;
  }
  
  /**
   * �������ʽ
   **/
  polynominal polyRead(){		
  
 	 polynominal p,rear,t;
 	 int n;                         //����ʽ������
 	 int excon;
 	 int coef;
 	 printf("����ʽ����Ϊ:");
 	 scanf("%d",&n);
 	 p = (polynominal)malloc(sizeof(struct PolyNode));
 	 p->link = NULL;
 	 rear = p;
 	 printf("����Ķ���ʽΪ��\r\n");
 	 while(n--){
    	scanf("%d %d",&coef,&excon);
	    Attach(coef,excon,&rear);
	  }
	 t = p;p=p->link;free(t);
	
     return  p;
  }
  
  /**
   * ����ʽ���
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
  * �Ƚ�ϵ��
  **/
  int compare(int a,int b){
  	if(a==b) return 0;
  	else if(a<b) return -1;
  	else return 1;  
  }
  
  /**
   * ����ʽ���
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
 	 
 	p1 = polyRead();//�������ʽ
    p2 = polyRead();//�������ʽ
 	//pp = Add(p1,p2);
 	//printf("����ʽ��ӵĽ���ǣ�");
    // printPoly(pp);
    ps = mult(p1,p2);
    printPoly(ps);
 	
 	
 }
