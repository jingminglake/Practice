#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<string> split(const string &str, char delim) {
    istringstream iss(str);
    vector<string> tokens;
    string token;
    while (getline(iss, token, delim)) {
        tokens.push_back(move(token));
    }
    return tokens;
}

vector<string> getSentence(string& fileName) {
    fstream fin(fileName);
    vector<string> res;
    string line;
    while (getline(fin, line)) {
        if (line.find("@JsonProperty") == string::npos)
            continue;
        res.emplace_back(line.substr(line.find_first_of('"') + 1, line.find_last_of('"') - line.find_first_of('"') - 1));
    }
    return res;
}

unordered_map<string, vector<string> > getSentenceToWords(vector<string>& sentenceList1, vector<string>& sentenceList2) {
    unordered_map<string, vector<string> > sentenceToWords;
    for (string& sen1 : sentenceList1) {
        if (!sentenceToWords.count(sen1)) {
            sentenceToWords[sen1] = split(sen1, '_');
        }
    }
    for (string& sen2 : sentenceList2) {
        if (!sentenceToWords.count(sen2)) {
            sentenceToWords[sen2] = split(sen2, '_');
        }
    }
    return sentenceToWords;
}

bool isSimSentence(vector<string>& words1, vector<string>& words2) {
    for (string& word1 : words1) {
        for (string& word2 : words2) {
            if (word1.find(word2) != string::npos || word2.find(word1) != string::npos)
                return true;
        }
    }
    return false;
}

vector<string> genResult(vector<string>& sentenceList1, vector<string>& sentenceList2, string& prefix1, string& prefix2) {
    unordered_map<string, vector<string> > sentenceToWords = getSentenceToWords(sentenceList1, sentenceList2);
    vector<string> res;
    string line;
    unordered_set<string> matched;
    for (string& sen1 : sentenceList1) {
        line = prefix1 + sen1 + "->";
        for (string& sen2 : sentenceList2) {
            if (isSimSentence(sentenceToWords[sen1], sentenceToWords[sen2])) {
                line += prefix2 + sen2 + ";";
                matched.insert(sen2);
            }
        }
        res.push_back(line);
    }
    // unmatched
    vector<string> unmatched;
    for (string& sen2 : sentenceList2) {
        if (!matched.count(sen2)) {
            res.push_back("->" + prefix2 + sen2);
        }
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc < 5)
        return 0;
    string fileName1 = argv[1];
    string prefix1 = argv[2];
    string fileName2 = argv[3];
    string prefix2 = argv[4];
    //cout << "argc: " << argc << endl;
    //for (int i = 0; i < argc; i++)
    //  cout << "argv[" << i << "]: " << argv[i] << endl;
    vector<string> sentenceList1 = getSentence(fileName1);
    vector<string> sentenceList2 = getSentence(fileName2);
    vector<string> res = genResult(sentenceList1, sentenceList2, prefix1, prefix2);
    ofstream out("res.txt");
    for (string ss : res)
        out << ss << endl;
    out.close();
    return 0;
}
