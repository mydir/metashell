#ifndef METASHELL_DATA_USER_CONFIG_HPP
#define METASHELL_DATA_USER_CONFIG_HPP

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

#include <metashell/data/standard.hpp>
#include <metashell/data/stdlib.hpp>
#include <metashell/data/console_type.hpp>
#include <metashell/data/logging_mode.hpp>

#include <string>
#include <vector>

namespace metashell
{
  namespace data
  {
    struct user_config
    {
      std::vector<std::string> include_path;
      bool verbose = false;
      bool syntax_highlight = true;
      bool indent = true;
      standard standard_to_use = standard::cpp11;
      std::vector<std::string> macros;
      bool warnings_enabled = true;
      std::vector<std::string> extra_clang_args;
      bool use_precompiled_headers = false;
      std::string clang_path;
      int max_template_depth = 256;
      bool saving_enabled = false;
      console_type con_type = console_type::plain;
      bool splash_enabled = true;
      logging_mode log_mode = logging_mode::none;
      std::string log_file;
      stdlib stdlib_to_use = stdlib::libstdcxx;
    };
  }
}

#endif

