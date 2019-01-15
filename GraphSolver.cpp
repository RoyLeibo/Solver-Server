//
// Created by einat on 1/14/19.
//

#include "GraphSolver.h"
#include "AStar.h"

using namespace std ;

GraphSolver::GraphSolver()
{
    this->fileCacheManager = new FileCacheManager("graph_solution.csv");
    this->searcher = new AStar();

}

string GraphSolver::solve(std::vector<std::string> problem)
{
    string problem_string;
    string solution_string;
    string answer ;

    for(int i = 0 ; i < problem.size() ; i++)
    {
       problem_string +=  problem.at(i) + ",";
    }
    bool there_is_solution;
    there_is_solution = this->fileCacheManager->find_solution(problem_string) ;
    if(there_is_solution)
    {
        return this->fileCacheManager->get_solution(problem_string);
    }
    else
    {
        this->searchable = new Matrix(problem);
        if(this->searchable->get_n() > -1) { // if matrix is legal

            // activates the shortest path solver for matrix
            answer = this->searcher->search(this->searchable) ;

            // adds the new solution into the solutions map and file
            solution_string = this->searcher->search(this->searchable);
            this->fileCacheManager->add_solution_map(problem_string,solution_string);
            this->fileCacheManager->add_solution_vec(pair<string,string>(problem_string,solution_string));
            return solution_string;
        }
        else {
            answer = "Matrix Is Illigal!" ;
            return answer ;
        }

    }
}