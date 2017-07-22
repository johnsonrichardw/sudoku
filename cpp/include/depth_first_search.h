#ifndef __depth_first_search_h__
#define __depth_first_search_h__

#include <stack>

class sudoku;

class depth_first_search
{
  protected:
    std::stack<sudoku*> _stack;

  public:
    depth_first_search();
    ~depth_first_search();

    void init(sudoku* init_state);
    bool execute();
};

#endif
