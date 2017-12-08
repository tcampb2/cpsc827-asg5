#include <vector>
#include "node.h"
class Node;

class PoolOfNodes {
public:
  static PoolOfNodes& getInstance();
  void add(const Node* node) { /*std::cout<< nodePool.size() << " " << node->name() << " " << node << std::endl;*/ nodePool.push_back(node); }
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  PoolOfNodes() : nodePool() {}
};
