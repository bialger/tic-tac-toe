#include <iostream>
using namespace std;
bool getGameState(int arr[3][3]){
    for (int i=0; i<3; ++i){
        if ((arr[i][0]==arr[i][1]==arr[i][2])&&(arr[i][0]!=-1)){return true;}
        if ((arr[0][i]==arr[1][i]==arr[2][i])&&(arr[0][i]!=-1)){return true;}
    }
    if (((arr[0][0]==arr[1][1]==arr[2][2])&&(arr[0][0]!=-1)) || ((arr[0][2]==arr[1][1]==arr[2][0])&&(arr[0][2]!=-1))){
        return true;
    }
    return false;
}
int main(){
    // to do: enumerete
    int arr[3][3];
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
            cin >> arr[i][j];
        }
    }
    cout << getGameState(arr);
}

