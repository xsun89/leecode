#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int maxVote(int* vec, int ncandidates, int* ret)
{
    int max = vec[0];
    int i, n=0;
    for(i=1; i<ncandidates; i++){
        if(max < vec[i]) {
            max = vec[i];
            n = i;
        }
    }
    *ret = max;
    return n;
}

int voting(int ncandidates, map<int, string>& choices){
    map<int, string>::iterator it = choices.begin();
    int vote[ncandidates];
    int totalNum = 0;
    while(1) {
        while (it != choices.end()) {
            totalNum++;
            vote[it->second[0]-'0']++;
        }
        int ret;
        int n = maxVote(vote, ncandidates, &ret);
        if(ret / totalNum >= 0.5) {
            return n;
        }else{

        }

    }
}
int main (int ac, char *av[])
{
    string line;
    int cases = 0, ncandidates = 0;
    vector<string> candidate;
    map<int, string> choices;
    cin >> cases;
    int current = 0;
    while(current < cases)
    {
        cin >> ncandidates;
        if(ncandidates <= 0){
            current++;
            continue;
        }
        cin.ignore();

        candidate.clear();
        candidate.resize(ncandidates);
        for(int i=0; i<ncandidates;i++){
            getline(cin, line);
            candidate.push_back(line);
        }
        int voteNum = 0;
        choices.clear();
        while((getline(cin, line), line.length()>0)){
            choices[voteNum++] = line;
        }
        voting(ncandidates, candidate, choices);
        current++;
    }
    return 0;
}