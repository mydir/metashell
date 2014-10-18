
// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2014, Andras Kucsma (andras.kucsma@gmail.com)
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

#include <metashell/pragma_mdb.hpp>
#include <metashell/shell.hpp>
#include <metashell/readline_mdb_shell.hpp>
#include <metashell/mdb_templight_be.hpp>

using namespace metashell;

pragma_mdb::pragma_mdb(shell& shell_) :
  _shell(shell_)
{}

pragma_handler_interface* pragma_mdb::clone() const
{
  return new pragma_mdb(_shell);
}

std::string pragma_mdb::arguments() const
{
  return "[<type>]";
}

std::string pragma_mdb::description() const
{
  return "Starts the metadebugger, and optionally evaluates type.";
}

void pragma_mdb::run(
  const command::iterator& args_begin_,
  const command::iterator& args_end_
) const
{
  std::string args = tokens_to_string(args_begin_, args_end_);

  mdb_templight_be mdb_be(
      _shell.get_config(),
      _shell.env());

  readline_mdb_shell mdb_shell(mdb_be);

  mdb_shell.display_splash();

  if (!args.empty()) {
    mdb_shell.command_evaluate(args);
  }

  mdb_shell.run();
}

