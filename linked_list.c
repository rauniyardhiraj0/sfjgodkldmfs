// Singly Linked List Using C Language........

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL,*temp;

void insert(){
    int num;
    printf("Enter the no. of nodes: ");
    scanf("%d", &num);
    while (num != 0) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data to be inserted: ");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        printf("Successfully added...\n");
        num--;
    }
}

void insertAtBeginning() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Successfully added at the beginning...\n");
}

void insertAtLast(){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }else{
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Successfully added....\n");
    
}

void insertAtAnyPoint(){
    int pos,i;
    printf("Enter the position: ");
    scanf("%d",&pos);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted: ");
    scanf("%d",&newnode->data);
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }else{
        temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Overflow....\n");
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("Successfully added.....\n");
    
}

void deleteAnyNode(){
    int pos;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d",&pos);
    struct node *head, *temp,*Q;
    temp = head;
    if (pos == 0){
        head = temp->next;
        free(temp);
    }
    else{
        for (int i = 0; i < pos-1; i++)
        {
            temp =  temp->next;
        }
        Q = temp->next;
        temp->next = Q->next;
        free(Q);
    }
}
void display(){
    struct node *head,*temp;
    temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    insert();
    deleteAnyNode();
    display();
    return 0;
}
