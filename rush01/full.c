/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:18:50 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/15 15:34:49 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Analysing the Input Function
int input(char *str, int content[16]) 
{
    int i = 0;
    int j = 0;
    while (str[i]) 
    {
        if (str[i] >= '1' && str[i] <= '4') 
        {
            content[j++] = str[i] - '0'; // convert a string into an int 
        } 
        else if (str[i] != ' ') // if the string is not between (1-4) and not a space return (0)
            return 0;
        i++;
    }
    return (j == 16);
}

// Check Column Constraints
/*int check_column_content(int grid[4][4], int content[16])
{
    int col, 
    int i; 
    int max;
    int count;
    
    col = 0;
    while (col < 4) // Loop through columns
    { 
        // Counts how many boxes are visible from the top
        i = 0; 
        max = 0; 
        count = 0;
        while (i < 4) 
        {
            if (grid[i][col] > max) 
            {
                max = grid[i][col];
                count++;
            }
            i++;
        }
        if (count != content[col])
            return 0;
        // Counts how many boxes are visible from the bottom
        i = 3;
        max = 0; 
        count = 0;
        while (i >= 0) 
        {
            if (grid[i][col] > max) 
            {
                max = grid[i][col];
                count++;
            }
            i--;
        }
        if (count != content[col + 4])
            return 0;
        col++;
    }
    return 1;
}

// Check Row Contents
int check_row_content(int grid[4][4], int content[16]) 
{
    int row, i, max, count;
    row = 0;
    while (row < 4) // Loop through rows
    { 
        // Counts how many boxes are visible from the left
        i = 0; max = 0; count = 0;
        while (i < 4) 
        {
            if (grid[row][i] > max) 
            {
                max = grid[row][i];
                count++;
            }
            i++;
        }
        if (count != content[row + 8])
            return 0;
        // Counts how many boxes are visible from the right
        i = 3; 
        max = 0; 
        count = 0;
        while (i >= 0) 
        {
            if (grid[row][i] > max) 
            {
                max = grid[row][i];
                count++;
            }
            i--;
        }
        if (count != content[row + 12])
            return 0;
        row++;
    }
    return 1;
}

// Main Content Checker
int check_content(int grid[4][4], int content[16]) 
{
    return (check_column_content(grid, content) &&
            check_row_content(grid, content));
}
*/

// Check if number can be placed
int is_valid(int grid[4][4], int row, int col, int num) 
{
    int i;
    
    i = 0;
    while (i < 4) 
    {
        if (grid[row][i] == num || grid[i][col] == num) // to make sure no number is repeated in the same column and row
            return 0;
        i++;
    }
    return 1;
}

// Recursive Solver
int solve(int grid[4][4], int row, int col, int content[16]) 
{
   if (row == 4) // End of grid  (it means we've filled all rows)
         return check_content(grid, content);
    if (col == 4) // End of row   (it means we’ve finished placing numbers in the current row)
        return solve(grid, row + 1, 0, content);
    int num;
    
    num = 1;
    while (num <= 4) 
    {
        if (is_valid(grid, row, col, num)) 
        {
            grid[row][col] = num;
            if (solve(grid, row, col + 1, content)) // same row, next column
                return 1;
            grid[row][col] = 0; // If the call fails (returns 0), we undo the placement by setting the cell back to 0.
        }
        num++;
    }
    return 0;
}

// Print the grid
void print_grid(int grid[4][4]) 
{
    int i = 0;
    while (i < 4) 
    {
        int j = 0;
        while (j < 4) 
        {
            char c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

// Main Function
int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        write(1, "Error\n", 6);
        return 1;
    }
    int content[16];
    if (!input(argv[1], content)) 
    {
        write(1, "Error\n", 6);
        return 1;
    }
    int grid[4][4] = {0};  // we made a grid filled with zeros 
    if (!solve(grid, 0, 0, content)) 
    {
        write(1, "Error\n", 6);
        return 1;
    }
    print_grid(grid);
    return 0;
}
