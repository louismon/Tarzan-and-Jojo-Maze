#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<string>
//#include<list>
//#include <boost/graph/adjacency_list.hpp>
//#include <boost/config.hpp>


using namespace std;

int row, col;

struct Node
{
    //pair<int,int> coordinates;
    int nodeRow;
    int nodeCol;
    string direction;
    Node* next3;
    Node* next4; 
};

//list<Node> adjList;

vector<vector<string>> table;

void createList(Node temp, vector<string> &path)
    {
        //int temp.nodeRow = temp.nodeRow;
        //int temp.nodeCol = temp.nodeCol;
        //string direction = temp.direction;

        //cout << "Coordinates: (" << temp.nodeRow << "," << temp.nodeCol << ")\tDirection: " << temp.direction << endl;
        table.at(temp.nodeRow).at(temp.nodeCol) = "X";
        
        //cout << "Path Size: " << path.size() << endl << "Current Path: ";
        
        if (temp.direction == "N")
            {
                if(temp.nodeRow-3 >= 0)
                    {
                        if (table.at(temp.nodeRow-3).at(temp.nodeCol) != "X")
                            {
                                Node newNode = {temp.nodeRow-3, temp.nodeCol, table.at(temp.nodeRow-3).at(temp.nodeCol), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("N-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow-4 >= 0)
                    {
                        if (table.at(temp.nodeRow-4).at(temp.nodeCol) != "X")
                            {
                                Node newNode = {temp.nodeRow-4, temp.nodeCol, table.at(temp.nodeRow-4).at(temp.nodeCol), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("N-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "NE")
            {
                if(temp.nodeRow-3 >= 0 && temp.nodeCol+3 < col)
                    {
                        if (table.at(temp.nodeRow-3).at(temp.nodeCol+3) != "X")
                            {
                                Node newNode = {temp.nodeRow-3, temp.nodeCol+3, table.at(temp.nodeRow-3).at(temp.nodeCol+3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("NE-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow-4 >= 0 && temp.nodeCol+4 < col)
                    {
                        if (table.at(temp.nodeRow-4).at(temp.nodeCol+4) != "X")
                            {
                                Node newNode = {temp.nodeRow-4, temp.nodeCol+4, table.at(temp.nodeRow-4).at(temp.nodeCol+4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("NE-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "E")
            {
                if(temp.nodeCol+3 < col)
                    {
                        if (table.at(temp.nodeRow).at(temp.nodeCol+3) != "X")
                            {
                                Node newNode = {temp.nodeRow, temp.nodeCol+3, table.at(temp.nodeRow).at(temp.nodeCol+3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("E-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeCol+4 < col)
                    {
                        if (table.at(temp.nodeRow).at(temp.nodeCol+4) != "X")
                            {
                                Node newNode = {temp.nodeRow, temp.nodeCol+4, table.at(temp.nodeRow).at(temp.nodeCol+4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("E-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "SE")
            {
                if(temp.nodeRow+3 < row && temp.nodeCol+3 < col)
                    {
                        if (table.at(temp.nodeRow+3).at(temp.nodeCol+3) != "X")
                            {
                                Node newNode = {temp.nodeRow+3, temp.nodeCol+3, table.at(temp.nodeRow+3).at(temp.nodeCol+3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("SE-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow+4 < row && temp.nodeCol+4 < col)
                    {
                        if (table.at(temp.nodeRow+4).at(temp.nodeCol+4) != "X")
                            {
                                Node newNode = {temp.nodeRow+4, temp.nodeCol+4, table.at(temp.nodeRow+4).at(temp.nodeCol+4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("SE-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "S")
            {
                if(temp.nodeRow+3 < row)
                    {
                        if (table.at(temp.nodeRow+3).at(temp.nodeCol) != "X")
                            {
                                Node newNode = {temp.nodeRow+3, temp.nodeCol, table.at(temp.nodeRow+3).at(temp.nodeCol), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("S-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow+4 < row)
                    {
                        if (table.at(temp.nodeRow+4).at(temp.nodeCol) != "X")
                            {
                                Node newNode = {temp.nodeRow+4, temp.nodeCol, table.at(temp.nodeRow+4).at(temp.nodeCol), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("S-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "SW")
            {
                if(temp.nodeRow+3 < row && temp.nodeCol-3 >= 0)
                    {
                        if (table.at(temp.nodeRow+3).at(temp.nodeCol-3) != "X")
                            {
                                Node newNode = {temp.nodeRow+3, temp.nodeCol-3, table.at(temp.nodeRow+3).at(temp.nodeCol-3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("SW-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow+4 < row && temp.nodeCol-4 >= 0)
                    {
                        if (table.at(temp.nodeRow+4).at(temp.nodeCol-4) != "X")
                            {
                                Node newNode = {temp.nodeRow+4, temp.nodeCol-4, table.at(temp.nodeRow+4).at(temp.nodeCol-4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("SW-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "W")
            {
                if(temp.nodeCol-3 >= 0)
                    {
                        if (table.at(temp.nodeRow).at(temp.nodeCol-3) != "X")
                            {
                                Node newNode = {temp.nodeRow, temp.nodeCol-3, table.at(temp.nodeRow).at(temp.nodeCol-3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("W-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeCol-4 >= 0)
                    {
                        if (table.at(temp.nodeRow).at(temp.nodeCol-4) != "X")
                            {
                                Node newNode = {temp.nodeRow, temp.nodeCol-4, table.at(temp.nodeRow).at(temp.nodeCol-4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("W-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        if (temp.direction == "NW")
            {
                if(temp.nodeRow-3 >= 0 && temp.nodeCol-3 >= 0 )
                    {
                        if (table.at(temp.nodeRow-3).at(temp.nodeCol-3) != "X")
                            {
                                Node newNode = {temp.nodeRow-3, temp.nodeCol-3, table.at(temp.nodeRow-3).at(temp.nodeCol-3), NULL, NULL};
                                temp.next3 = &newNode;
                                path.push_back("NW-3");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }

                if(temp.nodeRow-4 >= 0 && temp.nodeCol-4 >= 0)
                    {
                        if (table.at(temp.nodeRow-4).at(temp.nodeCol-4) != "X")
                            {
                                Node newNode = {temp.nodeRow-4, temp.nodeCol-4, table.at(temp.nodeRow-4).at(temp.nodeCol-4), NULL, NULL};
                                temp.next4 = &newNode;
                                path.push_back("NW-4");
                                createList(newNode, path);
                                path.pop_back();
                            }
                    }                
            }

        else if(temp.direction == "J")
            {
                ofstream output;
                
                output.open("output.txt");
                if(output.is_open())
                    {
                        for (int i =0; i < path.size(); i++)
                            {
                                output << path.at(i) << " ";
                            }
                    }
            }
    }


int main()
    {
        fstream input;
        string temp;
        int line = 0;

        //int row, col;
        int srow, scol;

        //vector<vector<string>> tempArray;
        vector<string> rowVector; 
        vector<string> path;

        //cout << "Prior to Input" << endl;

        input.open("input.txt");
        if(input.is_open())
            {
                while (getline(input, temp))
                {

                    if (line == 0)
                        {
                            row = stoi(temp.substr(0, temp.find(" ")));
                            //cout << "Row Size: " << row << endl;
                            col = stoi(temp.substr(temp.find(" ")+1));
                            //cout << "Column Size: " << col << endl;
                        }

                    else if(line == 1)
                        {
                            srow = stoi(temp.substr(0, temp.find(" "))) -1;
                            scol = stoi(temp.substr(temp.find(" ")+1)) -1;
                            //cout << "Tarzan Start: (" << srow << "," << scol << ")" << endl;
                        }
                    else 
                        {
                            int pos;
                            //int i = 0;
                            while ((pos = temp.find(" ")) != string::npos)
                                {
                                    rowVector.push_back(temp.substr(0, pos));
                                    //cout << rowVector.at(i) << " ";
                                    temp = temp.substr(pos+1);
                                    //i++;
                                }
                            
                            //Needed because the rows tarzan/small end in a space while large ends in newline
                            //So sometimes there'd be a missed final column and
                            //Others there wouldn't so needed a check
                            if ((pos = temp.find(" ")) == string::npos && !temp.empty())
                                {
                                    rowVector.push_back(temp.substr(0));
                                    //cout << rowVector.back();
                                }

                            //cout << rowVector.size() << " ";
                            //Covers cases like large where 1 row takes more than 1 line
                            if (rowVector.size() == col)
                                {
                                    //cout << endl;
                                    table.push_back(rowVector);
                                    rowVector.clear();
                                }
                            
                            
                        }
                    //cout << "Line: " << line << endl;
                    line++;
                }
                input.close();
                //cout << "Input closed" << endl;
            }

        /*for (int i=0; i < col; i++)
            {
                cout << tempArray.at(0).at(i) << " ";
            }*/
        
        Node start = {srow, scol, table.at(srow).at(scol), NULL, NULL};
        //cout << "Before create list call" << endl;
        createList(start, path);


        return 0;
    }