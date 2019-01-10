//
// Created by royl8 on 1/9/19.
//

#include "State.h"

State::State(string vertex_index, double cost) {
    this->father = NULL ;
    this->vertex_index = vertex_index ;
    this->cost = cost ;
}

State* State::get_father() {
    return this->father ;
}

string State::get_vertex_index() {
    return this->vertex_index ;
}

double State::get_cost() {
    return this ->cost ;
}

void State::set_father(State* father) {
    this->father = father ;
}

void State::set_vertex(string vertex) {
    this->vertex_index = vertex ;
}

void State::set_cost(double cost) {
    this->cost = cost ;
}

int State::get_i() {
    string index = this->get_vertex_index() ;
    return stoi(index.substr(0, index.find(',', 0))) ;
}

int State::get_j() {
    string index_vertex = this->get_vertex_index() ;
    int index_of_comma = index_vertex.find(',', 0) ;
    return stoi(index_vertex.substr(index_of_comma+1, index_vertex.length()-index_of_comma-1)) ;
}

int State::find_manhattan_distance(State* other) {
    int current_i = this->get_i() ;
    int current_j = this->get_j() ;
    int other_i = other->get_i() ;
    int other_j = other->get_j() ;
    int distance = abs(current_i-other_i) + abs(current_j-other_j) ;
    return distance ;
}