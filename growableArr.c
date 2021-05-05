#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nameval {
  char *name;
  int val;
};

struct nv_tab {
  int n;
  int max;
  struct nameval *name_val;
};

enum nv
{
  INIT = 1,
  GROW,
};

struct nameval create_nameval(char *name, int val) {
  struct nameval new_name = {NULL, val};

  new_name.name = malloc(sizeof(char) * (strlen(name) + 1));

  if (!new_name.name) {
    free(new_name.name);
    fprintf(stderr, "Allocation memory failed.\n");
    exit(-1);
  }

  strcpy(new_name.name, name);

  return new_name;
}

struct nv_tab add_name(struct nv_tab nv, struct nameval new_name) {
  struct nameval *temp = NULL;

  if (nv.name_val == NULL) {
    nv.name_val = malloc(sizeof(struct nameval) * INIT);

    if (!nv.name_val) {
      free(nv.name_val);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    nv.n = 0;
    nv.max = INIT;
  } else if (nv.n >= nv.max) {
    temp = realloc(nv.name_val, sizeof(struct nameval) * nv.max * GROW);

    if (!temp) {
      free(temp);
      fprintf(stderr, "Allocation memory failed.\n");
      exit(-1);
    }

    nv.max *= GROW;
    nv.name_val = temp;
  }

  nv.name_val[nv.n] = new_name;
  nv.n++;

  return nv;
}

int main(void) {
  struct nameval a, b, c, d, e;
  struct nv_tab tab = {0, 0, NULL};

  a = create_nameval("hello", 5);
  tab = add_name(tab, a);

  b = create_nameval("goodbye", 7);
  tab = add_name(tab, b);

  c = create_nameval("singapore", 9);
  tab = add_name(tab, c);

  d = create_nameval("gui", 3);
  tab = add_name(tab, d);

  e = create_nameval("adios", 5);
  tab = add_name(tab, e);

  return 0;
}
