#include "BBB.h"

Token *cur = NULL;

Node *new_node(NodeKind kind) {
  Node *node = malloc(sizeof(Node));
  node->kind = kind;
  return node;
}

Node *new_node_mov(Direction d) {
  Node *node = new_node(ND_MOV);
  node->dir = d;
  return node;
}

Node *new_node_counter(int n) {
  Node *node = new_node(ND_COUNT);
  node->count = n;
  return node;
}

char *consume_action() {
  if (cur->kind != TK_RESERVED) return NULL;
  Token *tok = cur;
  cur = cur->next;
  return tok->str;
}

int consume_counter() {
  if (cur->kind != TK_NUM) return 0;
  Token *tok = cur;
  cur = cur->next;
  return tok->val;
}

Node *parse(Token *token) {
  cur = token;
  Node *n = new_node(ND_ACTION);

  char *as;
  int count;

  if ((as = consume_action())) {
    Direction d;
    switch (*as) {
      case 'x':
      case 'X':
        d = X; break;
      case 'y':
      case 'Y':
        d = Y; break;
      case 'z':
      case 'Z':
        d = Z; break;
    }
    n->action = new_node_mov(d);
    n->sign = is_capital(*as) ? -1 : 1;

    if ((count = consume_counter()) == 0)
      count = 1;

    n->counter = new_node_counter(count);
  }

  return n;
}

