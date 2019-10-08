#include <stdio.h>
#include <stdlib.h>
typedef struct node *Nodeptr;

typedef struct node{
int data;
int coeff;
Nodeptr next;
} Node;
Nodeptr getNode(){
Nodeptr temp=(Nodeptr)malloc(sizeof(Node));
temp->next=temp;
return temp;
}
Nodeptr insert(Nodeptr head,int coeff,int x){
Nodeptr temp=getNode();
temp->data=x;
temp->coeff=coeff;
if(!head){
head=getNode();
}
temp->next=head->next;
head->next=temp;
return head;
}
void display(Nodeptr head){
Nodeptr temp=head->next;
    while(temp!=head){
        printf("(%d)x^(%d) +",temp->data,temp->coeff);
        temp=temp->next;
    }
    printf("0\n");
}
Nodeptr sub(Nodeptr l1,Nodeptr l2){
Nodeptr temp=NULL;
Nodeptr t1=l1->next;
Nodeptr t2=l2->next;
while((t1!=l1)&&(t2!=l2)){
if(t1->coeff<t2->coeff){
temp=insert(temp,t2->coeff,-t2->data);
t2=t2->next;
}
else if(t1->coeff>t2->coeff){
temp=insert(temp,t1->coeff,t1->data);
t1=t1->next;
}

else if(t1->coeff==t2->coeff){
temp=insert(temp,t1->coeff,(t1->data)-(t2->data));
t1=t1->next;
t2=t2->next;
}
}
if((t1==l1)&&(t2!=l2)){
 while(t2!=l2){
            temp=insert(temp,t2->coeff,-t2->data);
            t2=t2->next;
            
        }
}
if((t1!=l1)&&(t2==l2)){
 while(t1!=l1){
            temp=insert(temp,t1->coeff,t1->data);
            t1=t1->next;
            
        }
}
return temp;
}
Nodeptr mul(Nodeptr l1,Nodeptr l2){
Nodeptr temp=NULL;
Nodeptr t1=l1->next;
Nodeptr t2=l2->next;
while(t1!=l1){
t2=l2->next;
while(t2!=l2){
temp=insert(temp,t1->coeff+t2->coeff,(t1->data)*(t2->data));
t2=t2->next;
}
t1=t1->next;
}
return temp;
}
int main(){
    Nodeptr l1=NULL;
  l1=insert(l1,3,3);
l1=insert(l1,1,4);
l1=insert(l1,0,7);
Nodeptr l2=NULL;
l2=insert(l2,2,2);
l2=insert(l2,1,1);
l2=insert(l2,0,1);
Nodeptr sublist=sub(l1,l2);
display(sublist);
Nodeptr mullist=mul(l1,l2);
display(mullist);
}
    