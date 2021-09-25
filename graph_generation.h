#pragma once

#include <bits/stdc++.h>


typedef long double ld;

const int INF = 1000'000'000;

enum class Gender {
      Man
    , Woman
};

struct Person {
public:
    Gender gender_;
    int rank_;
    int beauty_;

    bool fertility_;

    std::weak_ptr<Person> match_;

    std::unordered_set<std::shared_ptr<Person>> dating_list_;
    std::unordered_map<std::shared_ptr<Person>, int> priority_by_person_;
    std::vector<std::weak_ptr<Person>> person_by_priority_;

public:
    Person(Gender gender) 
        : gender_(gender) {}

public:
    std::string ToString() const;
};

struct Graph {
public:
    std::map<Gender, std::vector<std::shared_ptr<Person>>> persons_by_gender_;

public:
    void Print();
};

std::unique_ptr<Graph> NewGraph(int n, int k, ld beta, int alpha, ld woman_fertility_probability);
