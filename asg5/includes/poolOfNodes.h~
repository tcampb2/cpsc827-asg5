#include <vector>
#include "node.h"
class Node;

class PoolOfNodes {
public:
  static PoolOfNodes& getInstance();
  void add(const Node* node) { nodePool.push_back(node); }
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  PoolOfNodes() : nodePool() {}
};
