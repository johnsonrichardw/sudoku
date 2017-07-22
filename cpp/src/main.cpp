#include "sudoku.h"
#include "depth_first_search.h"

int main(int argc, char ** argv)
{
  sudoku* s;
  depth_first_search* dfs;

  s = new sudoku();
  dfs = new depth_first_search();

  dfs->init(s);
  delete s;

  dfs->execute();

  delete dfs;

  return 0;
}
