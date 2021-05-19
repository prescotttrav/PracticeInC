#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct linked_list {
  int size;
  struct node *head;

  void (*add)(struct linked_list *, int);
  struct node *(*remove)(struct linked_list *, int);
  struct node *(*find)(struct linked_list *, int);
  void (*print)(struct linked_list);
};

static struct node *new_node(int val) {
  struct node *n = NULL;

  n = malloc(sizeof(struct node));

  if (!n) {
    free(n);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  n->val = val;
  n->next = NULL;

  return n;
}

static void add_node(struct linked_list *list, int val) {
  struct node *n = new_node(val);
  n->next = list->head;
  list->head = n;
  list->size++;
}

static struct node *remove_node(struct linked_list *list, int val) {
  struct node *prev = NULL;
  struct node *cur = list->head;

  while (cur != NULL && cur->val != val) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL)
    return NULL;

  prev->next = cur->next;
  list->size--;

  return cur;
}

static struct node *find_node(struct linked_list *list, int val) {
  struct node *n = list->head;

  while (n != NULL && n->val != val) {
    n = n->next;
  }

  return n;
}

static void print_list(struct linked_list list) {
  struct node *n = list.head;

  while (n) {
    printf("%d\t", n->val);
    n = n->next;
  }
  putchar('\n');
}

static struct linked_list initialize_list() {
  struct linked_list list;
  list.size = 0;
  list.head = NULL;

  list.add = add_node;
  list.remove = remove_node;
  list.find = find_node;
  list.print = print_list;

  return list;
}

int main(void) {
  struct linked_list list = initialize_list();

  list.add(&list, 5);
  list.add(&list, 4);
  list.add(&list, 3);
  list.add(&list, 2);
  list.add(&list, 1);

  list.find(&list, 4);
  list.find(&list, 1);

  list.remove(&list, 2);
  list.remove(&list, 4);

  list.print(list);

  return 0;
}
