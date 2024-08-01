#include <map>
#include <string>
#include<iostream>
#include <vector>

using namespace std;

namespace ljankai
{
    class Roadmap
    {
    public:
        map<string, vector<string>> buildGraph(vector<vector<string>>& edges)
        {
            map<string, vector<string>> graph;

            for (auto& edge : edges)
            {
                string src = edge[0];
                string dest = edge[1];

                graph[src].push_back(dest);
                graph[dest].push_back(src);
            }

            return graph;
        }
    };

    int roadmap(int argc, char const* argv[])
    {
        vector<vector<string>> edges = {
            {"Austria", "Czech Republic"},
            {"Austria", "Germany"},
            {"Austria", "Hungary"},
            {"Austria", "Italy"},
            {"Austria", "Slovakia"},
            {"Austria", "Slovenia"},

            {"Belgium", "France"},
            {"Belgium", "Germany"},
            {"Belgium", "Luxembourg"},
            {"Belgium", "Netherlands"},

            {"Bulgaria", "Greece"},
            {"Bulgaria", "Romania"},

            {"Croatia", "Hungary"},
            {"Croatia", "Slovenia"},

            {"Cyprus", "Greece"},

            {"Czech Republic", "Germany"},
            {"Czech Republic", "Poland"},
            {"Czech Republic", "Slovakia"},

            {"Denmark", "Germany"},

            {"Estonia", "Latvia"},

            {"Finland", "Sweden"},

            {"France", "Belgium"},
            {"France", "Germany"},
            {"France", "Italy"},
            {"France", "Luxembourg"},
            {"France", "Spain"},

            {"Germany", "Austria"},
            {"Germany", "Belgium"},
            {"Germany", "Czech Republic"},
            {"Germany", "Denmark"},
            {"Germany", "France"},
            {"Germany", "Luxembourg"},
            {"Germany", "Netherlands"},
            {"Germany", "Poland"},

            {"Greece", "Bulgaria"},
            {"Greece", "Cyprus"},

            {"Hungary", "Austria"},
            {"Hungary", "Croatia"},
            {"Hungary", "Romania"},
            {"Hungary", "Slovakia"},
            {"Hungary", "Slovenia"},


            {"Italy", "Austria"},
            {"Italy", "France"},
            {"Italy", "Slovenia"},

            {"Latvia", "Estonia"},
            {"Latvia", "Lithuania"},

            {"Lithuania", "Latvia"},
            {"Lithuania", "Poland"},
            {"Luxembourg", "Belgium"},
            {"Luxembourg", "France"},
            {"Luxembourg", "Germany"},

            {"Netherlands", "Belgium"},
            {"Netherlands", "Germany"},

            {"Poland", "Czech Republic"},
            {"Poland", "Germany"},
            {"Poland", "Lithuania"},
            {"Poland", "Slovakia"},

            {"Portugal", "Spain"},

            {"Romania", "Bulgaria"},
            {"Romania", "Hungary"},

            {"Slovakia", "Austria"},
            {"Slovakia", "Czech Republic"},
            {"Slovakia", "Hungary"},
            {"Slovakia", "Poland"},

            {"Slovenia", "Austria"},
            {"Slovenia", "Croatia"},
            {"Slovenia", "Hungary"},
            {"Slovenia", "Italy"},

            {"Spain", "France"},
            {"Spain", "Portugal"},

            {"Sweden", "Finland"},

            {"Malta", "Italy"}
        };

        Roadmap roadmap;

        map<string, vector<string>> graph = roadmap.buildGraph(edges);
        for (auto& entry : graph)
        {
            cout << entry.first << " : ";
            for (auto& nbr : entry.second)
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
}//namespace end
