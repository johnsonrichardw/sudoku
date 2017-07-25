#ifndef __depth_first_search_h__
#define __depth_first_search_h__

#include <stack>
#include <random>

class sudoku;

class depth_first_search
{
  protected:
    std::stack<sudoku*> _stack;
    std::mt19937 gen;

  public:
    depth_first_search();
    ~depth_first_search();

    void init(sudoku* init_state);
    bool execute(bool display_result);
};

#endif
