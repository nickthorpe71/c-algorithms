#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *next;
};

struct queue
{
  struct node *head;
  struct node *tail;
};

void init(struct queue *q)
{
  q->head = NULL;
  q->tail = NULL;
}

void enqueue(struct queue *q, int item)
{
  struct node *n = malloc(sizeof(*n));
  n->item = item;
  n->next = NULL;

  // if the queue is empty
  if (q->head == NULL)
  {
    q->head = n;
    q->tail = n;
  }
  else
  {
    q->tail->next = n;
    q->tail = n;
  }
}

struct node *dequeue(struct queue *q)
{
  struct node *n = q->head;
  q->head = n->next;
  return n;
}

void print(struct queue *q)
{
  struct node *n = q->head;
  while (n != NULL)
  {
    printf("%d ", n->item);
    n = n->next;
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  struct queue q;

  init(&q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  printf("dequeue: %d\n", dequeue(&q)->item);
  enqueue(&q, 23);
  enqueue(&q, 43);
  enqueue(&q, 53);
  printf("dequeue: %d\n", dequeue(&q)->item);
  print(&q);

  return 0;
}