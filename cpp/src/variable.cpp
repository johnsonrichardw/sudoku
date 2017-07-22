#include <algorithm>

#include "variable.h"

variable::variable(int min_val, int max_val): _set(false)
{
  for (int i = min_val; i <= max_val; i++)
    _domain.push_back(i);
}

variable::variable(const variable& obj)
{
  _set = obj._set;
  _value = obj._value;
  _domain = std::vector<int>(obj._domain);
}

void variable::set_value(int value)
{
  _set = true;
  _value = value;
  remove_domain_value(value);
}

int variable::get_value()
{
  return _value;
}

bool variable::is_set()
{
  return _set;
}

std::vector<int>& variable::get_domain()
{
  return _domain;
}

void variable::remove_domain_value(int value)
{
  auto it = std::find(_domain.begin(),_domain.end(),value);
  if (it != _domain.end())
    _domain.erase(it);
}

void variable::add_domain_value(int value)
{
  _domain.push_back(value);
}

int variable::get_domain_size()
{
  return _domain.size();
}

bool variable::is_domain_exhausted()
{
  return !_set && _domain.size() == 0;
}
