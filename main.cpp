#include <bits/stdc++.h>

#include "graph_generation.h"
#include "make_priorities.h"
#include "get_matching.h"
#include "fertility_cleaning.h"


int main() {
    auto graph = NewGraph(10000, 50, 0.2, 5, 0.2);
    graph = FertilityCleaning(std::move(graph));
    graph = MakePriorities(std::move(graph));
    //graph->Print();
    auto pr = GaleShapleyByGender(std::move(graph), Gender::Man);
    graph = std::move(pr.first);
    auto matching = std::move(pr.second);
    //std::cout << matching->ToString();
    std::ofstream file("../matching.txt");

    file << matching->ToBasicString();
}