// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2015, Abel Sinkovics (abel@sinkovics.hu)
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

#include <metashell/code_completer_constant.hpp>
#include <metashell/cpp_validator_constant.hpp>
#include <metashell/engine.hpp>
#include <metashell/engine_constant.hpp>
#include <metashell/header_discoverer_constant.hpp>
#include <metashell/preprocessor_shell_constant.hpp>
#include <metashell/template_tracer_constant.hpp>
#include <metashell/type_shell_constant.hpp>

using namespace metashell;

namespace
{
  header_discoverer_constant create_header_discoverer_with_include_path(
      data::include_type type_, std::vector<boost::filesystem::path> path_)
  {
    const std::vector<boost::filesystem::path> empty;

    switch (type_)
    {
    case data::include_type::sys:
      return header_discoverer_constant(move(path_), empty);
    case data::include_type::quote:
      return header_discoverer_constant(empty, move(path_));
    }
    // avoid control reaches end of non-void function warnings on
    // some compilers
    return header_discoverer_constant(empty, empty);
  }
}

std::unique_ptr<iface::engine> metashell::create_failing_engine()
{
  const data::result result(false, "", "Using failing engine", "");
  const std::vector<boost::filesystem::path> empty;

  return make_engine(
      "failing", type_shell_constant(result),
      preprocessor_shell_constant(result), code_completer_constant(),
      header_discoverer_constant(empty, empty),
      template_tracer_constant(result), cpp_validator_constant(result));
}

std::unique_ptr<iface::engine>
metashell::create_engine_returning_type(const std::string& type_)
{
  const data::result result(true, type_, "", "");
  const std::vector<boost::filesystem::path> empty;

  return make_engine(
      "type_returning", type_shell_constant(result),
      preprocessor_shell_constant(result), code_completer_constant(),
      header_discoverer_constant(empty, empty),
      template_tracer_constant(result), cpp_validator_constant(result));
}

std::unique_ptr<iface::engine> metashell::create_engine_with_include_path(
    data::include_type type_, std::vector<boost::filesystem::path> path_)
{
  const data::result result(true, "int", "", "");

  return make_engine(
      "engine_with_include_path", type_shell_constant(result),
      preprocessor_shell_constant(result), code_completer_constant(),
      create_header_discoverer_with_include_path(type_, path_),
      template_tracer_constant(result), cpp_validator_constant(result));
}
