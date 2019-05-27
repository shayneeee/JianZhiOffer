#include <iostream>
using namespace std;

bool hasPath(char *matrix, int rows, int columns, char *str)
{
    if(matrix==nullptr||rows<1||columns<1||str==nullptr)
        return false;

    bool *visited=new bool[rows*columns];
    for(int i=0; i<rows*columns; i++)
        visited[i]=false;

    int pathlength=0;
    for(int row=0; row<rows; row++)
    {
        for(int column=0; column<columns; column++)
        {
            if(haspathcore(matrix, rows, columns, row, column, str, pathlength, visited))
                return true;
        }
    }
    delete []visited;
    return false;
}

bool haspathcore(const char *matrix, int rows, int columns, int row, int column, const char *str, int &pathlength, bool *visited)
{
    if(str[pathlength]=='\0')   //判断str是否已经到结尾
        return true;

    bool haspath=false;
    if(row>0&&row<rows&&column>0&&column<columns&&!visited[row*columns+column]&&matrix[row*columns+columns]==str[pathlength])//判断matrix[row][column]是否是str[pathlength]
    {
        pathlength++;
        visited[row*columns+column]=true;
        haspath=haspathcore(matrix, rows, columns, row+1, column, str, pathlength+1, visited)||
                haspathcore(matrix, rows, columns, row-1, column, str, pathlength+1, visited)||
                haspathcore(matrix, rows, columns, row, column+1, str, pathlength+1, visited)||
                haspathcore(matrix, rows, columns, row, column-1, str, pathlength+1, visited);
    }

    if(!haspath)
    {
        pathlength--;
        visited[row*columns+column]=false;
    }

    return haspath;
}

