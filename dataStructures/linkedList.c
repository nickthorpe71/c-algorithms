#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *next;
};

struct list
{
  struct node *head;
  struct node *tail;
};

void listInit(struct list *l)
{
  l->head = NULL;
  l->tail = NULL;
}

void listAppend(struct list *l, int item)
{
  struct node *n = malloc(sizeof(*n));
  n->item = item;
  n->next = NULL;

  if (l->head == NULL)
  {
    l->head = n;
    l->tail = n;
  }
  else
  {
    l->tail->next = n;
    l->tail = n;
  }
}

void listInsertAfter(struct list *l, int item, int after)
{
  struct node *n = malloc(sizeof(*n));
  n->item = item;
  n->next = NULL;

  struct node *p = l->head;
  while (p != NULL)
  {
    if (p->item == after)
    {
      n->next = p->next;
      p->next = n;
      if (p == l->tail)
        l->tail = n;

      return;
    }
    p = p->next;
  }
}

void listMoveNextToFront(struct list *l, int item)
{
  struct node *p = l->head;
  struct node *prev = NULL;
  while (p != NULL)
  {
    if (p->item == item)
    {
      if (prev != NULL)
      {
        prev->next = p->next;
        p->next = l->head;
        l->head = p;
      }
      return;
    }
    prev = p;
    p = p->next;
  }
}

void listSwap(struct list *l, int item1, int item2)
{
  struct node *p1 = l->head;
  struct node *prev1 = NULL;
  while (p1 != NULL)
  {
    if (p1->item == item1)
      break;
    prev1 = p1;
    p1 = p1->next;
  }

  struct node *p2 = l->head;
  struct node *prev2 = NULL;
  while (p2 != NULL)
  {
    if (p2->item == item2)
      break;
    prev2 = p2;
    p2 = p2->next;
  }

  if (p1 == NULL || p2 == NULL)
    return;

  if (prev1 != NULL)
    prev1->next = p2;
  else
    l->head = p2;

  if (prev2 != NULL)
    prev2->next = p1;
  else
    l->head = p1;

  struct node *tmp = p1->next;
  p1->next = p2->next;
  p2->next = tmp;
}

void listDelete(struct list *l, int item)
{
  struct node *n = l->head;
  struct node *prev = NULL;

  while (n != NULL)
  {
    if (n->item == item)
    {
      if (prev == NULL)
        l->head = n->next;
      else
        prev->next = n->next;

      if (n->next == NULL)
        l->tail = prev;

      free(n);
      return;
    }

    prev = n;
    n = n->next;
  }
}

void listPrint(struct list *l)
{
  struct node *n = l->head;
  while (n != NULL)
  {
    printf("%d ", n->item);
    n = n->next;
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  struct list l;
  listInit(&l);
  listAppend(&l, 1);
  listAppend(&l, 2);
  listAppend(&l, 3);
  listAppend(&l, 23);
  listAppend(&l, 43);
  listAppend(&l, 53);
  listInsertAfter(&l, 111, 3);
  listSwap(&l, 2, 53);
  listDelete(&l, 1);
  listPrint(&l);

  return 0;
}