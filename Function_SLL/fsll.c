/*
 * fsll.c
 *
 *  Created on: 20-Nov-2019
 *      Author: hp
 */
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
struct sllnode
{
	int data ;
	struct sllnode *next ;
};
int append_node(struct sllnode **fhead , struct sllnode **flast , int fdata , int *fcnt);
int display(struct sllnode ** fhead);
int insert(struct sllnode **fhead , struct sllnode **flast , int fdata , int fc , int *flag);
int delete(struct sllnode **fhead , struct sllnode **flast , int ns , int fc , int *flag);
int input();
int print_reverse(struct sllnode **fhead , int arr[] );
int reverse(struct sllnode **fhead , struct sllnode **flast);
void deletesll(struct sllnode **fhead);
int main(void)
{
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	int choice = 0 ;
	int c = 0 ;
	int rs = 0 ;
	int data ;
	int ns = 0 ;
	int cnt = 0 ;
	int *arr = NULL ;
	int in = 0 ;
	int flag = 0 ;
	do
	{
		printf("\n\t SINGLY LINKED LIST MENU");
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
			rs = append_node(&head , &last , data , &cnt);
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
						printf("Memory allocation failed");
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
				else
				{
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
				}
			}while(c != 4);
			break ;
		case 5 :

			arr = (int *)calloc(cnt , sizeof(int));
			rs = print_reverse(&head , arr);
			if(rs == 1)
			{
				printf("Linked list is not created,please enter data first");
			}
			else
			{
				for(in=cnt-1 ; in >= 0 ; --in)
				{
					printf("%d\t" , arr[in]);
				}
				free(arr);
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
			deletesll(&head);
			break ;
		}
	}while(choice != 0);
return 0 ;
}
int append_node(struct sllnode **fhead , struct sllnode **flast ,int fdata , int *fcnt)
{
	struct sllnode *newnode = NULL ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	int rval = 0 ;
	newnode = (struct sllnode *)calloc(1 , sizeof(struct sllnode));
	if(newnode == NULL)
	{
		rval = 1 ;
	}
	else
	{
		newnode->data = fdata ;
		head = *fhead ;
		last = *flast ;
		if(head == NULL)
		{
			head = newnode ;
			last = newnode ;
		}
		else
		{
			last -> next = newnode ;
			last = newnode ;
		}
		rval = 0 ;
		*fcnt = *fcnt + 1 ;
		*fhead = head ;
		*flast = last ;
	}
	return rval ;
}
int display(struct sllnode ** fhead)
{
	struct sllnode *head = NULL ;
	struct sllnode *i = NULL ;
	int rval = 0 ;
	head = *fhead ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		printf("Linked List data :\n");
		for(i=head ; i != NULL ; i = i -> next)
		{
			printf("%d\t" , i -> data);
		}
		rval = 0 ;
	}
	return rval ;
}
int insert(struct sllnode **fhead , struct sllnode **flast , int fdata , int fc , int *flag)
{
	int rval = 0 ;
	struct sllnode *newnode = NULL ;
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *a = NULL ;
	struct sllnode *b = NULL ;
	struct sllnode *i = NULL ;
	int ns = 0 ;
	newnode = (struct sllnode *)calloc(1 , sizeof(struct sllnode));
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
			last -> next = newnode ;
			last = newnode ;
			break ;
		case 3 :
			*flag = 0 ;
			a = NULL ;
			ns = input();
			for(i=head ; i != NULL ; i = i -> next)
			{
				if(ns == i->data)
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
				if(a != NULL)
				{
					b = a -> next ;
					a ->next = newnode ;
					newnode -> next = b ;
				}
			}
			break ;
		case 4 :
			*flag = 0 ;
			a = NULL ;
			ns = input();
			if(ns == head->data)
			{
				newnode -> next = head ;
				head = newnode ;
			}
			else
			{
				for(i=head ; i != NULL && i-> next != NULL ; i = i -> next)
				{
					if(ns == i-> next -> data)
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
					if(a != NULL)
					{
						b = a -> next ;
						a ->next = newnode ;
						newnode -> next = b ;
					}
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
int delete(struct sllnode **fhead , struct sllnode **flast , int ns , int fc , int *flag)
{
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *dnode = NULL ;
	struct sllnode *i = NULL ;
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
			dnode -> next = NULL ;
			free(dnode);
			dnode = NULL ;
			last = head ;
			break ;
		case 2 :
			*flag = 0 ;
			dnode = head ;
			while(dnode -> next != NULL)
			{
				i = dnode ;
				dnode = dnode -> next ;
			}
			last = i ;
			i -> next = NULL ;
			free(dnode);
			dnode = NULL ;
			break ;
		case 3 :
			*flag = 0 ;
			dnode = head ;
			i = NULL ;
			if(ns == head -> data)
			{
				*flag = 0 ;
				dnode = head ;
				head = head -> next ;
				dnode -> next = NULL ;
			}
			else
			{
				for(dnode = head ; dnode != NULL && dnode ->next != NULL ; dnode = dnode ->next)
				{
					if(ns == dnode -> next ->data)
					{
						i = dnode ;
						dnode = last ;
					}
				}
				if(i != NULL)
				{
					*flag = 0 ;
					i->next = i -> next-> next ;
					free(dnode);
					dnode = NULL ;
				}
				else
				{
					*flag = 1 ;
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
int print_reverse(struct sllnode **fhead , int arr[] )
{
	struct sllnode *head = NULL ;
	struct sllnode *i = NULL ;
	int in = 0 ;
	int rval = 0 ;
	head = *fhead ;
	if(head == NULL)
	{
		rval = 1 ;
	}
	else
	{
		rval = 0 ;
		for(i=head ,in=0 ; i != NULL ;i=i->next , in=in+1)
		{
			arr[in] = i->data ;
		}
	}
	return rval ;
}
int reverse(struct sllnode **fhead , struct sllnode **flast)
{
	struct sllnode *head = NULL ;
	struct sllnode *last = NULL ;
	struct sllnode *dnode = NULL ;
	struct sllnode *head1 = NULL ;
	struct sllnode *last1 = NULL ;
	struct sllnode *k = NULL ;
	struct sllnode *i = NULL ;
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
		for(i=head ; i != NULL ; i = k)
		{
			dnode = head ;
			head = head -> next ;
			k = dnode -> next ;
			dnode -> next = NULL ;
			if(head1 == NULL)
			{
				head1 = dnode ;
				last1 = dnode ;
			}
			else
			{
				dnode -> next = head1 ;
				head1 = dnode ;
			}
		}
		head= head1 ;
		last = last1 ;
		head1 = NULL ;
		last1 = NULL ;
		*fhead = head ;
		*flast = last ;
	}
	return rval ;
}
void deletesll(struct sllnode **fhead)
{
	struct sllnode *head = NULL ;
	struct sllnode *dnode = NULL ;
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
