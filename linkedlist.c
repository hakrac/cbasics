#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
  int prio;
  struct node *next;
} node_t;


void linked_list(node_t **head, int prio) {
  if(*head == NULL) {
    node_t *new = malloc(sizeof(node_t));
    if(new == NULL) {
      return;
    }
    new->prio = prio;
    new->next = NULL;
    *head = new;
  } else {
    if((*head)->prio > prio) {
      node_t *new = malloc(sizeof(node_t));
      new->prio = prio;
      new->next = *head;
      *head = new;
    } else {
      node_t *next = (*head)->next;
      if(next == NULL) {
        // insert
        node_t *new = malloc(sizeof(node_t));
        new->next = NULL;
        new->prio = prio;
        (*head)->next = new; 
        return;
      }
 
      if(next->prio > prio && (*head)->prio < prio) {
        node_t *new = malloc(sizeof(node_t));
        new->next = next;
        new->prio = prio;
        (*head)->next = new; 
      } else {
        node_t *p = (*head)->next;
        linked_list(&p, prio);
      }
    }
  }
}

void printList(node_t **head) {
  if (*head == NULL) {
    printf("NULL.\n");
    return;
  }
  printf("%d -> ", (*head)->prio);
  node_t *p = (*head)->next;
  printList(&p);
}

/*
int main() {
  node_t *head = NULL;
  linked_list(&head, 1);
  linked_list(&head, 4);
  linked_list(&head, 6);
  linked_list(&head, 3);
  linked_list(&head, 0);
  linked_list(&head, 5);
  printf("%d\n", head->prio);
  printList(&head);  
   
  return 0;
}

*/
