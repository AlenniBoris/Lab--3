#include <iostream>
#include<iomanip>
#include<conio.h>
#include<vector>
#include<cstdlib>
#include <ctime>

using namespace std;




void RandomMatrix(int size,vector<vector<int>>& matrix){
    srand(time(NULL));
    int max;
    cout<<"Enter a max matrix element: " << endl;
    cin >> max;
    for(int i = 0; i < size; i++){
        cout<<"|";
        for(int j = 0; j < size; j++){
            matrix[i][j]=rand() % max;
            if((i+j)%2!=0)
            {
                matrix[i][j]=1;
            }
            cout << setw(6) << matrix[i][j] << "    ";
        }
        cout<<"|";
        cout<<endl;
    }
}
void HandsMatrix(int size,vector<vector<int>>& matrix){
    int q=1;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if((i+j)%2!=0)
            {
                matrix[i][j]=1;
                q++;
            }
            else{
                cout<< "\nEnter matrix elements: "<< endl;
                cin>>matrix[i][j];
            }
        }
    }
    for(int k = 0;k < size;k++){
            cout<<"|";
            for(int h = 0;h < size;h++)
            {
                cout<<setw(6)<<matrix[k][h]<<"  ";
            }
           cout<<"|"<<endl;
        }
}
void SumWithoutZero(int size,vector<vector<int>>& matrix){
        int pos = 0;
        int sum = 0;
        for(int i =0;i<size;i++)
        {
            for(int j =0;j<size;j++)
            {
                if(matrix[i][j]==0)
                {
                    pos++;
                }
            }
            if(pos==0)
            {
                for(int t=0;t<size;t++)
                {
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
        for(int u = b,y = 0;u < size;u++,y++)
        {
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
            swap(mult1, sravn);;
        }
    }

    if(sravn>rez){
        cout<<"The max product of the elements of diagonals parallel to the main: "<<sravn;
    }
    else{
        cout<<"The max product of the elements of diagonals parallel to the main: "<<rez;
    }

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