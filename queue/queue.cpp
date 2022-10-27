/**
 * 队列的定义
 **/
 
  #include<iostream>
  #include<stdio.h>
  #define MAXSIZE 20
  typedef int Elemtype;
  /**
   * 队列的顺序存储
   * 
   * 
   * 队空条件：front = rear = 0;
   * 入队操作：队尾指针rear+1;
   * 出队操作：队头指针front+1;
   **/
   
   typedef struct{
   	Elemtype data[MAXSIZE];
   	int front,rear;  
   }sqQueue;
