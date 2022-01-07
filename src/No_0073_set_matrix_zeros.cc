#include <stdio.h> // __DATE__, __TIME__, __FILE__, __func__, __LINE__
#include <vector>
#include <iostream>
#include <set>
#include "ioutils.h"
#include "mylog.h"

// 1. A straightforward solution using O(mn) space is probably a bad idea.
// 2. A simple improvement uses O(m + n) space, but still not the best solution.
// 3. Could you devise a constant space solution?
class Solution {
public:
	// Naive implementation
    void setZeroes_naive(std::vector<std::vector<int>>& matrix) {
    	int rows = matrix.size();
    	int cols = matrix[0].size();

    	std::vector<std::vector<int>> is_zero_symbol(rows, std::vector<int>(cols,0));
        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (matrix[y][x]==0)
        		{
        			// all the element in the row
        			for (int i=0; i<cols; i++)
        			{
        				is_zero_symbol[y][i] = 1;
        			}
        			// all the element in the col
        			for (int j=0; j<rows; j++)
        			{
        				is_zero_symbol[j][x] = 1;
        			}
        		}
        	}
        }

        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (is_zero_symbol[y][x]==1)
        		{
        			matrix[y][x] = 0;
        		}
        	}
        }
	}

	// Improved version
    void setZeroes_improved(std::vector<std::vector<int>>& matrix) {
    	int rows = matrix.size();
    	int cols = matrix[0].size();

        std::vector<int> is_zero_symbol(rows+cols, 0);
        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (matrix[y][x]==0)
        		{
        			is_zero_symbol[y] = 1;
        			is_zero_symbol[rows+x] = 1;
        		}
        	}
        }

        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (is_zero_symbol[y]==1)
        		{
        			matrix[y][x] = 0;
        		}
        		if (is_zero_symbol[rows+x]==1)
        		{
        			matrix[y][x] = 0;
        		}
        	}
        }
	}
    void setZeroes_hashtable(std::vector<std::vector<int>>& matrix) {
    	int rows = matrix.size();
    	int cols = matrix[0].size();

		// hash set
        std::set<int> row_symbols;
        std::set<int> col_symbols;

        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (0==matrix[y][x])
        		{
        			row_symbols.insert(y);
        			col_symbols.insert(x);
        		}
        	}
        }

        for (int y=0; y<rows; y++)
        {
        	int row_symbol = row_symbols.find(y)!=row_symbols.end();
        	for (int x=0; x<cols; x++)
        	{
        		if (row_symbol || col_symbols.find(x)!=col_symbols.end())
        		{
        			matrix[y][x] = 0;
        		}
        	}
        }
	}
	// Fancy solution
    void setZeroes(std::vector<std::vector<int>>& matrix) {
    	int rows = matrix.size();
    	int cols = matrix[0].size();

		int first_row = 0;
        int first_col = 0;
        for (int y=0; y<rows; y++)
        {
        	for (int x=0; x<cols; x++)
        	{
        		if (matrix[y][x]==0)
        		{
        			if (0==y) first_row = 1;
        			if (0==x) first_col = 1;
        			matrix[y][0] = 0;
        			matrix[0][x] = 0;
        		}
        	}
        }

        for (int y=1; y<rows; y++)
        {
        	for (int x=1; x<cols; x++)
        	{
        		if (0==matrix[0][x] || 0==matrix[y][0])
        		{
        			matrix[y][x] = 0;
        		}
        	}
        }

        if (1==first_row)
        {
        	for (int x=0; x<cols; x++)
        	{
        		matrix[0][x] = 0;
        	}
        }
        if (1==first_col)
        {
        	for (int y=0; y<rows; y++)
        	{
        		matrix[y][0] = 0;
        	}
        }
    }
};

int main(int argc, char *argv[])
{
    LOG_INFO("%s", __func__);
	std::vector<std::vector<int>> mat1 = {{1,1,1}, {1,0,1}, {1,1,1}};
	std::vector<std::vector<int>> mat2 = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

	Solution solver;
	print_2d_vector(mat1);
	solver.setZeroes(mat1);
	printf("result after modification: \n");
	print_2d_vector(mat1);

	print_2d_vector(mat2);
	solver.setZeroes(mat2);
	printf("result after modification: \n");
	print_2d_vector(mat2);

	spdlog::info("");
	
	return 0;
}
