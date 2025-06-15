#include <iostream>

#include "./engine/GameOfLifeBuilder.h"
#include "./cli/GameOfLifeCli.h"
#include "./myCustomImplementations/DefaultGameOfLifeCellFactoryMethod.cpp"

int main() {
    printf("Hello World\n");

    GameOfLifeBuilder b;

    b.addCellFactoryMethod("default", std::make_shared<DefaultGameOfLifeCellFactoryMethod>());

    GameOfLifeManager gameOfLifeManager = b.build();
    GameOfLifeCli cli(gameOfLifeManager);

    cli.run();

    return 0;
}