// Metashell - Interactive C++ template metaprogramming shell
// Copyright (C) 2013, Abel Sinkovics (abel@sinkovics.hu)
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

#include "test_shell.hpp"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_non_existing_class)
{
  test_shell sh;
  sh.line_available("hello");
  BOOST_CHECK_EQUAL("", sh.info());
  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK(!sh.error().empty());
}

BOOST_AUTO_TEST_CASE(test_accept_empty_input)
{
  test_shell sh;
  sh.line_available("");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_space_input)
{
  test_shell sh;
  sh.line_available(" ");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_tab_input)
{
  test_shell sh;
  sh.line_available("\t");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_vertical_tab_input)
{
  test_shell sh;
  sh.line_available("\v");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_new_line_input)
{
  test_shell sh;
  sh.line_available("\n");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_carrige_return_input)
{
  test_shell sh;
  sh.line_available("\r");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}

BOOST_AUTO_TEST_CASE(test_accept_two_space_input)
{
  test_shell sh;
  sh.line_available("  ");

  BOOST_CHECK_EQUAL("", sh.output());
  BOOST_CHECK_EQUAL("", sh.error());
}


