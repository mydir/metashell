// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Abel Sinkovics (abel@sinkovics.hu)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <metashell/pragma_environment_pop.hpp>
#include <metashell/shell.hpp>

using namespace metashell;

pragma_environment_pop::pragma_environment_pop(shell& shell_) :
  _shell(shell_)
{}

pragma_handler_interface* pragma_environment_pop::clone() const
{
  return new pragma_environment_pop(_shell);
}

std::string pragma_environment_pop::arguments() const
{
  return "";
}

std::string pragma_environment_pop::description() const
{
  return "Pops the last environment from the environment stack.";
}

void pragma_environment_pop::run(
  const token_iterator& args_begin_,
  const token_iterator& args_end_
) const
{
  _shell.pop_environment();
  _shell.display_environment_stack_size();
}
