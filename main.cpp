#include <iostream>

//void print(int** matrix, int size){
//    for(int j = 0; j < size; j++){
//        for(int i = 0; i < size; i++){
//            std::cout << matrix[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//}

bool drawConnect(int** matrix, int size, int from, bool * acyclicity){
    for(int i = 0; i < size; i++){
        if(matrix[from][i] == 1){
            if(acyclicity[i]) return true;

            acyclicity[i] = true;
            matrix[from][i] = 2;
            if(drawConnect(matrix, size, i, acyclicity)) return true;
        }
    }
    return false;
}
//Наша функція
bool isAcyclic(int** matrix, int size){
    for(int i = 0; i < size; i++){
        bool * arr = new bool[size];
        arr[i] = true;

        bool res = drawConnect(matrix, size, i, arr);

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(matrix[i][j] == 2) {
                    matrix[i][j] = 1;
                }
            }
        }

        if(res) return true;
    }
    return false;
}

//int main(){
//    const int SIZE = 4;
//
//    int** matrix = new int* [SIZE];
//
//    for(int i = 0; i < SIZE; i++){
//        matrix[i] = new int [SIZE];
//        for(int j = 0; j < SIZE; j++) matrix[i][j] = 0;
//    }
//
//    matrix[1][2] = 1;
//    matrix[0][3] = 1;
//    matrix[2][0] = 1;
//    matrix[2][3] = 1;
//    matrix[3][1] = 1;
//    matrix[3][2] = 1;
//
//    print(matrix, SIZE);
//
//    std::cout << isAcyclic(matrix, SIZE);
//}
