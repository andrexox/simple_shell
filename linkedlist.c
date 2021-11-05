#include "shell.h"

/**
 * append_node - Inserts a new tail node
 * @head: Pointer to head
 * @str: String to be stored in the new tail node
 *
 * Return: Pointer to the head
 */
list_t *append_node(list_t **head, const char *str)
{
	list_t *new, *tail;
	size_t len = 0;

	if (!head)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	while (new->str[len])
		len++;
	new->len = len;

	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = new;

	return (new);
}

/**
 * free_list - Frees all nodes in a linked list
 * @head: pointer to head
 *
 * Return: Void
 */
void free_list(list_t *head)
{
	list_t *dup;

	if (head == NULL)
	return;
	for (head->next != NULL; head = dup)
	{
	    dup = head->next;
	    free(head->str);
	    free(head);
	}
	free(head->str);
	free(head);
}

/**
 * add_node - adds a new node to the begining of list_t
 * @head: double pointer to start of list_t
 * @str: string to add
 *
 * Return: pointer to the element in the list
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = _strdup(str);
	new_node->len = _strlen(str);

	new_node->next = *head;

	*head = new_node;
	return (new_node);
}

/**
 * split_str - splits a string into a linked list
 * @string: the null terminated string to split
 * @dlmtr: delimiter
 *
 * Return: str_list_t linked list
 */
str_list_t *split_str(char *const string, const char *dlmtr)
{
	char *tok_ptr, *string_copy;
	str_list_t *head = NULL;

	if (!string || !dlmtr)
		return (NULL);

	string_copy = _strdup(string);

	/* Create nodes for each token */
	tok_ptr = _strtok(string_copy, dlmtr);

	while (tok_ptr)
	{
		if (!append_node(&head, tok_ptr))
		{
			free(head);
			free(string_copy);
			return (NULL);
		}
		tok_ptr = _strtok(NULL, dlmtr);
	}
	free(string_copy);
	return (head);
}
