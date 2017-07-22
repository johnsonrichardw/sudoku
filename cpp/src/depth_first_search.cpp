#include "depth_first_search.h"
#include "sudoku.h"
#include "variable.h"
#include <vector>
#include <iostream>

depth_first_search::depth_first_search()
{
}

depth_first_search::~depth_first_search()
{
  //Delete any remaining states on the stack
  while (_stack.size() > 0)
  {
    sudoku* s = _stack.top();
    _stack.pop();
    delete s;
  }
}

void depth_first_search::init(sudoku* init_state)
{
  _stack.push(new sudoku(*init_state));
}

bool depth_first_search::execute()
{
  int iter = 0;
  sudoku * curr_board;
  int x,y;
  variable * var;
  std::vector<int> vals;

  while (true)
  {
    iter++;
    if (_stack.size() == 0)
    {
      std::cout << "No solution found: stack is empty" << std::endl;
      return false;
    }

    curr_board = _stack.top();
    _stack.pop();

    curr_board->next_open_cell(x,y);
    var = curr_board->get_variable_at(x,y);

    //Create a new state for each value in the current open cell's domain
    for (auto it = var->get_domain().begin(); it != var->get_domain().end(); it++)
    {
      sudoku * new_board = new sudoku(*curr_board);
      new_board->set_value(*it,x,y);
      new_board->propagate_constraints();

      if (!new_board->domain_wipeout())
      {
        if (new_board->solution_check())
        {
          std::cout << "Solution found in " << iter << " iterations:" << std::endl;
          new_board->print_board();
          return true;
        }
        _stack.push(new_board);
      }
    }

    //Since we're done with the current board, get rid of it.
    delete curr_board;
  }
}

