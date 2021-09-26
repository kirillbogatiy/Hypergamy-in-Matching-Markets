#pragma once

#include <bits/stdc++.h>
#include "graph_generation.h"


typedef long double ld;


ld logBeauty(int beauty, int max_beauty);
ld logRank(int rank, int max_rank);

std::unique_ptr<Graph> MakePriorities(std::unique_ptr<Graph> graph);
