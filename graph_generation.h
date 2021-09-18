
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
    std::vector<std::shared_ptr<Person>> men_;
    std::vector<std::shared_ptr<Person>> women_;
};

std::unique_ptr<Graph> GraphGenerating(int n, int k, ld beta, int alpha);
