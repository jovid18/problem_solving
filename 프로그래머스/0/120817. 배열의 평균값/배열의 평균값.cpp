#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(auto e:numbers){
        answer+=e;
    }
    return answer/numbers.size();
}