#include <iostream.>
#include"MyRBT.h"
#include"GPtreeRBOS.h"

using namespace std;


int main() {
    setlocale(LC_ALL, "ukrainian");

    RedBlackTree tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Елемент з рангом 5: " << tree.select(5)->value << std::endl; // має вивести 3
    tree.print(tree.root);

    return 0;
}