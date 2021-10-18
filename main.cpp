#include <iostream>
#include<conio.h>
#include<vector>
#include<cstdlib>
#include <ctime>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix);
void RandomMatrix(int size,vector<vector<int>>& matrix){
    srand(time(NULL));
    int max;
    cout<<"Enter a max matrix element: " << endl;
    cin >> max;
    if (size % 2 == 0){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < (size / 2); j++){
                int dull = rand() % max;
                matrix[i].push_back(dull);
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < (size / 2) + i % 2; j++) {
                int dull = rand() % max;
                matrix[i].push_back(dull);
            }
        }
    }
    printMatrix(matrix);
}
void HandsMatrix(int size,vector<vector<int>>& matrix){
    if (size % 2 == 0){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < (size / 2); j++){
                int save;
                cout << "Enter numbers: " << endl;
                cin >> save;
                matrix[i].push_back(save);
                }
            }
        }
        else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < (size / 2) + i % 2; j++) {
                int save;
                cin >> save;
                matrix[i].push_back(save);
            }
        }
    }
    printMatrix(matrix);
}
void fillingMatrix(int size,vector<vector<int>>& matrix){
    int choise;
    cout << "You want to fill  by hands?(Yes(Enter 1) or No(Enter 0)) :";
    cin >> choise;
    while (choise < 0 || choise > 1){
        cout << "input 0 or 1\n";
        cin >> choise;
    }
    if (choise == 1){
        HandsMatrix(size, matrix);

    }
    if (choise == 0){
        RandomMatrix(size, matrix);
    }
}
int getValue(const vector<vector<int>>& matrix, const int x, const int y){
    if ((x + y) % 2 != 0)
    {
        return 1;
    }
    else
    {
        return matrix[x][y / 2];
    }
}
void SumWithoutZero(int size,vector<vector<int>>& matrix){ //bbbb
    int pos = 0;
    int sum = 0;
    for(int i =0;i<size;i++){
        for(int j =0;j<size;j++){
            if(matrix[i][j]==0){
                pos++;
            }
        }
        if(pos==0){
            for(int t=0;t<size;t++){
                sum=sum + matrix[i][t];
            }
            cout<<"Sum of "<<(i+1)<<" row: "<<sum<<endl;
            sum = 0;
        }
        pos= 0;
    }
}
void DiagMultiply(int size,vector<vector<int>>& matrix){
    int rez = 1;
    int y;
    int sravn = 0;
    for(int b = 1;b < (size-1);b++){
        for(int u = b,y = 0;u < size;u++,y++){
            rez*=matrix[y][u];
        }
        if (rez > sravn){
            swap(rez, sravn);;
        }
    }
    int mult1 = 1;
    int c;
    for(int b = 1;b < (size-1);b++){
        for(int v =0 ,c = b;c < size;c++,v++){
            mult1*=matrix[c][v];
        }
        if (mult1 > sravn){
            swap(mult1, sravn);
        }
    }
    if(sravn>rez){
        cout<<"The max product of the elements of diagonals parallel to the main: "<<sravn;
    }
    else{
        cout<<"The max product of the elements of diagonals parallel to the main: "<<rez;
    }
}
void printMatrix(const vector<vector<int>>& matrix){
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << getValue(matrix, i, j) << " ";
        }
        cout << endl;
    }
}
int main() {
    int size;
    cout << "Enter size of your vector:";
    cin >> size;
    while(size <= 0 || size > 11){
        cout << "Size has to be positive and less than eleven :";
        cin >> size;
    }
    vector< vector <int> >matrix(size,vector <int> (size));
    fillingMatrix(size,matrix);
    SumWithoutZero(size,matrix);
    DiagMultiply(size, matrix);
    return 0;
}