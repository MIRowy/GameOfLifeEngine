#ifndef BASENEIGHBOURHOOD_H
#define BASENEIGHBOURHOOD_H

#include <memory>

#include "../typedefs.h"

class BaseNeighbourhood {
public:
    virtual ~BaseNeighbourhood() = default;

    virtual std::vector<std::shared_ptr<BaseCell>> getNeighbours(const Board &board, Point position) = 0;
};

#endif