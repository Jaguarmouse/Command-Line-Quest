#include "BBB.h"

Token *new_token(TokenKind kind, Token *cur, char *str, int len) {
  Token *tok = malloc(sizeof(Token));
  tok->kind = kind;
  tok->str = str;
  tok->len = len;
  cur->next = tok;
  return tok;
}

static bool is_alphabet(char c) {
  return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == '_';
}

static char *starts_with_reserved(char *str) {
  static char *kws[] = {"exit"};

  for (int i = 0; i < sizeof(kws) / sizeof(*kws); i++) {
    int len = strlen(kws[i]);
    if (strncmp(kws[i], str, len) == 0 && !is_alphabet(str[len]))
      return kws[i];
  }

  static char *ops[] = {"x", "X", "y", "Y", "z", "Z"};

  for (int i = 0; i < sizeof(kws) / sizeof(*kws); i++)
    if (strncmp(ops[i], str, strlen(ops[i])) == 0)
      return ops[i];

  return NULL;
}

Token *tokenize(char *str) {
  char *p = str;

  Token head;
  Token *cur = &head;

  while (*p) {
    char *rw = starts_with_reserved(p);
    if (rw) {
      int len = strlen(rw);
      cur = new_token(TK_RESERVED, cur, p, len);
      p += len;
      continue;
    }

    if (isdigit(*p)) {
      char *q = p;
      int val = strtol(p, &p, 10);
      cur = new_token(TK_NUM, cur, q, p-q);
      cur->val = val;
      continue;
    }

    p++;
  }

  cur = new_token(TK_EOF, cur, NULL, 0);

  return head.next;
}
