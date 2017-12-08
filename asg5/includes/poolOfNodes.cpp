#include "node.h"
#include "poolOfNodes.h"

PoolOfNodes& PoolOfNodes::getInstance() {
  static PoolOfNodes pool;
  return pool;
}

void PoolOfNodes::drainThePool() {
  //int i = 1;
  for ( const Node* node : nodePool ) {
    //std::cout<< nodePool.size() << " " << node << std::endl;
    //std::cout<< nodePool.size() << " " << i++ << " " << node->name() << " " << node << std::endl;
    delete node;
  }
}

