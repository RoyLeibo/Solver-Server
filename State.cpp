//
// Created by royl8 on 1/9/19.
//

#include "State.h"

State::State(pair<int, int> vertex_index, int cost) {
    this->father = NULL ;
    this->vertex_index = vertex_index ;
    this->cost = cost ;
}

State* State::get_father() {
    return this->father ;
}

pair<int, int> State::get_vertex() {
    return this->vertex_index ;
}

int State::get_cost() {
    return this ->cost ;
}

void State::set_father(State* father) {
    this->father = father ;
}

void State::set_vertex(pair<int, int> vertex) {
    this->vertex_index = vertex ;
}

void State::set_cost(int cost) {
    this->cost = cost ;
}