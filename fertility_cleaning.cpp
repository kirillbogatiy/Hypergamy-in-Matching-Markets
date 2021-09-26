#include "fertility_cleaning.h"


std::unique_ptr<Graph> FertilityCleaning(std::unique_ptr<Graph> graph) {
    for (auto& woman : graph->persons_by_gender_[Gender::Woman]) {
        if (woman->fertility_) {
            for (auto man : woman->dating_list_) {
                man->dating_list_.erase(woman);
            }
            woman->dating_list_.clear();
        }
    }
    return graph;
}
