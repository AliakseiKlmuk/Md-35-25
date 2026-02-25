
#include <iostream>
#include "Tree.h"
#include "Forest.h"
#include <cassert>

int main()
{
    Forest forest1;
    Forest forest2;

    forest1.growUp(Tree("pine", "coniferuosu"));
    forest1.growUp(Tree("pine", "coniferuosu"));
    forest1.growUp(Tree("fir", "coniferuosu"));
    forest1.growUp(Tree("fir", "coniferuosu"));
    forest1.growUp(Tree("fir", "coniferuosu"));

    std::cout << std::endl;

    forest2.growUp(Tree("birch", "deciduous"));
    forest2.growUp(Tree("aspen", "deciduous"));
    forest2.growUp(Tree("alder", "deciduous"));
    forest2.growUp(Tree("oak", "deciduous"));
    forest2.growUp(Tree("ash", "deciduous"));
    forest2.growUp(Tree("maple", "deciduous"));

    forest1.displayAll();
    std::cout << "Forest_1: " << forest1.getTreesNumber() << std::endl;
    std::cout << std::endl;

    forest2.displayAll();
    std::cout << "Forest_2: " << forest2.getTreesNumber() << std::endl;
    std::cout << std::endl;

    forest2.changeID(0,21);
   // assert(forest1.getTree(0).getID() == 42);

    forest2.displayAll();
    std::cout << std::endl;

    Forest combinedForest = forest1 + forest2;
    std::cout << "CombinedForest: \t" << combinedForest.getTreesNumber() << std::endl;
    combinedForest.displayAll();
    std::cout << std::endl;

    combinedForest.cutAll();
    combinedForest.displayAll();
    std::cout << std::endl;

}
