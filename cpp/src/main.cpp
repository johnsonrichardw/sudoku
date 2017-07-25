#include "sudoku.h"
#include "depth_first_search.h"

int main(int argc, char ** argv)
{
  sudoku* s;
  depth_first_search* dfs;

  for (int i = 0; i < 10; i++)
  {
    s = new sudoku();
    dfs = new depth_first_search();

    dfs->init(s);
    delete s;

    dfs->execute(true);

    delete dfs;
  }

  return 0;
}
