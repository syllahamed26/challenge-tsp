//
// Created by 239371 on 04/06/2023.
//

#include "random_ameliorate.h"

std::vector<int> recherche(std::vector<int> &solution, std::vector<int> &neighbor, const std::vector<City> &cities) {
    Score score = *new Score();
    std::vector<int> best_solution = solution;
    double best_score = score.evaluate(cities, solution);
    std::vector<int> indices(solution.size());


    for (int i = 0; i < solution.size(); i++) {
        indices[i] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    for(int i = 0; i < indices.size(); i++){
        twoOpt twoopt = *new twoOpt();
        std::vector<int> current_solution = twoopt.solution_from_index(solution, indices[i]);

        double current_score = score.evaluate(cities, current_solution);

        if(current_score < best_score){
            best_solution = current_solution;
            break;
        }
    }

    return best_solution;
}