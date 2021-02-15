/*
 * fdll.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
struct dllnode
{
	int data ;
	struct dllnode *next ;
	struct dllnode *pre ;
};
int append_node(struct dllnode **fhead , struct dllnode **flast , int fdata );
int display(struct dllnode ** fhead);
int insert(struct dllnode **fhead , struct dllnode **flast , int fdata , int fc , int *flag);
int delete(struct dllnode **fhead , struct dllnode **flast , int ns , int fc , int *flag);
int input();
int print_reverse(struct dllnode **fhead,struct dllnode **flast);
int reverse(struct dllnode **fhead , struct dllnode **flast);
void deletedll(struct dllnode **fhead);
int main(void)
{
	struct dllnode *head = NULL ;
	struct dllnode *last = NULL ;
	int choice = 0 ;
	int c = 0 ;
	int rs = 0 ;
	int data = 0  ;
	int ns = 0 ;
	int flag = 0 ;
	do
	{
		printf("\n\t DOUBLY LINKED LIST MENU");
		printf("\n\t 1. Append node");
		printf("\n\t 2. Display linked list");
		printf("\n\t 3. Insert the node");
		printf("\n\t 4. Delete a node");
		printf("\n\t 5. Display linked list in reverse");
		printf("\n\t 6. Reverse linked list");
		printf("\n\t 7. Enter another linked list");
		printf("\n\t 0. Exit");
		printf("\n\t Enter the choice=");
		scanf("%d" , &choice);
		switch(choice)
		{
		case 1 :
			printf("Enter the data in node =");
			scanf("%d" ,&data);
			rs = append_node(&head , &last , data );
			if(rs == 1)
			{
				printf("Memory allocation failed");
			}
			break ;
		case 2 :
			rs = display(&head);
			if(rs == 1)
			{
				printf("Linked list is not created,please enter data first");
			}
			break ;
		case 3 :
			if(head == NULL)
			{
				printf("Linked list not created");
			}
			else
			{
				do
				{
					printf("\n\t MENU");
					printf("\n\t 1. Insert before head");
					printf("\n\t 2. Insert after last");
					printf("\n\t 3. Insert after particular node ");
					printf("\n\t 4. Insert before particular node");
					printf("\n\t 5. Exit");
					printf("\n\t Enter your choice =");
					scanf("%d" , &c);
					if(c >= 1 && c < 5)
					{
						printf("Enter new node here ");
						scanf("%d" , &data);
					}
					rs = insert(&head , &last , data , c , &flag);
					if(rs == 1)
					{
						printf("Linked list not created");
					}
					if(c >= 1 && c < 5)
					{
						if(flag ==1)
						{
							printf("There is no such node in linked list");
						}
						else
						{
							printf("New node is added successfully");
						}
					}
				}while(c != 5);
			}
			break ;
		case 4 :
			do
			{
				printf("\n\t MENU");
				printf("\n\t 1. Delete head");
				printf("\n\t 2. Delete last");
				printf("\n\t 3. Enter a node to be deleted");
				printf("\n\t 4. Exit");
				printf("\n\t Enter your choice =");
				scanf("%d" , &c);
				if(c == 3)
				{
					printf("Enter the node to be deleted");
					scanf("%d" , &ns);
				}
				rs = delete(&head , &last , ns , c , &flag );
				if(rs == 1)
				{
					printf("Linked list not created");
				}
				if(c >= 1 && c < 4)
				{
					if(flag == 0)
					{
						printf("Given node is deleted successfully");
					}
					else
					{
						printf("There is no such node in list");
					}
				}
			}while(c != 4);
			break ;
			case 5 :
				rs = print_reverse(&head , &last);
				if(rs == 1)
				{
					printf("Linked list is not created,please enter data first");
				}
				break ;
			case 6 :
				rs = reverse(&head , &last );
				if(rs == 1)
				{
					printf("Linked list not created");
				}
				else
				{
					printf("Linked list is reversed successfully");
				}
				break ;
			case 7 :
				main();
				break ;
			case 0 :
				deletedll(&head);
			break ;
		}
	}while(choice != 0);
	return 0 ;
}
int append_node(struct dllnode **fhead , struct dllnode **flast , int fdata )
{
	struct dllnode *newnode = NULL ;
	struct dllnode *head = NULL ;
	struct dllnode *last = NULL ;
	int rval = 0 ;
	newnode = (struct dllnode*)calloc(1 , sizeof(struct dllnode));
	if(newnode == NULL)
	{
		rval = 1 ;
	}
	else
	{
		head = *fhead ;
		last = *flast ;
		newnode -> data = fdata ;
		if(head == NULL)
		{
			head = newnode ;
			last = newnode ;
		}
		else
		{
			last -> next = newnode ;
			newnode -> pre = last ;
			last = newnode ;
		}
		rval = 0 ;
		*fhead = head ;
		*flast = last ;
	}
	return rval ;
}
int display(struct dllnode ** fhead)
{
	int rval = 0 ;
	struct dllnode *head = NULL ;
	struct dllnode *i = NULL ;
	head = *fhead ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		rval = 0 ;
		for(i=head ; i != NULL ; i = i -> next)
		{
			printf("%d \t" , i -> data);
		}
		*fhead = head ;
	}
	return rval ;
}
int insert(struct dllnode **fhead , struct dllnode **flast , int fdata , int fc , int *flag)
{
	int rval = 0 ;
	struct dllnode *newnode = NULL ;
	struct dllnode *head = NULL ;
	struct dllnode *last = NULL ;
	struct dllnode *a = NULL ;
	struct dllnode *b = NULL ;
	struct dllnode *i = NULL ;
	int ns = 0 ;
	newnode = (struct dllnode *)calloc(1 , sizeof(struct dllnode));
	if(newnode == NULL)
	{
		rval = 1 ;
	}
	else
	{
		head = *fhead ;
		last = *flast ;
		newnode -> data = fdata ;
		rval = 0 ;
		switch(fc)
		{
		case 1 :
			*flag = 0 ;
			newnode -> next = head ;
			head = newnode ;
			break ;
		case 2 :
			*flag = 0 ;
			last ->next = newnode ;
			last = newnode ;
			break ;
		case 3 :
			*flag = 0 ;
			a = NULL ;
			ns = input();
			if(ns == last -> data)
			{
				*flag = 0 ;
				last ->next = newnode ;
				last = newnode ;
			}
			else
			{
				for(i=head ; i != NULL ; i = i ->next)
				{
					if(ns == i -> data)
					{
						a = i ;
						i = last ;
					}
				}
				if(a == NULL)
				{
					*flag = 1 ;
				}
				else
				{
					*flag = 0 ;
					b = a -> next ;
					a -> next = newnode ;
					newnode ->next = b ;
					b -> pre = newnode ;
					newnode -> pre = a ;
				}
			}
			break ;
		case 4 :
			*flag = 0 ;
			a = NULL ;
			ns = input();
			if(ns == head -> data)
			{
				flag = 0 ;
				newnode -> next = head ;
				head = newnode ;
			}
			else
			{
				for(i=head ; i != NULL ; i = i->next )
				{
					if(ns == i ->data)
					{
						b = i ;
						i = last ;
					}
				}
				if(b == NULL)
				{
					*flag =1 ;
				}
				else
				{
					flag = 0 ;
					a = b -> pre ;
					a -> next = newnode ;
					newnode -> next = b ;
				}
			}
			break ;
		}
		*fhead = head ;
		*flast = last ;
	}
		return rval ;
}
int input(int c)
{
	int ns = 0 ;
	printf("Enter the node before/after which new node is to be inserted");
	scanf("%d" , &ns);
	return ns;
}
int delete(struct dllnode **fhead , struct dllnode **flast , int ns , int fc , int *flag)
{
	struct dllnode *head = NULL ;
	struct dllnode *last = NULL ;
	struct dllnode *dnode = NULL ;
	struct dllnode *i = NULL ;
	int rval = 0 ;
	head = *fhead ;
	last = *flast ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		rval = 0 ;
		switch(fc)
		{
		case 1 :
			*flag = 0 ;
			dnode = head ;
			head = head -> next ;
			dnode ->next = NULL ;
			free(dnode);
			dnode = NULL ;
			break ;
		case 2 :
			*flag = 0 ;
			dnode = head ;
			while(dnode -> next != NULL)
			{
				i = dnode ;
				dnode = dnode -> next ;
			}
			i -> next = NULL ;
			free(dnode);
			dnode = NULL ;
			break ;
		case 3 :
			i = NULL ;
			*flag = 0 ;
			if(ns == head->data)
			{
				dnode = head ;
				while(dnode -> next != NULL)
				{
					i = dnode ;
					dnode = dnode -> next ;
				}
				i -> next = NULL ;
				*flag = 0 ;
			}
			else
			{
				for(dnode = head ; dnode != NULL ; dnode = dnode -> next)
				{
					if(dnode ->data == ns)
					{
						i = dnode ;
						dnode = last ;
					}
				}
				if(i == NULL)
				{
					*flag = 1 ;
				}
				else
				{
					*flag = 0 ;
					i ->pre -> next = i -> next ;
					i -> next -> pre = i -> pre ;
				}
			}
			free(dnode);
			dnode = NULL ;
			break ;
		}
		*fhead = head ;
		*flast = last ;
	}
	return rval ;
}
int print_reverse( struct dllnode **fhead , struct dllnode **flast)
{
	struct dllnode *last= NULL ;
	struct dllnode *head= NULL ;
	struct dllnode *i = NULL ;
	int rval = 0 ;
	last = *flast ;
	head = *fhead ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		rval = 0 ;
		for(i = last ; i != NULL ; i = i -> pre)
		{
			printf("%d\t" , i->data);
		}
	}
	*fhead = head ;
	*flast = last ;
	return rval ;
}
int reverse(struct dllnode **fhead , struct dllnode **flast)
{
	struct dllnode *last= NULL ;
	struct dllnode *head= NULL ;
	struct dllnode *i = NULL ;
	struct dllnode *temp = NULL ;
	int rval = 0 ;

	last = *flast ;
	head = *fhead ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		rval = 0 ;
		i = head ;
		while( i != NULL)
		{
			temp = i -> next ;
			i -> next = i -> pre ;
			i -> pre = temp ;
			i = temp ;
		}
		temp = head ;
		head = last ;
		last = temp ;
	}
	*fhead = head ;
	*flast = last ;
	return rval ;
}
void deletedll(struct dllnode **fhead)
{
	struct dllnode *head = NULL ;
	struct dllnode *dnode = NULL ;
	head = *fhead ;
	while(head != NULL)
	{
		dnode = head ;
		head = head -> next ;
		free(dnode);
		dnode = NULL ;
	}
	head = NULL ;
	*fhead = head ;
}


