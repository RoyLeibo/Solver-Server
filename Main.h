
#ifndef FINAL_PROJECT_SECOND_MAIN_H
#define FINAL_PROJECT_SECOND_MAIN_H

namespace boot {

    class Main {
    public:
        void main(int port) {
//            Solver<Searchable*, string> *solver = new SearcherSolver();
//            server_side::Server *A = new MyParallelServer;
//            ClientHandler *B = new MyClientHandler(solver);
//            A->open(port, B);
//            delete (solver);
//            delete (A);
//            delete (B);
//
            vector<string> matrix_vec ;
            matrix_vec.push_back("15,1,15,1,1,1,15") ;
            matrix_vec.push_back("15,1,15,1,15,1,15") ;
            matrix_vec.push_back("15,1,15,1,15,1,15") ;
            matrix_vec.push_back("15,1,15,15,15,1,15") ;
            matrix_vec.push_back("1,1,1,1,1,1,15") ;
            matrix_vec.push_back("1,15,15,15,15,15,15") ;
            matrix_vec.push_back("1,1,1,1,1,1,1") ;
            matrix_vec.push_back("2,3") ;
            matrix_vec.push_back("6,6") ;
            Searchable* mat = new Matrix(matrix_vec) ;
            Searcher* bfs = new AStar() ;
            cout << bfs->search(mat) << endl ;
        }

    };

}


#endif //FINAL_PROJECT_SECOND_MAIN_H
