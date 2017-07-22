#ifndef __sudoku_h__
#define __sudoku_h__

#define SIZE 9
#define MIN_VAL 1
#define MAX_VAL 9

class variable;

class sudoku
{
  protected:
    variable*** _board;

    void init_board();
    void update_domains(int value, int x, int y);
    void update_row_domains(int value, int x, int y);
    void update_column_domains(int value, int x, int y);
    void update_ninth_domains(int value, int x, int y);
    bool find_domain_of_one(int& x,int& y);

  public:
    sudoku();
    sudoku(const sudoku& obj); //Copy constructor
    ~sudoku();

    bool domain_wipeout();
    void set_value(int value, int x, int y);
    void propagate_constraints();
    bool next_open_cell(int& x, int& y);
    variable* get_variable_at(int x,int y);
    bool solution_check();
    void print_board();
};

#endif
