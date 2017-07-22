#include "sudoku.h"
#include "variable.h"

#include <iostream>
#include <string>

sudoku::sudoku()
{
  init_board();
}

sudoku::sudoku(const sudoku& obj)
{
  _board = new variable**[SIZE];
  for (int x = 0; x < SIZE; x++)
  {
    _board[x] = new variable*[SIZE];
    for (int y = 0; y < SIZE; y++)
      _board[x][y] = new variable(*(obj._board[x][y]));
  }
}

sudoku::~sudoku()
{
  //Delete the board!
  for (int x = 0; x < SIZE; x++)
  {
    for (int y = 0; y < SIZE; y++)
      delete _board[x][y];
    delete [] _board[x];
  }
  delete [] _board;
}

void sudoku::init_board()
{
  _board = new variable**[SIZE];
  for (int x = 0; x < SIZE; x++)
  {
    _board[x] = new variable*[SIZE];
    for (int y = 0; y < SIZE; y++)
      _board[x][y] = new variable(MIN_VAL,MAX_VAL);
  }
}

void sudoku::update_domains(int value, int x, int y)
{
  //Update the domains according to the 3 constraints
  update_row_domains(value,x,y);
  update_column_domains(value,x,y);
  update_ninth_domains(value,x,y);
}

void sudoku::update_row_domains(int value, int x, int y)
{
  for (int u_x = 0; u_x < SIZE; u_x++)
    _board[u_x][y]->remove_domain_value(value);
}

void sudoku::update_column_domains(int value, int x, int y)
{
  for (int u_y = 0; u_y < SIZE; u_y++)
    _board[x][u_y]->remove_domain_value(value);
}

void sudoku::update_ninth_domains(int value, int x, int y)
{
  int x_off = x/3;
  int y_off = y/3;

  for (int u_x = 0; u_x < SIZE/3; u_x++)
    for (int u_y = 0; u_y < SIZE/3; u_y++)
      _board[u_x + x_off * 3][u_y + y_off * 3]->remove_domain_value(value);
}

void sudoku::propagate_constraints()
{
  bool updated_domain = false;
  int x,y;
  int value;

  //While there exist cells with a single variable in their domains
  //set that value, and update the other domains.
  do
  {
    updated_domain = false;

    //If we've wiped out the domain bail out.
    if (domain_wipeout())
    {
      //std::cout << "Domain wipeout when propagating constraints\n";
      return;
    }

    if (find_domain_of_one(x,y))
    {
      value = _board[x][y]->get_domain()[0];
      set_value(value,x,y);
      updated_domain = true;
      //std::cout << "Propagated constraint value: " << value << " at (" << x << "," << y << ")\n";
    }
  } while (updated_domain);
}

bool sudoku::find_domain_of_one(int& x, int& y)
{
  for (int _x = 0; _x < SIZE; _x++)
    for (int _y = 0; _y < SIZE; _y++)
      if (_board[_x][_y]->get_domain_size() == 1 && !_board[_x][_y]->is_set())
      {
        x = _x;
        y = _y;
        return true;
      }
  return false;
}

bool sudoku::domain_wipeout()
{
  for (int x = 0; x < SIZE; x++)
    for (int y = 0; y < SIZE; y++)
      if (_board[x][y]->is_domain_exhausted())
        return true;
  return false;
}

void sudoku::set_value(int value, int x, int y)
{
  if (!_board[x][y]->is_set())
  {
    _board[x][y]->set_value(value);
    update_domains(value,x,y);
  }
}

bool sudoku::next_open_cell(int& x, int& y)
{
  for (int _x = 0; _x < SIZE; _x++)
    for (int _y = 0; _y < SIZE; _y++)
      if (!_board[_x][_y]->is_set())
      {
        x = _x;
        y = _y;
        return true;
      }
  return false;
}

variable* sudoku::get_variable_at(int x,int y)
{
  return _board[x][y];
}

bool sudoku::solution_check()
{
  //If all set, we've found a solution
  for (int x = 0; x < SIZE; x++)
    for (int y = 0; y < SIZE; y++)
      if (!_board[x][y]->is_set())
        return false;
  return true;
}

void sudoku::print_board()
{
  std::string sep = "+---+---+---+";

  for (int y = 0; y < SIZE; y++)
  {
    if (y % 3 == 0)
      std::cout << sep << std::endl;
    for (int x = 0; x < SIZE; x++)
    {
      if (x % 3 == 0)
        std::cout << "|";
      std::cout << _board[x][y]->get_value();
    }
    std::cout << "|" << std::endl;
  }
  std::cout << sep << std::endl;
}

