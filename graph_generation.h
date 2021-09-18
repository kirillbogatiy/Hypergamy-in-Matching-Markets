
enum class Gender {
      Man
    , Women
}


struct Person {
    Gender gender_;
    int rank_;

    std::unordered_set<std::shared_ptr<Person>> dating_list_;
    std::vector<std::shared_ptr<Person>> dating_list_by_priority_;
}

struct Graph {
    std::map<Gender, std::vector<std::shared_ptr<Person>>> persons_by_gender_;
};

std::unique_ptr<Graph> GraphGenerating(int n, int k, ld beta, int alpha);
