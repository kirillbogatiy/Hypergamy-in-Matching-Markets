#pragma once

#include <bits/stdc++.h>
#include "graph_generation.h"


struct Matching {
public:
    std::vector<std::pair<std::weak_ptr<Person>, std::weak_ptr<Person>>> pairs_;

public:
    std::string ToString() const;
    std::string ToBasicString() const;
};

std::pair<std::unique_ptr<Graph>, std::unique_ptr<Matching>> GaleShapleyByGender(std::unique_ptr<Graph> graph, Gender gender);

