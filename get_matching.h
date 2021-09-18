
struct Matching {
    std::vector<std::pair<std::shared_ptr<Person>, std::shared_ptr<Person>>> pairs_;
}

std::unique_ptr<Matching> GaleShapleyByGender(std::unique_ptr<Graph> graph, Gender gender);

