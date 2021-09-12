#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}list;

list*create(list *l)
{
    l=NULL;
    return l;
}
int insert_pos(list **l,int num,int pos)
{
    list*temp;
    list*new_node;
    temp=*l;
    if(pos==0)
    {
        temp = (list*)malloc(sizeof(list));
        temp->info=num;
        temp->next=*l;
        *l=temp;
        return 1;
    }
    else
    {

        int i;
        new_node = (list*)malloc(sizeof(list));
        new_node->info=num;
        new_node->next=NULL;
       for(i=1;i<=pos-1;i++)
       {
           temp=temp->next;
           if(temp==NULL)
           {
               return 0;
           }
       }

        new_node->next=temp->next;
        temp->next=new_node;
        return 1;
    }

}

int insert_end(list **l,int num)
{
    list *temp,*new_node;
    temp=*l;
    new_node = (list*)malloc(sizeof(list));
    if(new_node == NULL)
    {
        return 0;
    }
    else
    {
        new_node->info=num;
        new_node->next=NULL;
        if(temp!=NULL)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

        temp->next=new_node;
        return 1;
        }
        else
        {
            *l=temp;
            return 1;
        }
    }
}
int del(list **l,int num)
{
    list *temp,*old;
    temp=*l;
    old=NULL;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
       if(temp->info == num)
        {
                if(temp==*l)
                {
                    *l=temp->next;
                    free(temp);
                    return 1;
                }
        }
        while(temp!=NULL && temp->info!=num)
        {
            old = temp;
            temp = temp->next;
        }
        if(temp==NULL)
            return 0;
        else
        {
            old->next=temp->next;
            free(temp);
            return 1;

        }
    }


}
void display(list *l)
{
    list*temp;
   if(l== NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = l;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->info);
            temp = temp->next;
        }
    }
}
list *reverse(list *l)
{
    struct node *prevNode, *curNode;
    struct node *temp=l;
    if(l!= NULL)
    {
        prevNode = temp;
        curNode = temp->next;
        temp = temp->next;
        prevNode->next = NULL;
        while(temp != NULL)
        {
            temp = temp->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = temp;
        }
        temp = prevNode;
        return(temp);
    }
}


int main()
{
    list *l,*c,*r;
    r=c=NULL;
    c=create(l);
    int item,pos,check,n,k;
    char ch;
    printf("Press 1 to start");
    scanf("%d",&k);
    while(k==1)
    {
        printf("\t\tMENU");
        printf("\n1.Press 1 for inserting at any position. ");
        printf("\n2.Press 2 for inserting at end. ");
        printf("\n3.Press 3 for deleting. ");
        printf("\n4.Press 4 for Reversing. ");
        printf("\n5.Press 5 for Displaying. ");
        scanf("%d",&n);
        switch(n)
        {

            case 1: printf("\nEnter the element you want to enter: ");
                    scanf("%d",&item);
                    printf("Enter the position where you want to enter the element: ");
                    scanf("%d",&pos);
                    check=insert_pos(&c,item,pos);
                    if(check==1)
                    {
                        printf("Insert successful");
                    }
                    else
                    {
                        printf("Insert unsuccessful");
                    }
                    break;
            case 2: printf("\nEnter the element you want to enter: ");
                    scanf("%d",&item);

                    check=insert_end(&c,item);
                    if(check==1)
                    {
                        printf("Insert Successful");
                    }
                    else
                    {
                        printf("Insert unsuccessful");
                    }
                    break;
            case 3:
                    printf("Enter the element you want to delete: ");
                    scanf("%d",&item);
                    check=del(&c,item);
                    if(check==1)
                    {
                        printf("Deleted");

                    }
                    else
                    {
                        printf("Element was not deleted.");
                    }
                    break;
            case 4: printf("The reverse of the list is:\n");
                    c=reverse(c);
                    display(c);
                    break;
            case 5: display(c);
                    break;
            default:printf("Invalid input");
        }
        printf("\nDo you want to continue?(1/0): ");
        scanf("%d",&k);
    }
    return 0;
}




























