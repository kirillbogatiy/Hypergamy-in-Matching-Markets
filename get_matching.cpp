#include "get_matching.h"

std::pair<std::unique_ptr<Graph>, std::unique_ptr<Matching>> GaleShapleyByGender(std::unique_ptr<Graph> graph, Gender gender) {
    auto matching = std::make_unique<Matching>();
    


    std::unordered_map<std::shared_ptr<Person>, int> last_proposal; 
    bool ok = true;
    for (int step = 0; ok; ++step) {
        ok = false;
        for (auto person : graph->persons_by_gender_[gender]) {
            if (last_proposal[person] >= person->dating_list_.size() || (person->match_.lock()->gender_ != gender && person->person_by_priority_[last_proposal[person]].lock()->rank_ == person->match_.lock()->rank_)) {
                if (last_proposal[person] >= person->dating_list_.size()) {
                    person->match_ = person;
                }
                continue;
            }
            ok = true;
            auto match = person->person_by_priority_[last_proposal[person]].lock();
            //std::cerr << person->rank_ << " " << match->rank_ << " " << (match->match_.lock()->gender_ == Gender::Man ? "" : "FUCK") << match->match_.lock()->rank_ << "\n";
            if (match->match_.lock()->gender_ == match->gender_) {
                match->match_ = person;
                person->match_ = match;
                //std::cerr << "case1\n"; 
            } else if (match->priority_by_person_[match->match_.lock()] > match->priority_by_person_[person]) {
                ++last_proposal[match->match_.lock()];
                match->match_ = person;
                person->match_ = match;
                //std::cerr << "case2\n";
            } else {
                ++last_proposal[person];
                //std::cerr << "case3\n";
            }
        }
    }

    for (auto man : graph->persons_by_gender_[Gender::Man]) {
        matching->pairs_.push_back({man, man->match_});
    }


    for (auto woman : graph->persons_by_gender_[Gender::Woman]) {
        matching->pairs_.push_back({woman, woman->match_});
    }

    return make_pair(std::move(graph), std::move(matching));
}

std::string Matching::ToString() const {
    std::stringstream output;
    for (auto [first_person, second_person] : pairs_) {
        output << "pair:\n";
        output << (first_person.lock()->gender_ == Gender::Man ? "m" : "w") << first_person.lock()->rank_ << " "; 
        output << (second_person.lock()->gender_ == Gender::Man ? "m" : "w") << second_person.lock()->rank_ << "\n";
    }
    return output.str();
}

std::string Matching::ToBasicString() const {
    std::stringstream output;
    for (auto [first_person, second_person] : pairs_) {
        output << (first_person.lock()->gender_ == Gender::Man ? "m" : "w") << first_person.lock()->rank_ << " "; 
        output << (second_person.lock()->gender_ == Gender::Man ? "m" : "w") << second_person.lock()->rank_ << "\n";
    }
    return output.str();
}
