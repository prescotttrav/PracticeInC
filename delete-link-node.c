// Write a function to delete a node in a singly-linked list. You will not be
// given access to the head of the list, instead you will be given access to the
// node to be deleted directly.

struct link_node {
  int val;
  struct link_node *next;
}

static void
delete_node(struct link_node *node) {
  struct link_node *temp = node->next;

  node->val = temp->val;
  node->next = temp->next;
}
