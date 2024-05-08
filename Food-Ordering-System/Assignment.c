/**********************************************************************************************************
Course: DCP5101 Program Design
Assignment: 1
Session: T2215
Group Name: Elon Ma 
ID & Name 1: 1221201573, PRAGASH VARMAN A/L RAJASEGARAN 
Phone,Email: 0182380482, 1221201573@student.mmu.edu.my
ID & Name 2: 1221201502, CHEW JUN JIE
Phone, Email: 0174668053, 1221201502@student.mmu.edu.my
ID & Name 3: 1221201921, KEVIN LIM FU WEI
Phone, Email: 01139774170, 1221201921@student.mmu.edu.my
ID & Name 4: 1221202391, MUHAMMAD AMMAR AR - RASYID
Phone, Email: 0176572142, 1221202391@student.mmu.edu.my
**************************************************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void Displaybill(struct Bill* bill);
float CalculateDiscount(struct Bill* bill);

struct Item 
{
	char name[50];
	float price;
	int quantity;
};

struct Bill 
{
  struct Item items[50];
  int itemCount;
  float total;
  float discount;
  float totalamount;
};

int main() 
{	
	FILE *fread;
	fread = fopen("menu.txt", "r");
    if(fread != NULL)
	{
        char c;
        while((c = fgetc(fread)) != EOF) 
		{
            putchar(c);
        }
        fclose(fread);
	} 
	else 
	{
        printf("Error opening file\n");
	}
	
	struct Bill bill;
	bill.itemCount = 0;
	bill.total = 0;
	bill.discount = 0;
	bill.totalamount = 0;

	char choice;
	do {
		struct Item item;
		printf("Enter item code: ");
		scanf(" %c", &choice);
		switch(choice)
		{
			case 'A' :
				strcpy(item.name, "French Toast");
				item.price = 10.00;
				break;
			
			case 'B':
				strcpy(item.name, "Egg Benedict");
				item.price = 12.90;
				break;
			
			case 'C':
				strcpy(item.name, "Butter Pancakes");
				item.price = 11.50;
				break;
			
			case 'D':
				strcpy(item.name, "Coffee");
				item.price = 8.00;
				break;
			
			case 'E':
				strcpy(item.name, "Green Tea");
				item.price = 5.60;
				break;
			
			case 'F':
				strcpy(item.name, "Orange Fruit Juice");
				item.price = 7.00;
				break;
			
			case 'G':
				strcpy(item.name, "Apple Pie");
				item.price = 4.60;
				break;
			
			case 'H':
				strcpy(item.name, "Donuts");
				item.price = 4.00;
				break;
			
			case 'I':
				strcpy(item.name, "Chocolate Chip Cookies");
				item.price = 3.50;
				break;
			
			default:
				printf("\n\nInvalid choice,  please enter a valid code\n\n\n");
				main();
				continue;

		}
		
	printf("Enter item quantity: ");
	scanf("%d", &item.quantity);
	bill.items[bill.itemCount] = item;
	bill.itemCount++;
	bill.total += item.price * item.quantity;
	
	printf("Do you want to enter another item? (y/n): ");
	scanf(" %c", &choice);
	} while (choice == 'y' || choice == 'Y');

	CalculateDiscount(&bill);
	bill.totalamount = bill.total - bill.discount;

	Displaybill(&bill);	

	return 0;
}

void Displaybill(struct Bill* bill) 
{
	printf("\n\t\t\t\t    Bill:\n\n");
	for (int i = 0; i < bill->itemCount; i++) 
	{
		struct Item item = bill->items[i];
		printf("%d. %s,\t Price of one: %.2f\t Quantity: %d\t Total: %.2f\n", i + 1, item.name, item.price, item.quantity, item.price * item.quantity);  
	}

	printf("\nTotal Amount: %.2f\n", bill->total);
	printf("Discount: %.2f\n", bill->discount);
	printf("Net Payable: %.2f\n", bill->totalamount);
}

float CalculateDiscount(struct Bill* bill)
{
    char code;
    printf(" (Y/N) :  ");
    scanf(" %c", &code);

    if(code == 'Y' || code == 'y')
    {
        printf("Enter Discount Code (disTen or disTwenty): ");
        char discount[10];
        scanf("%s",  discount);

        if (strcmp(discount, "disTen")== 0)
            bill->discount = (10.0 / 100.0) * bill->total;

        else if(strcmp(discount, "disTwenty")== 0)
            bill->discount = (20.0 / 100.0) * bill->total;

        else
            printf("Your Discount Code is Invalid. Discount has been set to Zero.\n");

    }
    else if (code == 'N' || code == 'n')
    {
        bill->discount = 0;
  
    }
    else
    {
        printf("Invalid input. Please enter 'y' or 'n'\n");
        CalculateDiscount(bill);
    }
	
	return bill->discount;
}