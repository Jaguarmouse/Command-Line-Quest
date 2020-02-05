#include "BBB.h"

int px;
int py;
int pz;

int W = 100;
int H = 100;
int D = 100;

int main(int argc, char *argv[]) {
  srand((unsigned int)time(NULL));
  px = rand() % (W + 1);
  py = rand() % (H + 1);
  pz = rand() % (D + 1);

  bool ending = false;
  char str[101];
  Token *token;
  Node *node;

  printf("type \"exit\" to exit!\n");
  printf("%d/%d %d/%d %d/%d\n", px, W, py, H, pz, D);

  while (!ending) {
    printf("> ");
    if (scanf("%100[^\n]%*[^\n]", str) < 1) *str = '\0';
    getchar();

    token = tokenize(str);
    node = parse(token);
    if ((ending = !exec(node)))
      printf("Bye!\n");
    else
      printf("%d/%d %d/%d %d/%d\n", px, W, py, H, pz, D);
  }

  return 0;
}
