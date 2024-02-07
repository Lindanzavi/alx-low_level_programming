#include "lists.h"
#include <stdlib.h>

/* Define the structure for the linked list */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

size_t free_listint_safe(listint_t **h) {
    size_t node_count = 0;
    listint_t *current = *h;
    listint_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
        node_count++;
    }

    *h = NULL; // Set the head to NULL after freeing the list
    return node_count;
}

