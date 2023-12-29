#include <stdlib.h>
#include <string.h>
#include <stdio.h>



/**
 *
 **/

typedef struct _path
{
  char *path;
  struct _path *next;
} _path;


_path head;


/**
 *
 **/

_path *linked_path ()
  {
    _path *temp;
    char *temp_path = getenv("PATH");
    char *list_path = strtok(temp_path, ":");
    if (list_path == NULL)
      return (NULL);
    
    head.path = malloc((strlen(list_path) + 1) * sizeof(char));
    if (head.path == NULL)
      {
	perror("malloc fails!!!\n");
	return (NULL);
      }

    strcpy(head.path, list_path);
    head.next = NULL;
    
    temp = &head;

    while (1)
      {
	list_path = strtok(NULL, ":");
	if (list_path != NULL)
	  {
	    temp->next = malloc(sizeof(_path));
	    if (temp->next == NULL)
	      return (NULL);
	    
	    temp = temp->next;
	    temp->path = malloc((strlen(list_path) + 1) * sizeof(char));
	    if (temp->path == NULL)
	      return (NULL);

	    strcpy(temp->path, list_path);
	    temp->next = NULL;
	  }
	else
	  {
	    return (&head);
	  }
      }
  }


/**
 *
 **/

int main()
  {
    _path *nodes;
    nodes = linked_path();
    if (nodes == NULL)
      return (-1);

    while (nodes != NULL)
      {
	printf("%s\n", nodes->path);
	nodes = nodes->next;
      }

    return (0);
  }
