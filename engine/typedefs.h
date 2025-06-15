#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>
#include <memory>

#include "../utils/Point.h"

// Forwarding.
class BaseCell;
class BaseNeighbourhood;
class BaseGameCycleBehaviour;
class BaseCellFactoryMethod;

using Board = std::vector<std::vector<std::shared_ptr<BaseCell>>>;

#endif