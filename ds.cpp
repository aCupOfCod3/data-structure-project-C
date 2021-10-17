#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item{
	int itemCodes;
	char desc[100];
	int quantity;
	long int price;
	item *next;
}*head = NULL, *tail=NULL;

void print(){
	struct item *curr = head;
	//empty
	if(!curr){
		printf("the list is empty\n");
		return;
	}
	//if not empty then traverse the linked list and print all elements
	else{
		while(curr){
			printf("Item Codes	:%d\n",curr->itemCodes);
			printf("Description	:%s\n",curr->desc);
			printf("Quantity	:%d\n",curr->quantity);
			printf("Price		:%ld\n",curr->price);
			printf("\n");
			curr=curr->next;
		}
		
	}
}

//push / insert elements
void insert(int itemCodes, char *desc, int quantity, long int price){
	struct item* curr = (struct item*)malloc(sizeof(struct item));
	curr->itemCodes = itemCodes;
	strcpy(curr->desc,desc);
	curr->quantity = quantity;
	curr->price = price;
	curr->next = NULL;
	
	//sortedInsert
	if(head==NULL||head->itemCodes >= curr->itemCodes){
		curr->next = head;
		head = curr;
		return;
	}
	
	struct item *temp = head;
	while(temp->next!=NULL&&temp->next->itemCodes<curr->itemCodes){
		temp = temp->next;
	}
	curr->next = temp->next;
	temp->next = curr;
}

void update(int itemcode){
	int newQuantity;
	int newPrice;
	char newDesc[100];
	
	struct item *curr = head;
	while(curr!=NULL){
		if(curr->itemCodes==itemcode){
			printf("Enter the new data to update the old data:\n");
			printf("Desc	: ");
			scanf("%[^\n]s", newDesc);
			printf("Quantity	: ");
			scanf("%d", &newQuantity);getchar();
			printf("Price	: ");
			scanf("%d", &newPrice);getchar();
			
			strcpy(curr->desc,newDesc);
			curr->quantity = newQuantity;
			curr->price = newPrice;
			printf("Updated Successfully!\n");
			return;
		}
		else{
			curr = curr->next;
		}
	}
	
	printf("item code  %d not found!\n",itemcode);
}

void delete_data(int itemcode){
	if(head==NULL){
		printf("The list is empty!\n");
		return;
	}
	if(head->itemCodes==itemcode){
		if(head->next!=NULL){
			head = head->next;
			return;
		}
		else{
			head = NULL;
			printf("List is Empty Now\n");
			return;
		}
	}else if(head->itemCodes!=itemcode && head->next==NULL){
		printf("Item code %d is not found\n");
		return;
	}
	struct item *curr = head;
	while(curr->next!=NULL && curr->itemCodes!=itemcode){
		tail = curr;
		curr = curr->next;
	}
	if(curr->itemCodes == itemcode){
		tail->next = tail->next->next;
		free(curr);
	}
	else{
		printf("item code %d is not found\n");
	}
}


int main(){
	int choice;
	int itemcode;
	char desc[100];
	int quantity;
	long int price;
	do{
		printf("\n");
		printf("* * * *MAIN MENU* * * *\n");
		printf("1:	Add Items\n");
		printf("2:	Display Items\n");
		printf("3:	Edit Items\n");
		printf("4:	Delete Items\n");
		printf("5:	EXIT\n");
		printf("\n");
		printf("Enter your Option: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Please enter the followong details:\n");
				printf("Item Codes	: ");
				scanf("%d", &itemcode);getchar();
				printf("Desc	: ");
				scanf("%[^\n]s", desc);getchar();
				printf("Quantity	: ");
				scanf("%d", &quantity);getchar();
				printf("Price	: ");
				scanf("%ld", &price);getchar();
				insert(itemcode,desc,quantity,price);
				break;
			
			case 2:
				print();
				break;
			
			case 3:
				printf("Enter the item code for updating the item: ");
				scanf("%d", &itemcode);getchar();
				update(itemcode);
				break;
				
			case 4:
				printf("Enter the item code for the item you want to remove: ");
				scanf("%d", &itemcode);
				delete_data(itemcode);
				break;
			
			case 5:
				printf("see you next time :)\n");
				break;
			
				
		}
	}while(choice!=5);
	
	
	
	
	return 0;
}

