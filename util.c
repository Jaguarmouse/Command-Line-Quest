#include "BBB.h"

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

bool is_capital(char c) {
  return 'A' <= c && c <= 'Z';
}
