/**
 * ���еĶ���
 **/
 
  #include<iostream>
  #include<stdio.h>
  #define MAXSIZE 20
  typedef int Elemtype;
  /**
   * ���е�˳��洢
   * 
   * 
   * �ӿ�������front = rear = 0;
   * ��Ӳ�������βָ��rear+1;
   * ���Ӳ�������ͷָ��front+1;
   **/
   
   typedef struct{
   	Elemtype data[MAXSIZE];
   	int front,rear;  
   }sqQueue;
