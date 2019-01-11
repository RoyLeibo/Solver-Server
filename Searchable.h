//
// Created by royl8 on 1/10/19.
//

#ifndef FINAL_PROJECT_SECOND_SEARCHABLE_H
#define FINAL_PROJECT_SECOND_SEARCHABLE_H

#include <list>
#include <vector>
#include <map>
#include "State.h"
#include "SearchableUtility.h"

class Searchable {
    State* entry_vertex ;
    State* exit_vertex ;

public:
    virtual State* getInitialState() = 0;
    virtual State* getGoalState() = 0;
    virtual unordered_map<string, State*>* get_vertex_map() = 0 ;
    virtual int get_n() = 0 ;

};


#endif //FINAL_PROJECT_SECOND_SEARCHABLE_H