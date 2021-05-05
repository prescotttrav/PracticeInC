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

void free_dynamic_arr(struct nv_tab tab) {
  for (int i = 0; i < tab.n; i++) {
    free(tab.name_val[i].name);
  }
  free(tab.name_val);
}

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

struct nv_tab del_name(struct nv_tab nv, char *name) {
  for (int i = 0; i < nv.n; i++) {
    if (strcmp(name, nv.name_val[i].name) == 0) {
      free(nv.name_val[i].name);
      memmove(nv.name_val + i, nv.name_val + i + 1,
              (nv.n - (i + 1)) * sizeof(struct nameval));
      nv.n--;
      break;
    }
  }
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

  tab = del_name(tab, "hello");
  tab = del_name(tab, "nothing");
  tab = del_name(tab, "singapore");

  d = create_nameval("gui", 3);
  tab = add_name(tab, d);

  e = create_nameval("adios", 5);
  tab = add_name(tab, e);

  free_dynamic_arr(tab);
  return 0;
}
