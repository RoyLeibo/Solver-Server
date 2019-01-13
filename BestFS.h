//
// Created by einat on 1/12/19.
//

#ifndef FINAL_PROJECT_SECOND_BESTFS_H
#define FINAL_PROJECT_SECOND_BESTFS_H

#include "Searcher.h"
#include <vector>
#include "State.h"
#include "SearchableUtility.h"
class BestFS : Searcher {
    private:
        static vector<State*>::iterator find_lowest_cost(vector<State*>* vec, map<string,double>* cost_to_vertex_map) ;
        static map<string, double> build_f_map(unordered_map<string, State *> *vertex_map);
        bool find_in_vec(vector<State*> *vec,State* is_find);
public:
    virtual string search(Searchable* searchable);
    string searchtwo(Searchable* searchable);
};


#endif //FINAL_PROJECT_SECOND_BESTFS_H