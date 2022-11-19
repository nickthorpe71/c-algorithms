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
  listDelete(&l, 1);
  listPrint(&l);

  return 0;
}