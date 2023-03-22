#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;
node *head;
void display(){
   node *temp=head;
    for(;;){
        printf("%d\n", temp->data);
         if(temp->next!=NULL){
            temp=temp->next;
         }else{
            break;
         }

    }
}
void create(int n){
    node *temp=head;
    for(int i=1; i<n; i++){
        node *newnode;
        newnode=(node*)malloc(sizeof(node));
        printf("Enter data for %d no node:",i+1);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}
void ins_beg(){
    node *newnode=(node*)malloc(sizeof(node));
    printf("Enter data for inset begining:");
    scanf("%d", &newnode->data);
    newnode->next=head;
    head=newnode;
}
void  del_beg(){
    node *temp=head->next;
    free(head);
    head=temp;
}
void ins_end(){
    node *newnode=(node*)malloc(sizeof(node));
    printf("Enter data for insert ending:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    node *temp=head;
    for(;;){
        if(temp->next!=NULL){
            temp=temp->next;
        }else{
            break;
        }
    }
    temp->next=newnode;
}
void del_end(){
    node *p,*q;
    p=head;
    q=head->next;
    for(;;){
        if(q->next!=NULL){
            p=p->next;
            q=q->next;
        }else{
            break;
        }
    }
    free(q);
    p->next=NULL;
}
void ins_mid(){
    node *newnode=(node*)malloc(sizeof(node));
    printf("Enter data for mddle insert:\n");
    scanf("%d", &newnode -> data);
    int x;
    printf("In which position do you want to insert data?\n");
    scanf("%d",&x);
    printf("\n\n");
    node *p, *q;
    p=head;
    q=head->next;
    for(int i=1; i<x-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=newnode;
    newnode->next=q;

}
void del_mid(){
    int x=2;
    node *p, *q;
    p=head;
    q=head->next;
    for(int i=1;i<x;i++){
        p=p->next;
        q=q->next;
    }
    node *temp=q->next;
    free(q);
    p->next=temp;
}
void main(){
    int n;
    scanf("%d", &n);
   printf("\n Create and display:\n");
    head=(node *)malloc(sizeof(node));
    printf("Enter data for 1 no node:\n");
    scanf("%d", &head->data);
    head->next=NULL;
    create(n);
    display();
    // printf("\n Insert Beginning and disply:\n");
    // ins_beg();
    // display();
    // printf("\n Delete beginning and disply:\n");
    //  del_beg();
    //  display();
    //  printf("\n List insert beginning and display:\n");
    //  ins_end();
    //  display();
    //  printf("\n Delete last insert beginning and display:\n");
    //  del_end();
    //  display();
     printf("\n Insert middle and display:\n");
     ins_mid();
     display();
     printf("\n Insert deleat middle and display:\n");
    del_mid();
    display();



}

