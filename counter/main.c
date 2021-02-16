#include <stdio.h>
#include <stdlib.h>

#define COUNTER_FIELDS             \
  void (*reset)(struct counter *); \
  int (*next)(struct counter *);   \
  void (*destroy)(struct counter *);

struct counter {
  COUNTER_FIELDS
};

typedef struct counter *Counter;

static void noop(Counter c) {
  ;
}
static int return_zero(Counter c) {
  return 0;
}
static struct counter Zero_counter = {noop, return_zero, noop};

Counter make_zero_counter() {
  return &Zero_counter;
}

struct ifs_counter {
  COUNTER_FIELDS
  int init;
  int cur;
  int (*f)(int);
};

static void ifs_reset(Counter c) {
  struct ifs_counter *ic;

  ic = (struct ifs_counter *) c;

  ic->cur = ic->init;
}

static int ifs_next(Counter c) {
  struct ifs_counter *ic;
  int ret;

  ic = (struct ifs_counter *) c;

  ret = ic->cur;
  ic->cur = ic->f(ic->cur);

  return ret;
}

Counter make_ifs_counter(int init, int (*f)(int)) {
  struct ifs_counter *ic;
  ic = malloc(sizeof(*ic));

  ic->reset = ifs_reset;
  ic->next = ifs_next;
  ic->destroy = (void (*)(struct counter *)) free;

  ic->init = init;
  ic->cur = init;
  ic->f = f;

  return (Counter) ic;
}

static int times2(int x) {
  return x * 2;
}

void print_powers_of_2() {
  int i;
  Counter c;

  c = make_ifs_counter(1, times2);

  for (i = 0; i < 10; ++i) {
    printf("%d\n", c->next(c));
  }

  c->reset(c);

  for (i = 0; i < 20; ++i) {
    printf("%d\n", c->next(c));
  }

  c->destroy(c);
}

int main() {
  print_powers_of_2();

  return 0;
}
