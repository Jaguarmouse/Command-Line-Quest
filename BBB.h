#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef enum {
  X,
  Y,
  Z
} Direction;

extern int px;
extern int py;
extern int pz;

extern int W;
extern int H;
extern int D;

// 
// util.c
//

int min(int a, int b);
int max(int a, int b);
bool is_capital(char c);

//
// tokenize.c
//

typedef enum {
  TK_NONE,
  TK_NUM,
  TK_RESERVED,
  TK_EOF
} TokenKind;

typedef struct Token Token;

struct Token {
  Token *next;
  TokenKind kind;
  char *str;
  int len;
  int val;
};

Token *tokenize(char *str);

//
// parse.c
//

typedef enum {
  ND_ROOT,
  ND_ACTION,
  ND_MOV,
  ND_COUNT
} NodeKind;

typedef struct Node Node;

struct Node {
  NodeKind kind;
  Node *action;
  Node *counter;
  Direction dir;
  int sign;
  int count;
};


Node *parse(Token *token);

//
// exec.c
//

bool exec(Node *node);

