#ifndef BASECELLFACTORYMETHOD_H
#define BASECELLFACTORYMETHOD_H

#include <memory>

#include "../typedefs.h"

class BaseCellFactoryMethod {
public:
    virtual ~BaseCellFactoryMethod() = default;

    virtual std::shared_ptr<BaseCell> create(Point p) = 0;
};

#endif
