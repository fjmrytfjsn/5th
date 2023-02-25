#include <fstream>
#include <iostream>
#include <math.h>
#include <sys/stat.h>
#include "construct.cpp"
using namespace std;

void draw(string file_name, int n, vector<vector<int>> mat, double scale) {
    ofstream writing_file;
    writing_file.open(file_name);

    writing_file
    << "\\begin{tikzpicture}[scale="<<scale<<"]\n"
    << "\t"
    << "\\tikzset{enclosed/.style={draw, circle, inner sep=0pt, minimum size="<<0.2*(1+scale)/2<<"cm, fill=black}}\n"
    << endl;

    double ratio=1.3*(1+scale)/2;

    for(int i=0; i<n; i++) {
        writing_file
        << "\t"
        << "\\node[enclosed, label={above, xshift="
        << round(0.35*sin(2*M_PI*i/n)*100)/100*ratio
        << "cm, yshift="
        << round((-0.31+0.35*cos(2*M_PI*i/n))*100)/100*ratio
        << "cm:"<<i<<"}] at ("
        << round((2.6+2*sin(2*M_PI*i/n))*100)/100*ratio
        << ", "
        << round((2+2*cos(2*M_PI*i/n))*100)/100*ratio
        << ")"
        << "("<<i<<"){};"
        << endl;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(mat[i][j]) {
                writing_file
                << "\t\\draw [thick] ("<<i<<")--("<<j<<");"
                << endl;
            }
        }
    }
    writing_file
    << "\\end{tikzpicture}\n"
    << endl;

    writing_file.close();
}

void make_figure(string file_name, string cr, double scale) {
    ofstream writing_file;
    writing_file.open(file_name);

    writing_file
    << "\\begin{figure}[H]\n"
    << "\t\\centering\n"
    << "\t\\begin{tabular}{cc}\n"
    << "\t\t\\centering"
    << endl;
    
    for(int i=0; i<3; i++) {
        writing_file
        << "\t\t"
        << "{\\scriptsize \\input{materials/"<<cr<<"-"<<to_string(scale)<<"/t"<<i<<".tex}}&"
        << "{\\scriptsize \\input{materials/"<<cr<<"-"<<to_string(scale)<<"/t"<<i+3<<".tex}}\\\\"
        << endl;
    }

    writing_file
    << "\t\\end{tabular}\n"
    << "\t\\caption{$"<<cr<<"$の6つの独立全域木}\n"
    << "\t\\label{fig:"<<cr<<"}\n"
    << "\\end{figure}"
    << endl;

    writing_file.close();
}

int main() {
    int n, d1, d2;
    string cr;

    cout<<"nを入力してください>>"; cin>>n;
    cout<<"d1を入力してください>>"; cin>>d1;
    cout<<"d2を入力してください>>"; cin>>d2;
    cr = "CR("+to_string(n)+", "+to_string(d1)+", "+to_string(d2)+")";

    double scale;
    cout<<"scaleを入力してください>>"; cin>>scale;

    vector<Graph> ts = construct(n, d1, d2);

    string file_name;
    string directory_name;

    directory_name = "./draw/N="+to_string(n)+"/";
    mkdir(directory_name.c_str(), 0755);

    directory_name += cr+"-"+to_string(scale)+"/";
    mkdir(directory_name.c_str(), 0755);

    // 頂点のみ
    vector<vector<int>> temp(n, vector<int>(n, 0));
    file_name = directory_name+"vertex_map.tex";
    draw(file_name, n, temp, scale);

    // コーダルリング
    temp.assign(n, vector<int>(n, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((n+j-i)%n==1 or (n+j-i)%n==d1 or (n+j-i)%n==d2)
                temp[i][j] = 1;
        }
    }
    file_name = directory_name+"base.tex";
    draw(file_name, n, temp, scale);
    
    // t0~t5
    for(int t=0; t<6; t++) {
        file_name = directory_name+"t"+to_string(t)+".tex";
        draw(file_name, n, ts[t].mat, scale);
    }

    file_name = directory_name+"graphs.tex";
    make_figure(file_name, cr, scale);
    
    return 0;
}
