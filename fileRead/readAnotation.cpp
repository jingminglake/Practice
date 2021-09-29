#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 3)
        return 0;
    string fileName = argv[1];
    string prefix = argv[2];
    //cout << "argc: " << argc << endl;
    //for (int i = 0; i < argc; i++)
    //  cout << "argv[" << i << "]: " << argv[i] << endl;
    fstream fin(fileName);
    ofstream out("res.txt");
    vector<string> res;
    string line;
    while (getline(fin, line)) {
        if (line.find("@JsonProperty") == string::npos)
            continue;
        string property = prefix + line.substr(line.find_first_of('"') + 1, line.find_last_of('"') - line.find_first_of('"') - 1);
        out << property << endl;
    }

    out.close();
    return 0;
}
