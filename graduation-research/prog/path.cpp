#include <fstream>
#include <iostream>
#include <math.h>
#include <sys/stat.h>
#include "construct.cpp"
#include "cr_check.cpp"
using namespace std;

int main() {
    int n, d1, d2;
    string cr;

    cout<<"nを入力してください>>"; cin>>n;
    cout<<"d1を入力してください>>"; cin>>d1;
    cout<<"d2を入力してください>>"; cin>>d2;
    cr = "CR("+to_string(n)+", "+to_string(d1)+", "+to_string(d2)+")";

    vector<Graph> ts = construct(n, d1, d2);
    vector<vector<vector<int>>> path_set(6, vector<vector<int>>(n, vector<int>(0)));
    for(int i=0; i<6; i++) path_set[i] = find_path(n, ts[i].G);

    string file_name;
    string directory_name;
    ofstream writing_file;

    directory_name = "./path/";
    mkdir(directory_name.c_str(), 0755);

    file_name = directory_name+cr+".txt";
    writing_file.open(file_name);

    writing_file
    << cr
    << "\n"
    << endl;
    for(int dest=0; dest<n; dest++) {
        writing_file<<"dest: "<<dest<<endl;
        for(int t=0; t<6; t++) {
            for(auto ver: path_set[t][dest]) {
                writing_file
                << ver
                << " ";
            }
            writing_file
            <<endl;
        }
        writing_file
        <<endl;
    }
    writing_file.close();

    return 0;
}
