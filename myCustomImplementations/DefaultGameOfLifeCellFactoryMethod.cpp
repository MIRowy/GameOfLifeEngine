#include "BaseCellFactoryMethod.h"
#include "DefaultGameOfLifeCell.cpp"

class DefaultGameOfLifeCellFactoryMethod final : public BaseCellFactoryMethod {
public:
    std::shared_ptr<BaseCell> create(Point p) override {
        return std::make_shared<DefaultGameOfLifeCell>(p);
    }
};