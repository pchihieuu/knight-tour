#include<iostream>
#include<fstream>
#define MAX 8

using namespace std;
int dong[] = {-1, -2, -2, -1, 1, 2, 2,1 };
int cot[] = {-2, -1, 1 , 2, 2, 1, -1, -2};

int n, stt, demKQ;
int BC[MAX][MAX];
void Try(int x, int y);
int main(){
    cin>>n;
    for(int x =0;x < n;x++){
        for(int y=0; y < n;y++){
            stt =1;
            BC[x][y] = 1;
            Try(x, y);
            BC[x][y] =0;

        }
        cout<<demKQ<<endl;
        return 0;
    }
}
void Try(int x, int y){
        if(stt >= n*n){
            demKQ++;

        }else{
            for(int i =0;i <8 ;++i){
                int x2 = x + dong[i];
                int y2 = y + cot[i];
                if(0 <= x2 && x2 < n && 0 <= y2 && y2 < n && BC[x2][y2] == 0){
                    stt++;
                    BC[x2][y2] = stt;
                    Try(x2, y2);

                    BC[x2][y2] = 0;
                    stt--;

                }
            }
        }
    }
