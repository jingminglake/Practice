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
        string::size_type pos = line.find(" set");
        if (pos == string::npos) continue;
        //pos = line.find_first_of(" set");
        int start = pos + 1;
        int length = line.find_first_of('(', start) - start;
        cout << "start: " << start << " length: " << length << endl;
        string property = prefix + line.substr(start, length) + "();";
        out << property << endl;
    }

    out.close();
    return 0;
}
