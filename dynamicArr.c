#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

struct arr {
  _Bool (*add)(struct arr *, int, int);
  _Bool (*delete)(struct arr *, int);
  _Bool (*delete_val)(struct arr *, int);
  int (*find_val)(struct arr *, int val);
  void (*print)(struct arr *);
  int size;
  int *items;
};

static void free_dynamic_arr(struct arr a) {
  free(a.items);
}

static _Bool is_invalid_index(int i) {
  return i < 0;
}

static _Bool add_arr(struct arr *a, int i, int val) {
  int *temp = NULL;

  if (a->size < i || is_invalid_index(i))
    return 0;

  a->size++;
  temp = a->items;

  a->items = malloc(sizeof(int) * a->size);

  for (int j = 0; j < a->size; j++) {
    if (j < i)
      a->items[j] = temp[j];
    else if (j > i)
      a->items[j] = temp[j - 1];
    else
      a->items[j] = val;
  }

  free(temp);

  return 1;
}

static int find_val_arr(struct arr *a, int val) {
  for (int i = 0; i < a->size; i++) {
    if (a->items[i] == val)
      return i;
  }
  return -1;
}

static void print_arr(struct arr *a) {
  for (int i = 0; i < a->size; i++) {
    printf("%d\t", a->items[i]);
  }
  putchar('\n');
}

static _Bool delete_arr(struct arr *a, int i) {
  int *temp = NULL;

  if (a->size < i || is_invalid_index(i))
    return 0;

  temp = a->items;

  a->items = malloc(sizeof(int) * a->size - 1);

  for (int j = 0; j < a->size; j++) {
    if (j < i) {
      a->items[j] = temp[j];
    } else if (j > i) {
      a->items[j - 1] = temp[j];
    } else {
      continue;
    }
  }

  a->size--;
  free(temp);

  return 1;
}

static _Bool delete_val_arr(struct arr *a, int val) {
  int i = find_val_arr(a, val);
  return delete_arr(a, i);
}

static struct arr init_arr(void) {
  struct arr a;
  a.add = add_arr;
  a.delete = delete_arr;
  a.delete_val = delete_val_arr;
  a.find_val = find_val_arr;
  a.print = print_arr;
  a.size = 0;
  a.items = NULL;

  return a;
}

int main(void) {
  struct arr a = init_arr();

  a.add(&a, 0, 2);
  a.print(&a);

  a.add(&a, 0, 1);
  a.print(&a);

  a.add(&a, 2, 3);
  a.print(&a);

  assert(a.find_val(&a, 1) == 0);
  assert(a.find_val(&a, 2) == 1);
  assert(a.find_val(&a, 3) == 2);
  assert(a.find_val(&a, 4) == -1);

  a.delete(&a, 1);
  a.print(&a);

  a.delete_val(&a, 3);
  a.print(&a);

  free_dynamic_arr(a);

  return 0;
}
