#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>

struct node {
  char *key;
  int val;
  struct node *next;
};

static void free_all(struct node *list) {
  struct node *next;

  while (list) {
    next = list->next;
    free(list);
    list = next;
  }
}

static void assert_list(struct node *actual, char *expected[]) {
  for (int i = 0; actual != NULL; i++) {
    assert(strcmp(actual->key, expected[i]) == 0);
    actual = actual->next;
  }
}

static struct node *new_node(char *key, int val) {
  struct node *n = NULL;

  n = malloc(sizeof(struct node));

  if (!n) {
    free(n);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  n->key = key;
  n->val = val;
  n->next = NULL;

  return n;
}

static struct node *add_front(struct node *list, struct node *new) {
  new->next = list;

  return new;
}

static struct node *add_end(struct node *list, struct node *new) {
  struct node *last = list;

  if (!last) {
    return new;
  }

  while (last->next) {
    last = last->next;
  }
  last->next = new;

  return list;
}

static struct node *del_item(struct node *list, char *key) {
  struct node *p, *prev;

  prev = NULL;
  p = list;

  while (p) {
    if (strcmp(p->key, key) == 0) {
      if (prev == NULL)
        list = p->next;
      else
        prev->next = p->next;
      free(p);
      return list;
    }
    prev = p;
    p = p->next;
  }
  return NULL;
}

static struct node *lookup(struct node *list, char *key) {
  while (list) {
    if (strcmp(list->key, key) == 0) {
      return list;
    }
    list = list->next;
  }
  return NULL;
}

static void apply(struct node *list, void (*fn)(struct node *, void *),
                  void *arg) {
  while (list) {
    (*fn)(list, arg);
    list = list->next;
  }
}

static void print_fn(struct node *p, void *fmt) {
  printf((char *) fmt, p->key, p->val);
}

static void print_list(struct node *list) {
  apply(list, print_fn, "%s: %d\n");
}

static void count_fn(struct node *p, void *arg) {
  int *c;
  c = (int *) arg;

  (*c)++;
}

static int count(struct node *list) {
  int n = 0;

  apply(list, count_fn, &n);

  return n;
}

int main(void) {
  struct node *list = NULL;

  assert(list == NULL);

  list = add_front(list, new_node("second", 1));

  assert_list(list, (char *[]){"second"});
  assert(list->next == NULL);

  list = add_front(list, new_node("first", 2));

  assert_list(list, (char *[]){"first", "second"});
  assert(list->next != NULL);

  list = add_end(list, new_node("third", 3));

  assert_list(list, (char *[]){"first", "second", "third"});

  struct node *find = lookup(list, "second");
  assert(find->val == list->next->val);

  find = lookup(list, "no exist");
  assert(find == NULL);

  print_list(list);

  assert(count(list) == 3);

  list = del_item(list, "third");
  assert_list(list, (char *[]){"first", "second"});

  list = del_item(list, "first");
  assert_list(list, (char *[]){"second"});

  free_all(list);
  return 0;
}
