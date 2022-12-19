#include<bits/stdc++.h>
#include<sys/stat.h>
#include"../construct2.cpp"
using namespace std;

int main() {
    int n, d1=4, d2;
    string cr;

    cout<<"nを入力してください>>"; cin>>n;
    cout<<"d2を入力してください>>"; cin>>d2;

    vector<Graph> ts = construct(n, d1, d2);

    string file_name;
    string directory_name;
    ofstream writing_file;

    cr = "CR("+to_string(n)+", "+to_string(d1)+", "+to_string(d2)+")";
    directory_name = "./"+cr;

    mkdir(directory_name.c_str(), 0755);

    for(int t=0; t<6; t++) {
        file_name = directory_name+"/t"+to_string(t)+".tex";
        
        writing_file.open(file_name);

        writing_file
        << "\\begin{tikzpicture}\n"
        << "\t"
        << "\\tikzset{enclosed/.style={draw, circle, inner sep=0pt, minimum size=0.2cm, fill=black}}\n"
        << endl;

        for(int i=0; i<n; i++) {
            writing_file
            << "\t"
            << "\\node[enclosed, label={above, xshift="
            << round(0.35*sin(2*M_PI*i/n)*100)/100*1.3
            << "cm, yshift="
            << round((-0.31+0.35*cos(2*M_PI*i/n))*100)/100*1.3
            << "cm:"<<i<<"}] at ("
            << round((2.6+2*sin(2*M_PI*i/n))*100)/100*1.3
            << ", "
            << round((2+2*cos(2*M_PI*i/n))*100)/100*1.3
            << ")"
            << "("<<i<<"){};"
            << endl;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(ts[t].mat[i][j]) {
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

    file_name = directory_name+"/graphs.tex";
    
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
        << "{\\scriptsize \\input{materials/"<<cr<<"/t"<<i<<".tex}}&"
        << "{\\scriptsize \\input{materials/"<<cr<<"/t"<<i+3<<".tex}}\\\\"
        << endl;
    }

    writing_file
    << "\t\\end{tabular}\n"
    << "\t\\caption{$"<<cr<<"$の6つの独立全域木}\n"
    << "\t\\label{fig:CR("<<n<<", "<<d1<<", "<<d2<<")}\n"
    << "\\end{figure}"
    << endl;

    writing_file.close();

    return 0;
}
