/* 여행경로
 * 2019.12.28
 */
#include <string>
#include <vector>

using namespace std;

vector<string> result;
bool visited[10000];

void DFS(vector<vector<string>> tickets, vector<string> routes) {

    if (routes.size() == tickets.size()+1) {
        if (result.size() == 0) {
            // 초기 경로 저장
            for (auto r: routes) {
                result.push_back(r);
            }
        } else {
            for (int i = 0; i < result.size(); i++) {
                // 경로가 다른경우 사전적 비교
                if (result[i].compare(routes[i]) != 0) {
                    /* 저장된 경로가 새로운 경로보다 사전적으로 
                     * 뒤에있는 경우 새로운 경로 저장
                     */
                    if (result[i].compare(routes[i]) > 0) {
                        result.clear();
                        for (auto r: routes) {
                            result.push_back(r);
                        }
                    }
                    break;
                }
            }
        }
        return;
    }

    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && routes[routes.size()-1].compare(tickets[i][0]) == 0) {
            visited[i] = true;
            routes.push_back(tickets[i][1]);
            DFS(tickets, routes);
            routes.pop_back();
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {

    vector<string> routes;
    routes.push_back("ICN");
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0].compare("ICN") == 0) {
            visited[i] = true;
            routes.push_back(tickets[i][1]);
            DFS(tickets, routes);
            routes.pop_back();
            visited[i] = false;
        }
    }
    return result;
}