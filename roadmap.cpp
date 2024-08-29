// #include <map>
// #include <string>
// #include<iostream>
// #include <vector>

// using namespace std;

// namespace ljankai
// {
//     class Roadmap
//     {
//     public:
//         map<string, vector<string>> buildGraph(vector<vector<string>>& edges)
//         {
//             map<string, vector<string>> graph;

//             for (auto& edge : edges)
//             {
//                 string src = edge[0];
//                 string dest = edge[1];

//                 graph[src].push_back(dest);
//                 graph[dest].push_back(src);
//             }

//             return graph;
//         }
//     };

//     int roadmap(int argc, char const* argv[])
//     {
//         vector<vector<string>> edges = {
//             {"Austria", "Czech Republic"},
//             {"Austria", "Germany"},
//             {"Austria", "Hungary"},
//             {"Austria", "Italy"},
//             {"Austria", "Slovakia"},
//             {"Austria", "Slovenia"},

//             {"Belgium", "France"},
//             {"Belgium", "Germany"},
//             {"Belgium", "Luxembourg"},
//             {"Belgium", "Netherlands"},

//             {"Bulgaria", "Greece"},
//             {"Bulgaria", "Romania"},

//             {"Croatia", "Hungary"},
//             {"Croatia", "Slovenia"},

//             {"Czech Republic", "Poland"},
//             {"Czech Republic", "Slovakia"},

//             {"Denmark", "Germany"},

//             {"Estonia", "Latvia"},

//             {"Finland", "Sweden"},

//             {"France", "Germany"},
//             {"France", "Italy"},
//             {"France", "Luxembourg"},
//             {"France", "Spain"},

//             {"Germany", "Poland"},
//             {"Germany", "Luxembourg"},
//             {"Germany", "Netherlands"},

//             {"Hungary", "Romania"},
//             {"Hungary", "Slovakia"},
//             {"Hungary", "Slovenia"},


//             {"Italy", "Slovenia"},

//             {"Latvia", "Lithuania"},

//             {"Lithuania", "Poland"},

//             {"Portugal", "Spain"},

//             {"Slovakia", "Poland"}
//         };



//         Roadmap roadmap;

//         map<string, vector<string>> graph = roadmap.buildGraph(edges);
//         for (auto& entry : graph)
//         {
//             cout << entry.first << " : ";
//             for (auto& nbr : entry.second)
//             {
//                 cout << nbr << " ";
//             }
//             cout << endl;
//         }
//     }

// }//namespace end
