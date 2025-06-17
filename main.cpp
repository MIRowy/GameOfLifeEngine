#include <iostream>

#include "./engine/GameOfLifeBuilder.h"
#include "./cli/GameOfLifeCli.h"
#include "./myCustomImplementations/DefaultGameOfLifeCellFactoryMethod.cpp"
#include "./myCustomImplementations/VonNeumannNeighbourhood.cpp"

int main() {
    printf("Hello World\n");

    GameOfLifeBuilder b;

    b.addCellFactoryMethod("default", std::make_shared<DefaultGameOfLifeCellFactoryMethod>());
    b.addNeighbourhood("vonNeumann", std::make_shared<VonNeumannNeighbourhood>());

    GameOfLifeManager gameOfLifeManager = b.build();
    GameOfLifeCli cli(gameOfLifeManager);

    cli.run();

    return 0;
}