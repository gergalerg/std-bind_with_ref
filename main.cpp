#include <iostream>
#include <vector>

enum State {empty, nought, cross };

int main(int argc, char const *argv[])
{
    std::vector<State> pos;
    pos.push_back(cross);
    pos.push_back(nought);
    pos.push_back(empty);

    for (auto x: pos) std::cout << (int)x << "\n";
    return 0;
}