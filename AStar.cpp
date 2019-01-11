//
// Created by royl8 on 1/10/19.
//

#include "AStar.h"

string AStar::search(Searchable* searchable) {
    unordered_map<string, State*>* vertex_map = searchable->get_vertex_map() ;
    map<string, int> distance_map = build_distance_map(vertex_map) ;
    map<string, int> g_map = build_g_map(vertex_map) ;
    map<string, int> f_map = build_g_map(vertex_map) ;
    map<string, vector<State*>> adjacent_map = SearchableUtility::build_adjacent_map(vertex_map, searchable->get_n()) ;

    State* current_vertex ;
    State* temp_adj ;
    State* goal_vertex = searchable->getGoalState() ;
    State* start_vertex = searchable->getInitialState() ;

    vector<State*> open_vec ;
    vector<State*> close_vec ;
    vector<State*> current_adjancents ;
    open_vec.push_back(start_vertex) ;

    g_map[start_vertex->get_vertex_index()] = 0 ;
    f_map[start_vertex->get_vertex_index()] = start_vertex->find_manhattan_distance(goal_vertex) ;

    vector<State*>::iterator low_cost_it ;
    vector<State*>::iterator begin_it ;

    string adj_index ;
    int adj_distance_value ;
    int adj_g_value ;

    while(open_vec.empty() == false) {
        low_cost_it  = find_lowest_cost(&open_vec, &f_map) ;
        current_vertex = *low_cost_it ;
        if(current_vertex != goal_vertex) {
            open_vec.erase(low_cost_it) ;
            close_vec.push_back(current_vertex);
            current_adjancents = adjacent_map.at(current_vertex->get_vertex_index()) ;
            distance_calc(current_vertex, current_adjancents, &distance_map) ;
            for(int i = 0 ; i < current_adjancents.size() ; i++) {
                begin_it = open_vec.begin() ;
                temp_adj = current_adjancents[i] ;
                adj_index = temp_adj->get_vertex_index() ;
                adj_distance_value = distance_map[adj_index] +  ;
                adj_g_value = g_map[adj_index] ;
                if (!find_in_vec(&close_vec, temp_adj)) {
                    if ((find_in_vec(&open_vec, temp_adj)) && (adj_distance_value < adj_g_value)) {
                        open_vec.erase(begin_it + find_in_vec(&open_vec, temp_adj));
                    } else if ((find_in_vec(&close_vec, temp_adj)) && (adj_distance_value < adj_g_value)) {
                        close_vec.erase(begin_it + find_in_vec(&close_vec, temp_adj));
                    } else if ((!find_in_vec(&open_vec, temp_adj)) && (!find_in_vec(&close_vec, temp_adj))) {
                        open_vec.push_back(temp_adj);
                        g_map[adj_index] = adj_distance_value ;
                        f_map[adj_index] = adj_distance_value + temp_adj->find_manhattan_distance(goal_vertex) ;
                    }
                }
                else {
                    continue;
                }


//                if (!find_in_vec(&close_vec, temp_adj)) {
//                    f_map[adj_index] = g_map[adj_index] + temp_adj->find_manhattan_distance(goal_vertex) ;
//                    if (!find_in_vec(&open_vec, temp_adj)) {
//                        open_vec.push_back(temp_adj) ;
//                    }
//                    else {
//
//                    }
            }
        }
        else {
            return restore_solution(searchable);
        }
    }
}

map<string, int> AStar::build_distance_map(unordered_map<string, State*>* vertex_map) {
    map<string, int> cost_distance_map ;
    unordered_map<string, State*>::iterator it ;
    for(it = vertex_map->begin() ; it != vertex_map->end() ; ++it) {
        cost_distance_map.insert(pair<string, int>(it->first, 0)) ;
    }
    return cost_distance_map ;
}

map<string, int> AStar::build_g_map(unordered_map<string, State*>* vertex_map) {
    int init_cost = numeric_limits<int>::max() ;
    map<string, int> g_map ;
    unordered_map<string, State*>::iterator it ;
    for(it = vertex_map->begin() ; it != vertex_map->end() ; ++it) {
        g_map.insert(pair<string,int>(it->first, init_cost)) ;
    }
    return g_map ;
}

void AStar::distance_calc(State* current, vector<State*> adj_vec, map<string, int>* cost_distance_map) {
    string adj_index ;
    int next_vertex_cost ;
    State* temp_adj ;
    for(int i = 0 ; i < adj_vec.size() ; i++) {
        temp_adj = adj_vec[i] ;
        adj_index = temp_adj->get_vertex_index();
        next_vertex_cost = cost_distance_map->at(current->get_vertex_index()) + temp_adj->get_cost() ;
        (*cost_distance_map)[adj_index] = next_vertex_cost;
    }
}

string AStar::restore_solution(Searchable* searchable) {
    State* current = searchable->getGoalState() ;
    vector<string> directions ;
    string answer = "{ " ;
    while(current != searchable->getInitialState()) {
        directions.push_back(check_direction(current)) ;
        current = current->get_father() ;
    }
    for(int i = directions.size()-1 ; i >= 0 ; i--) {
        answer += directions.at(i) + ", " ;
    }
    answer.erase(answer.length()-2, 2) ;
    answer += " }" ;
    return answer ;
}

string AStar::check_direction(State* current) {
    int current_i = current->get_i() ;
    int current_j = current->get_j() ;
    int father_i = current->get_father()->get_i() ;
    int father_j = current->get_father()->get_j() ;

    if (current_j == father_j) {
        if (current_i > father_i) {
            return "DOWN" ;
        }
        else {
            return "UP" ;
        }
    }
    else if (current_i == father_i) {
        if (current_j > father_j) {
            return "RIGHT" ;
        }
        else {
            return "LEFT" ;
        }
    }
}

int AStar::find_in_vec(vector<State*>* vec, State* current) {
    string current_index = current->get_vertex_index() ;
    string temp_index ;
    for (int i = 0 ; i < vec->size() ; i++) {
        temp_index = (*vec)[i]->get_vertex_index() ;
        if (current_index == temp_index) {
            return i ;
        }
    }
    return -1 ;
}

vector<State*>::iterator AStar::find_lowest_cost(vector<State*>* vec, map<string,int>* cost_to_vertex_map) {
    int min_cost = numeric_limits<int>::max() ;
    vector<State*>::iterator it ;
    vector<State*>::iterator min_cost_it ;
    int temp_cost ;
    for (it = vec->begin() ; it != vec->end(); it++) {
        temp_cost = (*cost_to_vertex_map)[(*it)->get_vertex_index()] ;
        if (temp_cost < min_cost) {
            min_cost = temp_cost ;
            min_cost_it = it ;
        }
    }
    return min_cost_it ;
}

int AStar::getNumberOfNodesEvaluated() {}