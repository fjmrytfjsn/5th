#include<bits/stdc++.h>
#include<sys/stat.h>
#include"construct.cpp"
using namespace std;

int main() {
    int n=20, d1=4, d2=6;

    vector<Graph> ts = construct(n, d1, d2);

    string file_name;
    ofstream writing_file;
    int t=0;

    file_name = "a.tex";
    
    writing_file.open(file_name);

    writing_file
    << "\\begin{tikzpicture}\n"
    << "\t"
    << "\\tikzset{enclosed/.style={draw, circle, inner sep=0pt, minimum size=0.3cm, fill=black}}\n"
    << endl;

    for(int i=0; i<n; i++) {
        writing_file
        << "\t"
        << "\\node[enclosed, label={above, xshift="
        << round(0.35*sin(2*M_PI*i/n)*100)/100*1.5
        << "cm, yshift="
        << round((-0.31+0.35*cos(2*M_PI*i/n))*100)/100*1.5
        << "cm:"
        << i
        << "}] at ("
        << round((2.6+2*sin(2*M_PI*i/n))*100)/100*1.5
        << ", "
        << round((2+2*cos(2*M_PI*i/n))*100)/100*1.5
        << ")"
        << "("
        << i
        << "){};"
        << endl;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(ts[t].mat[i][j]) {
                writing_file
                << "\t"
                << "\\draw [thick] ("
                << i
                << ")--("
                << j
                << ");"
                << endl;
            }
        }
    }
    writing_file
    << "\\end{tikzpicture}\n"
    << endl;

    writing_file.close();

    return 0;
}