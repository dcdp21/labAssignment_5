#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
	char letter;
	struct node* next;
} node;


int length(node* head)
{
	
	int size = 0;
	while (head != NULL) 
	{
		
		size++;
		 
		head = head->next;
	}
	
	return size;
}


char* toCstring(node* head) 
{
	int size = length(head);
	char* str = (char*)malloc(size + 1);
	int i = 0;
	
	while (head != NULL) 
	{
		str[i] = head->letter;
		head = head->next;
		i++;
	}
	
	str[size] = '\0';
	return str;
}


void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->letter = c;
	newNode->next = NULL;
	if (*pHead == NULL) 
	{
		*pHead = newNode;
	}
	else 
	{
		
		node* currentnode = *pHead;
		while (currentnode->next != NULL)
		{
			currentnode = currentnode->next;
		}
		
		currentnode->next = newNode;
	}
}


void deleteList(node** pHead) 
{
	node* currentnode = *pHead;
	while (currentnode != NULL)
	{
		node* temp = currentnode;
		currentnode = currentnode->next;
		free(temp);
	}
	
	*pHead = NULL;
}


int main(void) 
{
	
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");
	fscanf(inFile, "%d\n", &numInputs);
	while (numInputs > 0) 
	{
		
		fscanf(inFile, "%d\n", &strLen);
		for (i = 0; i < strLen; i++) 
		{
			fscanf(inFile, "%c", &c);
			insertChar(&head, c);
		}
	
		str = toCstring(head);
		printf("String is: (%s)\n", str);
		free(str);
		deleteList(&head);
		if (head != NULL)
		{
			printf("deleteList is not correct!\n");
			break;
		}
		numInputs--;
	}
	fclose(inFile);
	return 0;
}