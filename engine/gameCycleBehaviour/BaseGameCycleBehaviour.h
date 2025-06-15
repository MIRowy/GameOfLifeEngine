#ifndef BASEGAMECYCLEBEHAVIOUR_H
#define BASEGAMECYCLEBEHAVIOUR_H

#include <memory>

#include "../typedefs.h"

class BaseGameCycleBehaviour {
public:
    virtual ~BaseGameCycleBehaviour() = default;

    virtual void performCycle(const Board &board, std::shared_ptr<BaseNeighbourhood> neighbourhood) = 0;
};

#endif