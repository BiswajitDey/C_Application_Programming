#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}node;
int length(char[]);
node * create(char[],int);

node * insert_b(node *);
node * insert_be(node *);
node * insert_ae(node *);
node * insert_e(node *);

node * delete_b(node *);
node * delete_be(node *);
node * delete_ae(node *);
node * delete_e(node *);

int checkpalin(node *);

void display(node *);
main()
{
	node *head;
	char str[20];
	int len,ch,ch1,ch2,result;
	head=NULL;
	printf("Enter a string:");
		scanf("%s",str);
	len=length(str);
	head=create(str,len);	
	do
	{
	printf("\n***MENU***\n1.Insert\n2.Delete\n3.Check Palindrome\n4.Display\n5.Exit\n\nEnter your choice:");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				printf("\n1.In the beginning\n2.Before a character\n3.After a character\n4.In the end\n\nEnter a choice:");
					scanf("%d",&ch1);
				switch(ch1)
				{
					case 1:
							head=insert_b(head);
							break;
					case 2:
							head=insert_be(head);
							break;
					case 3:
							head=insert_ae(head);
							break;
					case 4:
							head=insert_e(head);
							break;					
				}
				break;	
		case 2:
				printf("\n1.In the beginning\n2.Before a character\n3.After a character\n4.In the end\n\nEnter a choice:");
					scanf("%d",&ch2);
				if(head==NULL)
					printf("Empty linked list..!!");
				else
				{
				switch(ch2)
				{
					case 1:
							head=delete_b(head);							
							break;
					case 2:
							head=delete_be(head);							
							break;
					case 3:
							head=delete_ae(head);							
							break;
					case 4:
							head=delete_e(head);
							break;					
				}
				}
				break;
		case 3:
				result=checkpalin(head);
				if(result==1)
					printf("Palindrome..!!\n");
				else
					printf("Not a palindrome..!!\n");
				break;				
	
		case 4:
				display(head);
				break;
	}
	}while(ch!=5);
	
}
int length(char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++);
	return(i);		
}
node * create(char s[],int n)
{
	node *p,*head;
	int i;
	i=0;
	p=(node *)malloc(sizeof(node));
	p->data=s[i];
	p->next=NULL;
	head=p;
	for(i=1;i<n;i++)
	{
		
		p->next=(node *)malloc(sizeof(node));
		p=p->next;
		p->data=s[i];
		p->next=NULL;
				
	}
	return(head);		
}
void display(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%c\t",p->data);
		p=p->next;
	}
}
node * insert_b(node *head)
{
	node *p;
	char ch;
	p=(node *)malloc(sizeof(node));
	printf("Enter a character:");
		scanf(" %c",&ch);
	p->data=ch;
	p->next=head;
	printf("Character inserted..!!");
	return(p);
}
node * insert_e(node *head)
{
	node *p;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=(node *)malloc(sizeof(node));
	p=p->next;
	printf("Enter a chracter:");
	scanf(" %c",&p->data);
	p->next=NULL;	
	printf("Character inserted..!!");
	return(head);
}
node * insert_be(node *head)
{
	node *p,*q;
	char x;
	p=head;
	q=(node *)malloc(sizeof(node));
	q->next=NULL;
	printf("Enter the character before which you want to insert:");
		scanf(" %c",&x);
	if(p->data==x)
	{
		head=insert_b(head);
		return(head);
	}
	while(p!=NULL)
	{
		if(p->data!=x)
			p=p->next;
		else
			break;
	}
	if(p==NULL)
	{	printf("Character not found..!!");
		return(head);
	}
	p=head;
	printf("Enter the character you want to insert:");
		scanf(" %c",&q->data);
	
	while(p->next->data!=x)
	{
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
	printf("Character inserted..!!");
	return(head);
}
node * insert_ae(node *head)
{
	node *p,*q;
	char x;
	p=head;
	q=(node *)malloc(sizeof(node));
	q->next=NULL;
	printf("Enter the character after which you want to insert:");
		scanf(" %c",&x);
	while(p!=NULL)
	{
		if(p->data!=x)
			p=p->next;
		else
			break;
	}
	if(p==NULL)
	{	printf("Character not found..!!");
		return(head);
	}
	p=head;
	printf("Enter the character you want to insert:");
		scanf(" %c",&q->data);
	while(p->data!=x)
	{
		p=p->next;
	}
	q->next=p->next;
	p->next=q;
	printf("Character inserted..!!");
	return(head);	
}
node * delete_e(node *head)
{
	node *p,*q;
	p=head;
	while(p->next->next!=NULL)
	{
		p=p->next;
	}
	q=p->next;
	p->next=NULL;
	free(q);
	printf("Character deleted..!!");
	return(head);
}
node * delete_b(node *head)
{
	node *q;
	q=head;
	head=head->next;
	free(q);
	printf("Character deleted..!!");
	return(head);
}

node * delete_ae(node *head)
{
	node *p,*q;
	char x;
	p=head;
	printf("Enter the character after which you want to delete:");
		scanf(" %c",&x);
	while(p!=NULL)
	{
		if(p->data!=x)
			p=p->next;
		else
			break;
	}
	if(p==NULL)
	{	printf("Character not found..!!");
		return(head);
	}
	p=head;	
	while(p->data!=x)
	{
		p=p->next;
	}
	if(p->data==x)
	{
		printf("Character not found..!!");
		return(head);
	}
	q=p->next;
	p->next=q->next;
	free(q);
	printf("Character deleted..!!");
	return(head);	
}

node * delete_be(node *head)
{
	int i=0;
	node *p,*q;
	char x;
	p=head;
	printf("Enter the character before which you want to delete:");
		scanf(" %c",&x);	
	if(p->data==x)
	{	
		printf("Character not found..!!");
		return(head);
	}
	while(p!=NULL)
	{
		if(p->data!=x)
			p=p->next;
		else
			break;
	}
	if(p==NULL)
	{	printf("Character not found..!!");
		return(head);
	}
	p=head;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	if(i==2||head->next->data==x)
	{	head=delete_b(head);
		return(head);	
	}
	else
	{		
		p=head;
		while(p->next->next->data!=x)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);
	}
	printf("Character deleted..!!");
	return(head);	
}

int checkpalin(node *head)
{
	int i=0,j,flag=0;
	node *p;
	char s[30];
	p=head;
	while(p!=NULL)
	{
		s[i]=p->data;
		i++;
		p=p->next;
	}
	s[i]='\0';
	i--;
	j=i;
	i=0;
	while(i<j)
	{
		if(s[i]==s[j])
			flag=1;
		else
			return(0);
		i++;
		j--;
	}
	return(1);
}
