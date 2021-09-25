#include "make_priorities.h"


std::seed_seq seq2{ (uint64_t) std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(), (uint64_t) __builtin_ia32_rdtsc(), (uint64_t) (uintptr_t) std::make_unique<char>().get() };
std::mt19937 rng2(seq2);

ld logBeauty(int beauty, int max_beauty) {
    return -log(10 - 10 * static_cast<ld>(beauty) / max_beauty);
}

ld logRank(int rank, int max_rank) {
    return -log(10 - 10 * static_cast<ld>(rank) / max_rank);
}

std::unique_ptr<Graph> MakePriorities(std::unique_ptr<Graph> graph) {
    // for (auto& man : graph->persons_by_gender_[Gender::Man]) {
    //     std::vector<int> mas(man->dating_list_.size());
    //     std::iota(mas.begin(), mas.end(), 0); 
    //     std::shuffle(mas.begin(), mas.end(), rng2);
    //     int num = 0;
    //     man->person_by_priority_.resize(man->dating_list_.size());
    //     for (auto woman : man->dating_list_) {
    //         man->priority_by_person_[woman] = mas[num];
    //         man->person_by_priority_[mas[num]] = woman;
    //         ++num;
    //     }
    // }

    for (auto& man : graph->persons_by_gender_[Gender::Man]) {
        std::vector<std::pair<ld, std::shared_ptr<Person>>> priorities;
        for (auto woman : man->dating_list_) {
            priorities.push_back({(logBeauty(woman->beauty_, graph->persons_by_gender_[Gender::Woman].size()) * 0.7 + logRank(woman->rank_, graph->persons_by_gender_[Gender::Woman].size()) * 0.3), woman});
        }
        sort(priorities.begin(), priorities.end());
        for (int i = 0; i < priorities.size(); ++i) {
            man->priority_by_person_[priorities[i].second] = i;
            man->person_by_priority_.push_back(priorities[i].second);
        }
    }



    for (auto& woman : graph->persons_by_gender_[Gender::Woman]) {
        std::vector<std::pair<ld, std::shared_ptr<Person>>> priorities;
        for (auto man : woman->dating_list_) {
            priorities.push_back({(logBeauty(man->beauty_, graph->persons_by_gender_[Gender::Man].size()) * 0.4 + logRank(man->rank_, graph->persons_by_gender_[Gender::Man].size()) * 0.6), man});
        }
        sort(priorities.begin(), priorities.end());
        for (int i = 0; i < priorities.size(); ++i) {
            woman->priority_by_person_[priorities[i].second] = i;
            woman->person_by_priority_.push_back(priorities[i].second);
        }
    }
    return graph;
}