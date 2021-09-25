#include "graph_generation.h"

std::seed_seq seq{ (uint64_t) std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(), (uint64_t) __builtin_ia32_rdtsc(), (uint64_t) (uintptr_t) std::make_unique<char>().get() };
std::mt19937 rng(seq);

std::unique_ptr<Graph> NewGraph(int n, int k, ld beta, int alpha, ld woman_fertility_probability) {
    auto graph = std::make_unique<Graph>();
    
    graph->persons_by_gender_[Gender::Man] = std::vector<std::shared_ptr<Person>>(n);
    
    for (auto& man : graph->persons_by_gender_[Gender::Man]) {
        man = std::make_shared<Person>(Gender::Man);
        man->match_ = man;
    }
    

    graph->persons_by_gender_[Gender::Woman] = std::vector<std::shared_ptr<Person>>(n, std::make_shared<Person>(Gender::Woman));

    for (auto& woman : graph->persons_by_gender_[Gender::Woman]) {
        woman = std::make_shared<Person>(Gender::Woman);
        woman->match_ = woman;
        if (rng() % INF <= static_cast<int>(woman_fertility_probability * INF)) {
            woman->fertility_ = true;
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i + j < n) {
                graph->persons_by_gender_[Gender::Man][i]->dating_list_.insert(graph->persons_by_gender_[Gender::Woman][(i + j) % n]);
                graph->persons_by_gender_[Gender::Woman][(i + j) % n]->dating_list_.insert(graph->persons_by_gender_[Gender::Man][i]);
            }
            if (i - j >= 0) {
                graph->persons_by_gender_[Gender::Man][i]->dating_list_.insert(graph->persons_by_gender_[Gender::Woman][(i - j + n) % n]);
                graph->persons_by_gender_[Gender::Woman][(i - j + n) % n]->dating_list_.insert(graph->persons_by_gender_[Gender::Man][i]);    
            }
            // if (i + j + 1 < n) {
            //     graph->persons_by_gender_[Gender::Woman][i]->dating_list_.insert(graph->persons_by_gender_[Gender::Man][(i + j + 1) % n]);
            //     graph->persons_by_gender_[Gender::Man][(i + j + 1) % n]->dating_list_.insert(graph->persons_by_gender_[Gender::Woman][i]);
            // }
        }
    }

    for (int num = 0; num < alpha; ++num) {
        for (int i = 0; i < n; ++i) {
            const auto man = graph->persons_by_gender_[Gender::Man][i];
            const auto mans_list = man->dating_list_; 
            for (auto woman : mans_list) {
                if (rng() % INF < static_cast<int>(beta * static_cast<ld>(INF))) {
                    man->dating_list_.erase(woman);
                    woman->dating_list_.erase(man);
                    int num = rng() % n;
                    man->dating_list_.insert(graph->persons_by_gender_[Gender::Woman][num]);
                    graph->persons_by_gender_[Gender::Woman][num]->dating_list_.insert(man);
                }
            }
        }
    }

    for (int num = 0; num < alpha; ++num) {
        for (int i = 0; i < n; ++i) {
            const auto woman = graph->persons_by_gender_[Gender::Woman][i];
            const auto womans_list = woman->dating_list_; 
            for (auto man : womans_list) {
                if (rng() % INF < static_cast<int>(beta * static_cast<ld>(INF))) {
                    woman->dating_list_.erase(man);
                    man->dating_list_.erase(woman);
                    int num = rng() % n;
                    woman->dating_list_.insert(graph->persons_by_gender_[Gender::Man][num]);
                    graph->persons_by_gender_[Gender::Man][num]->dating_list_.insert(woman);
                }
            }
        }
    }

    std::vector<int> mans_ranks(n);
    std::iota(mans_ranks.begin(), mans_ranks.end(), 0);
    std::shuffle(mans_ranks.begin(), mans_ranks.end(), rng);
    for (auto& man : graph->persons_by_gender_[Gender::Man]) {
        man->rank_ = mans_ranks.back();
        mans_ranks.pop_back();
    }

    std::vector<int> womans_ranks(n);
    std::iota(womans_ranks.begin(), womans_ranks.end(), 0);
    std::shuffle(womans_ranks.begin(), womans_ranks.end(), rng);
    for (auto& woman : graph->persons_by_gender_[Gender::Woman]) {
        woman->rank_ = womans_ranks.back();
        womans_ranks.pop_back();
    }

    std::vector<int> mans_beauty(n);
    std::iota(mans_beauty.begin(), mans_beauty.end(), 0);
    std::shuffle(mans_beauty.begin(), mans_beauty.end(), rng);
    for (auto& man : graph->persons_by_gender_[Gender::Man]) {
        man->beauty_ = mans_beauty.back();
        mans_beauty.pop_back();
    }

    std::vector<int> womans_beauty(n);
    std::iota(womans_beauty.begin(), womans_beauty.end(), 0);
    std::shuffle(womans_beauty.begin(), womans_beauty.end(), rng);
    for (auto& woman : graph->persons_by_gender_[Gender::Woman]) {
        woman->beauty_ = womans_beauty.back();
        womans_beauty.pop_back();
    }


    return graph;
}

void Graph::Print() {
    std::cerr << "Begin to output men\n";
    for (auto man : persons_by_gender_[Gender::Man]) {
        std::cerr << man->ToString() << "\n\n";
    }

    std::cerr << "Begin to output women\n";
    for (auto woman : persons_by_gender_[Gender::Woman]) {
        std::cerr << woman->ToString() << "\n\n";
    }
}


std::string Person::ToString() const {
    std::stringstream output;
    if (gender_ == Gender::Man) {
        output << "Man\n";
    } else {
        output << "Woman\n";
    }

    output << "Rank: " << rank_ << "\n";
    output << "Beauty: " << beauty_ << "\n";
    output << "Fertility: " << fertility_ << "\n";

    output << "Dating List without order\n";
    for (auto person : dating_list_) {
        if (person->gender_ == Gender::Man) {
            output << "Man";
        } else {
            output << "Woman";
        }
        output << " with rank " << person->rank_ << "\n";
    }


    output << "Dating List with order\n";
    for (int i = 0; i < person_by_priority_.size(); ++i) {
        auto person = person_by_priority_[i].lock();
        output << "Priority: " << i << "\n";
        if (person->gender_ == Gender::Man) {
            output << "Man";
        } else {
            output << "Woman";
        }
        output << " with rank " << person->rank_ << "\n";
    }

    /*
    output << "Dating List with order\n";
    for (auto [person, i] : priority_by_person_) {
        output << "Priority: " << i << "\n";
        if (person->gender_ == Gender::Man) {
            output << "Man";
        } else {
            output << "Woman";
        }
        output << " with rank " << person->rank_ << "\n";
    }
    */

    return output.str();
}