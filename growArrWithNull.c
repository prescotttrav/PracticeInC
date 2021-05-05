#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum DynamicArr
{
  INIT = 1,
  GROW,
};

struct element {
  char *name;
  int val;
};

struct dynamic_arr {
  void (*add)(struct dynamic_arr *, struct element *);
  void (*remove)(struct dynamic_arr *, char *);
  int n;
  int max;
  struct element **elements;
};

static struct element create_element(char *name, int val) {
  struct element el = {NULL, val};

  el.name = malloc(sizeof(char) * strlen(name) + 1);

  if (!el.name) {
    free(el.name);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  strcpy(el.name, name);

  return el;
}

static void free_dynamic_arr(struct dynamic_arr *arr) {
  for (int i = 0; i < arr->max; i++) {
    if (arr->elements[i] != NULL) {
      free(arr->elements[i]->name);
    }
  }
  free(arr->elements);
  free(arr);
}

static struct element **initialize_new_elements(struct element **el, int start,
                                                int end) {
  for (int i = start; i < end; i++) {
    el[i] = NULL;
  }
  return el;
}

static void insert(struct dynamic_arr *arr, struct element *el) {
  for (int i = 0; i < arr->max; i++) {
    if (arr->elements[i] == NULL) {
      arr->elements[i] = el;
      return;
    }
  }
}

static void add_element(struct dynamic_arr *arr, struct element *el) {
  struct element **temp = NULL;

  if (arr->elements == NULL) {
    temp = malloc(sizeof(struct element *) * INIT);

    if (!temp) {
      free(temp);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    temp = initialize_new_elements(temp, 0, INIT);

    arr->max = INIT;
    arr->elements = temp;
  } else if (arr->n >= arr->max) {
    temp = realloc(arr->elements, sizeof(struct element *) * (arr->max * GROW));

    if (!temp) {
      free(temp);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    temp = initialize_new_elements(temp, arr->max, arr->max * GROW);

    arr->max *= GROW;
    arr->elements = temp;
  }
  insert(arr, el);
  arr->n++;
}

static void remove_element(struct dynamic_arr *arr, char *name) {
  for (int i = 0; i < arr->max; i++) {
    if (arr->elements[i] && strcmp(name, arr->elements[i]->name) == 0) {
      free(arr->elements[i]->name);
      arr->elements[i] = NULL;
      arr->n--;
      return;
    }
  }
}

static struct dynamic_arr *init_dynamic_arr(void) {
  struct dynamic_arr *arr = NULL;

  arr = malloc(sizeof(struct dynamic_arr));

  if (!arr) {
    free(arr);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  arr->n = 0;
  arr->max = 0;
  arr->elements = NULL;
  arr->add = add_element;
  arr->remove = remove_element;

  return arr;
}

int main(void) {
  struct element a, b, c, d;
  struct dynamic_arr *arr = init_dynamic_arr();

  a = create_element("name_one", 1);
  arr->add(arr, &a);

  b = create_element("name_two", 2);
  arr->add(arr, &b);

  arr->remove(arr, "name_one");
  arr->remove(arr, "name_two");

  c = create_element("name_three", 3);
  arr->add(arr, &c);

  d = create_element("name_four", 4);
  arr->add(arr, &d);

  arr->remove(arr, "name_four");

  free_dynamic_arr(arr);
  return 0;
}
