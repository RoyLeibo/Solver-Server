//
// Created by royl8 on 1/9/19.
//

#include "Matrix.h"

Matrix::Matrix(vector<string> matrix_vec) {
    build_matrix(matrix_vec) ;
}

void Matrix::build_matrix(vector<string> matrix_vec) {
    int vec_size = matrix_vec.size()- 2 ;
    vector<string> line_vec ;
    for(int i = 0 ; i < vec_size ; i++) {
        line_vec = line_parse(matrix_vec.at(i)) ;
        update_map(line_vec, i) ;
    }
    line_vec = line_parse(matrix_vec.at(vec_size)) ;
    entry_vertex = pair<int, int>(stoi(line_vec.at(0)), stoi(line_vec.at(1))) ;
    line_vec = line_parse(matrix_vec.at(++vec_size)) ;
    exit_vertex = pair<int, int>(stoi(line_vec.at(0)), stoi(line_vec.at(1))) ;
}

vector<string> Matrix::line_parse(string line) {
    int start_of_num = 0 ;
    int end_of_num ;
    vector<string> line_vec ;
    if(line_vec[line.length()] != ",") {
        line += "'" ;
    }
    int line_length = line.length() ;
    while (true) {
        end_of_num = line.find(',', start_of_num) ;
        if (end_of_num < line_length) {
            line_vec.push_back(line.substr(start_of_num, end_of_num - start_of_num)) ;
            start_of_num = end_of_num + 1 ;
        }
        else {
            return line_vec ;
        }
    }
}

void Matrix::update_map(vector<string> line_vec, int i) {
    int vec_length = line_vec.size() ;
    State* temp_state ;
    pair<int, int> vertex_index ;
    for (int j = 0 ; j < vec_length ; j++) {
        vertex_index = pair<int, int>(i, j) ;
        temp_state = new State(vertex_index, stoi(line_vec.at(i))) ;
        vertex_map.insert(pair<pair<int, int>, State*>(vertex_index, temp_state)) ;
    }
}

pair<int, int> Matrix::get_entry_vertex() {
    return this->entry_vertex ;
}

pair<int, int> Matrix::get_exit_vertex() {
    return this->exit_vertex ;
}