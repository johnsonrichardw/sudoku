#ifndef __variable_h__
#define __variable_h__

#include <vector>

class variable
{
  protected:
    bool _set;
    int _value;
    std::vector<int> _domain;

  public:
    variable(int min_val, int max_val);
    variable(const variable& obj); //Copy constructor

    void set_value(int value);
    int get_value();
    bool is_set();

    std::vector<int>& get_domain();
    void remove_domain_value(int value);
    void add_domain_value(int value);
    int get_domain_size();
    bool is_domain_exhausted();
};

#endif
