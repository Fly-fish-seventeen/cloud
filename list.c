/* 包含的头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 


struct list {
	int id;				
	int data;		
	struct list *next;	
};


/**	将指定元素插入到链表第二个位置
  * 	head	: 表示要插入元素的链表的头部的地址
  *	list    : 表示要插入到链表中的元素
  */
static void list_add(struct list **head, struct list *list)
{
	struct list *temp;
 
	/* 判断链表是否为空 */
	if(NULL == *head)
	{
		/* 为空 */
		*head = list;
		(*head)->next = NULL;
	}
	else{
		list->next=NULL;
        
        list->next= (*head)->next;
        (*head)->next=list;
	}

	
		
	
}
 

int tailadd(struct list **list_tail, struct list *list){
	(*list_tail)->next=list;
	(*list_tail)=list;
	return 1;
}
/** 遍历一个链表，打印链表中每个元素所包含的数据
  * head : 表示要遍历的链表的头部的指针
  */
static void list_print(struct list **head)
{	
	struct list *temp;
	printf("list information :\n");
	printf("listhead %d \n", (*head)->id);
	temp = (*head)->next;
 
	
	while(temp)
	{
		printf("listnode %d\n", temp->id);
		temp = temp->next;
	}
	printf("list information over:\n\n");
}
 

struct list *list_head;

 
/* 主函数，程序的入口 */
int main(int argc, char *argv[])
{
	struct list *list_tail;
	struct list tree1;tree1.id=1;tree1.next=NULL;
	
	list_head=&tree1;
	struct list tree3;tree3.id=3;tree3.next=NULL;
	struct list tree2;tree2.id=2;tree2.next=NULL;
	struct list tree4;tree4.id=4;tree4.next=NULL;
	struct list tree5;tree5.id=5;tree5.next=NULL;
	struct list tree6;tree6.id=6;tree6.next=NULL;
	tree1.next=&tree2;
	tree2.next=&tree3;
	list_tail=&tree3;
	list_tail->next=&tree4;list_tail=&tree4;
	list_tail->next=&tree5;list_tail=&tree5;
//	list_add(&list_head, &temp_list);
	tailadd(&list_tail,&tree6);
	list_print(&list_head);
	return 0;
}