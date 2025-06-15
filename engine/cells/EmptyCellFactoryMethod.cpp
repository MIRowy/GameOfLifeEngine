#include "BaseCellFactoryMethod.h"
#include "EmptyCell.cpp"

class EmptyCellFactoryMethod final : public BaseCellFactoryMethod {
public:
    std::shared_ptr<BaseCell> create(Point p) override {
        return std::make_shared<EmptyCell>(p);
    }
};