//Josepus problem... 
/*This is a problem we need to find the k-th winner.. that is we need to delete each person everytime at the k-time and then we need to find the //last persion who left*/

#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
//to define a linked list
struct node
{
	int data;
	struct node *next;
};
int main()
{
	int a,c=0,t=1,p;
	struct node *rand,*ptr,*start=NULL,*temp;
	printf("\n \t lets create a circular linked list ....\n");
	printf("\n\n\twhen you enter -1 only you can exit from creation");
	printf("\n\nenter the player id:");
	scanf("%d",&a);
	
	// we are reading(regestring) the persons details and making a linked list(circular)...
	while(a!=-1)
	{
		rand=(struct node*)malloc(sizeof(struct node));
			rand->data=a;
			rand->next=rand;
			if(start==NULL)
			{
				start=rand;
				ptr=rand;
			}
			else
			{
				ptr->next=rand;
				ptr=rand;
				rand->next=start;
			}
			printf("\nenter the player id:");
			scanf("%d",&a);
		}
		ptr=start;
		//We are printing the players... who were registered.
		printf("The players are:\n");
		while(ptr->next!=start)
		{
		       c++;
		       printf("\t%d",ptr->data);
		       ptr=ptr->next;
		       if(ptr->next==start)
				printf("\t%d",ptr->data);
		}
		c++;
		//Reading the Kth term to start the problem(game)
		printf("\nenter the position:\t");
		scanf("%d",&p);
	ptr=start;
	while(c!=1)
	{
		if(t==p-1)
		{
			temp=ptr->next;
			ptr->next=ptr->next->next;
			free(temp);
			c--;
			t=0;
		}
		ptr=ptr->next;
		t++;
	}
		if(c==1)
		printf("\nthe winner is:%d",ptr->data);
//getch();
}

