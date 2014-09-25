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

#include "mdb_test_shell.hpp"

#include "test_fibonacci.hpp"

#include <just/test.hpp>

using namespace metashell;

#ifndef METASHELL_DISABLE_TEMPLIGHT_TESTS
JUST_TEST_CASE(test_mdb_evaluate_int) {
  mdb_test_shell sh;

  sh.line_available("evaluate int");

  JUST_ASSERT_EQUAL(sh.get_output(), "");
  JUST_ASSERT(sh.has_metaprogram());
  JUST_ASSERT_EQUAL(sh.get_metaprogram().get_evaluation_result(), "int");
}
#endif

#ifndef METASHELL_DISABLE_TEMPLIGHT_TESTS
JUST_TEST_CASE(test_mdb_evaluate_fib_10) {
  mdb_test_shell sh(fibonacci_mp);

  sh.line_available("evaluate int_<fib<10>::value>");

  JUST_ASSERT_EQUAL(sh.get_output(), "");
  JUST_ASSERT(sh.has_metaprogram());
  JUST_ASSERT_EQUAL(sh.get_metaprogram().get_evaluation_result(), "int_<55>");
}
#endif

#ifndef METASHELL_DISABLE_TEMPLIGHT_TESTS
JUST_TEST_CASE(test_mdb_evaluate_no_arguments) {
  mdb_test_shell sh;

  sh.line_available("evaluate");

  JUST_ASSERT(!sh.has_metaprogram());
  JUST_ASSERT_EQUAL(sh.get_output(), "Argument expected\n");
}
#endif

#ifndef METASHELL_DISABLE_TEMPLIGHT_TESTS
JUST_TEST_CASE(test_mdb_evaluate_no_arguments_with_trailing_spaces) {
  mdb_test_shell sh;

  sh.line_available("evaluate  ");

  JUST_ASSERT(!sh.has_metaprogram());
  JUST_ASSERT_EQUAL(sh.get_output(), "Argument expected\n");
}
#endif

