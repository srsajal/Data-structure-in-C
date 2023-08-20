#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int data;
	struct list * link;
}node;
node * start = NULL;
int getinteger()
{
	int c;
	while(scanf("%d",&c) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input. Please enter an integer : ");
	}
	return c;
}
void print()
{
	node * tmp;
	tmp = start;
	if(tmp == NULL)
	{
		printf("...................... The list is empty ......................\n");
	}
	else
	{
		printf("The given data stored in linked list is :-\n\n");
		while(tmp != NULL)
		{
			printf("%d\t",tmp -> data);
			tmp = tmp -> link;		
		}
		printf("\n\n");
	}
}
void insert_at_begin(int data)
{
	node * newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> link = NULL;
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		newnode -> link = start;
		start = newnode;
	}
}
void insert_at_end(int data)
{
	node * newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> link = NULL;
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		node * tmp;
		tmp = start;
		while( tmp -> link != NULL)
		{
			tmp = tmp -> link;
		}
		tmp -> link = newnode;
	}
}
void insert_at_position(int n, int data)
{
	int count=1;
	node * tmp = start;
	node * newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> link = NULL;
	if(start == NULL)
	{
		start = newnode;
		if(n!=1)
		{
			printf("...................... Any data is not stored, so this is the first number(position 1) ......................\n");
		}
	}
    else if(n == 1)
    {
        newnode -> link = start;
        start = newnode;
		printf("...................... Susccessfully inserted ......................\n");
    }
	else
	{
		while(tmp -> link != NULL && count != (n-1))
		{
			count++;
			tmp = tmp -> link;
		}
		if(count == (n-1))
        {
            newnode -> link = tmp -> link;
            tmp -> link = newnode;
			printf("...................... Susccessfully inserted ......................\n");
        }
		else
		{
			printf(".........................WRONG INPUT........................\nCheck the stored number below and give the correct position :-\n");
			print();
		}
	}
}
void after_value_insert(int n, int data)
{
	node * tmp = start;
	node * newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> link = NULL;
	if(start == NULL)
	{
		start = newnode;
		if(n!=1)
		{
			printf("...................... Any data is not stored, so this is the first number(position 1) ......................\n");
		}
	}
	else
	{
		while(tmp -> link != NULL && tmp -> data != n)
		{
			tmp = tmp -> link;
		}
		if( n == tmp -> data )
		{
			newnode -> link = tmp -> link;
			tmp -> link = newnode;
			printf("...................... Susccessfully inserted ......................\n");	
		}
		else
		{
			printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
			print();
		}		
	}
}
void before_value_insert(int n, int data)
{
	node * tmp = start;
	node * prev = start;
	node * newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> link = NULL;
	if(start == NULL)
	{
		start = newnode;
		printf("...................... Any data is not stored, so this is the first number(position 1) ......................\n");
	}
    else if(start -> data == n)
    {
        newnode -> link = start;
        start = newnode;
		printf("...................... Susccessfully inserted ......................\n");
    }
	else
	{
        while(tmp -> link != NULL && tmp -> data != n)
        {
            prev = tmp;
            tmp = tmp -> link;
        }
        if( n != tmp -> data )
        {
            printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
            print();
        }
        else
        {
            newnode -> link = prev -> link;
            prev -> link = newnode;
			printf("...................... Susccessfully inserted ......................\n");
        }		
	}
}
void reverse()
{
	if(start == NULL)
	{
		printf("...................... Can't reverse, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		printf("...................... Check the stored number(At least two number needs to reverse) ......................\n");
		print();
	}
	else if(start -> link -> link == NULL)
	{
		start -> link -> link = start;
		start = start -> link;
		start -> link -> link = NULL;
		printf("...................... Successfully reversed ......................\n");
	}
	else
	{
		node *tmp, *prev, *next;
		prev = tmp = next = start;
		while(next -> link != NULL)
		{
			prev = tmp;
			tmp = next;
			next = next -> link;
			if(prev == start && tmp != start)
			{
				prev -> link = NULL;
				tmp -> link = prev;
			}
			else if(prev != start)
			{
				tmp -> link = prev;
			}
		}
		next -> link = tmp;
		start = next;
		printf("...................... Successfully reversed ......................\n");
	}
}
void del_end()
{
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		free(start);
		start = NULL;
		printf("...................... Susccessfully deleted ......................\n");
	}
	else
	{
		node * tmp;
		node * prev;
		prev = tmp = start;
		while(tmp -> link != NULL)
		{
			prev = tmp;
			tmp = tmp -> link;
		}
		prev -> link = NULL;
		free(tmp);
		printf("...................... Susccessfully deleted ......................\n");
	}
}
void del_beg()
{
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		free(start);
		start = NULL;
		printf("...................... Susccessfully deleted ......................\n");
	}
	else
	{
	node * tmp;
	tmp = start;
	start = start -> link;
	free(tmp);
	printf("...................... Susccessfully deleted ......................\n");
	}
}
int del_at_position(int n)
{
	node * tmp = start;
	node * prev = start;
	int count=1, c=0;
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(n==1)
	{
		start = start -> link;
		free(tmp);
		c=1;
	}
	else
	{
		while(tmp -> link != NULL && count != n)
		{
			count++;
			prev = tmp;
			tmp = tmp -> link;
		}
		if(count == n)
		{
			prev -> link = tmp -> link;
			free(tmp);
			c=1;
		}
		else
		{
			printf(".........................WRONG INPUT........................\nCheck the stored number below and give the correct position :-\n");
			print();
		}
	}
	return c;
}
void del_particular_value()
{
	int data;
	printf("Enter the value to delete : ");
	data = getinteger();
	node * tmp = start;
	node * prev = start;
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> data == data)
	{
		start = start -> link;
		free(tmp);
		printf("...................... Susccessfully deleted ......................\n");
	}
	else
	{
        while(tmp -> link != NULL && tmp -> data != data)
        {
            prev = tmp;
            tmp = tmp -> link;
        }
        if( data == tmp -> data )
        {
            prev -> link = tmp -> link;
            free(tmp);
			printf("...................... Susccessfully deleted ......................\n");
        }
        else
        {
            printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
            print();
        }	
	}
}
void del_particular_all_value()
{
	int data ,c=1;
	printf("Enter the value to delete : ");
	data = getinteger();
	node * tmp = start;
	node * prev = start;
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else
	{
		while(tmp -> link != NULL)
		{
			if(start -> data == data)
			{
				start = start -> link;
				free(tmp);
				tmp = start;
				c=0;
			}
			else if(data == tmp -> data)
			{
				prev -> link = tmp -> link;
				free(tmp);
				tmp = prev -> link;		
				c=0;
			}
			else
			{
				prev = tmp;
				tmp = tmp -> link;
			}			
		}
        if(tmp -> data == data)
        {
            if(start -> link == NULL)
			{
				start = NULL;
				free(tmp);
				c=0;
			}
			else
			{
				prev -> link = NULL;
				free(tmp);
				c=0;
			}
        }
		if(c)
		{
			printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
			print();
		}
		else
		{
			printf("...................... Susccessfully deleted ......................\n");
		}
	}
}
void before_value_delete()
{
	int data;
	printf("Enter the checking value to delete : ");
	data = getinteger();
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		printf("...........................WRONG INPUT..........................\nCheck the stored number(At least two number needs for this process)\n");
		print();
	}
	else if(start -> data == data)
	{
		printf(".................................WRONG INPUT................................\nThe given number is the first number so there is no number to delete before it. Check the number.... :-\n");
		print();
	}
	else if(start -> link -> data == data)
	{
		del_beg();
	}
	else
	{
		node *tmp, *prev;
		tmp = prev = start;
		while(tmp -> link -> link != NULL && tmp -> link -> data != data)
		{
			prev = tmp;
			tmp = tmp -> link;
		}
		if(tmp -> link -> data == data)
		{
			prev -> link = tmp -> link;
			free(tmp);
			printf("...................... Susccessfully deleted ......................\n");
		}
		else
		{
			printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
			print();
		}
	}
}
void after_value_delete()
{
	int data;
	printf("Enter the checking value to delete : ");
	data = getinteger();
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		printf("...........................WRONG INPUT..........................\nCheck the stored number(At least two number needs for this process) :-\n");
		print();
	}
	else if(start -> data == data)
	{
		node * tmp = start -> link;
		start -> link = tmp -> link;
		free(tmp);
		printf("...................... Susccessfully deleted ......................\n");
	}
	else
	{
		node *prev , *tmp;
		prev = tmp = start;
		while(tmp -> link != NULL && prev -> data != data)
		{
			prev = tmp;
			tmp = tmp -> link;
		}
		if(prev -> data == data)
		{
			prev -> link = tmp -> link;
			free(tmp);
			printf("...................... Susccessfully deleted ......................\n");
		}
		else
		{
			printf("...........................WRONG INPUT..........................\nCheck the stored number below and give the correct checking number :-\n");
			print();
		}
	}
}
void del_position_to_position()
{
	if(start == NULL)
	{
		printf("...................... Can't delete, The list is empty ......................\n");
	}
	else if(start -> link == NULL)
	{
		printf("...................... Check the stored number(At least two number needs for this process) .....................\n");
		print();
	}
	else
	{
		int s, l, count=1;
		node * tmp = start;
		printf("Enter the starting position(The given position also will be deleted, start form 1) : ");
		s = getinteger();
		printf("Enter the last position(The given position also will be deleted, start form 1) : ");
		l = getinteger();
		while(tmp -> link != NULL)
		{
			count++;
			tmp = tmp -> link;
		}
		if(s>0 && s<count && l>s && l<=count)
		{
			for(int i=s;i<=l;i++)
			{
				count = del_at_position(s);
			}
			if(count == 1)
			{
				printf("...................... Susccessfully deleted ......................\n");
			}
		}
		else
		{
			printf(".........................WRONG INPUT........................\nCheck the stored number below and give the correct position :-\n");
			print();
		}
	}	
}
void getDataDelPosition()
{
	printf("Enter which position you want to delete : ");
	if(del_at_position(getinteger()))
	{
		printf("...................... Susccessfully deleted ......................\n");
	}
}
void getDataBegin()
{
	int n;
	printf("Enter how many number you want to store : ");
	n = getinteger();
	if(n>0)
	{
		for(int i=0;i<n;i++)
		{
			printf("Enter value : ");
			insert_at_begin(getinteger());
		}
		printf("...................... Susccessfully inserted ......................\n");
	}
	else
	{
		printf("...................WRONG INPUT..................\n\t\tPlease try again\n");
	}
}
void getDataEnd()
{
	int n;
	printf("Enter how many number you want to store : ");
	n = getinteger();
	if(n>0)
	{
		for(int i=0;i<n;i++)
		{
			printf("Enter value : ");
			insert_at_end(getinteger());
		}
		printf("...................... Susccessfully inserted ......................\n");
	}
	else
	{
		printf("...................WRONG INPUT..................\n\t\tPlease try again\n");
	}	
}
void getDataPosition()
{
	int n;
	printf("In which position you want to store the number(start from 1) : ");
	n = getinteger();
	printf("Enter the value : ");
	insert_at_position(n, getinteger());
}
void getbeforevalueinsert()
{
	int n;
	printf("Enter the checking value(before data) : ");
	n = getinteger();
	printf("Enter the value : ");
	before_value_insert(n, getinteger());
}
void getaftervalueinsert()
{
	int n;
	printf("Enter the checking value(after data) : ");
	n = getinteger();
	printf("Enter the value : ");
	after_value_insert(n, getinteger());
}
int main()
{
	printf("You are in Sajal's program..............\n");
	do
	{
		printf("what do you want to do(press the number) :-\n1. Insert number\t2. Delete number\t3. Print number\t\t 4. Reverse list\t5. Exit : ");
		switch(getinteger())
		{
			case 1:
			{
				printf("How do you want to store(press the number) :-\n1. Insert from beginning\t2. Insert from end\t3. Insert at any position\n4. Insert at before value\t5. Insert at after value\t6. Back : ");
				switch(getinteger())
				{
					case 1:
					{
						getDataBegin();
						break;
					}
					case 2:
					{
						getDataEnd();
						break;
					}
					case 3:
					{
						getDataPosition();
						break;
					}
					case 4:
					{
						getbeforevalueinsert();
						break;
					}
					case 5:
					{
						getaftervalueinsert();
						break;
					}
					case 6:
					{
						break;
					}
					default:
					{
						printf("...................WRONG INPUT..................\n\t\tPlease try again\n");
					}
				}
				break;
			}
			case 2:
			{
				printf("How do you want to delete(press the number) :-\n1. Delete at beginning\t\t2. Delete at end\t3. Delete at position\t\t4. Delete position to position\n5. Delete particular first value\t\t6. Delete particular all value\t\t7. Delete before the particular value\n8. Delete after the particular value\t\t9. Back : ");
				switch(getinteger())
				{
					case 1:
					{
						del_beg();
						break;
					}
					case 2:
					{
						del_end();
						break;
					}
					case 3:
					{
						getDataDelPosition();
						break;
					}
					case 4:
				   	{
						del_position_to_position();
						break;
				   	}
					case 5:
				   	{
						del_particular_value();
						break;
				   	}
				   	case 6:
				   	{
				   		del_particular_all_value();
				   		break;
				   	}
					case 7:
				   	{
				   		before_value_delete();
				   		break;
				   	}
					case 8:
				   	{
				   		after_value_delete();
				   		break;
				   	}
					case 9:
					{
						break;
					}
					default:
					{
						printf("...................WRONG INPUT..................\n\t\tPlease try again\n");
					}
				}
				break;
			}
			case 3:
			{
				print();
				break;
			}
			case 4:
			{
				reverse();
				break;
			}
			case 5:
			{
				printf("ok check the number last time :-\n");
				print();
				return 0;
				break;
			}
			default :
			{
				printf("...................WRONG INPUT..................\n\t\tPlease try again\n");
			}
		}
	}while(1);
	return 0;
}