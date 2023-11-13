#include "shell.h"

/**
 *createNode - Creates a single node linked list
 *@dir: pointer to the provided directory
 *
 *Return: Pointer to a linked list
 */
linkedd1 *createNode(const char *dir)
{
	linkedd1 *node;

	node = malloc(sizeof(linkedd1));
	if (node)
	{
		node->dir = strdup(dir);
		node->next = NULL;
	}
	return (node);
}

/**
 *insertNode - inserts node at the end of linked list
 *@head: Pointer to the end of the node
 *@dir: string to be added in the node
 *
 *Return: Nothing
 */
void insertNode(linkedd1 **head, const char *dir)
{
	linkedd1 *newNode = createNode(dir);
	linkedd1 *currentNode;

	if (!newNode)
	{
		printError("Memory allocation failed\n");
		exit(1);
	}
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		currentNode = *head;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}
/**
 *printList - List printer
 *@head: pointer to string
 *
 *Return: Nothing
 */
void printList(linkedd1 *head)
{
	while (head != NULL)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
}
/**
 *main2 - Entry point
 *
 *Return: 0 (Success)
 */
int main2(void)
{
	char *path = _getenv("PATH");
	linkedd1 *head = NULL;
	char *token;
	linkedd1 *temp;

	if (path == NULL)
	{
		printf("NO PATH Environment.\n");
		return (1);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		insertNode(&head, token);
		token = strtok(NULL, ":");
	}
	printList(head);
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
	return (0);
}
