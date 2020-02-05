#include "BBB.h"

bool move(Direction dir, int c) {
  switch (dir) {
    case X:
      px = max(0, min(px + c, W));
      return true;
    case Y:
      py = max(0, min(py + c, H));
      return true;
    case Z:
      pz = max(0, min(pz + c, D));
      return true;
  }
  return false;
}

bool exec_action(Node *node) {
  switch (node->kind) {
    case ND_ACTION:
      switch (node->action->kind) {
        case ND_MOV:
          return move(node->action->dir, node->counter->count * node->sign);
        default:
          return true;
      }
    case TK_RESERVED:
      return false;
    default:
      return true;
  }
}

bool exec(Node *node) {
  if (!exec_action(node)) return false;
  return true;
}
