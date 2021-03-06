// RUN: %clang_cc1 -templight-dump %s 2>&1 | FileCheck %s

template <int N>
struct foo : foo<N - 1> {};

template <>
struct foo<0> {};

// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<2>'$}}
// CHECK: {{^kind:[ ]+TemplateInstantiation$}}
// CHECK: {{^event:[ ]+Begin$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:}}[[@LINE+26]]{{:8'$}}
// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<1>'$}}
// CHECK: {{^kind:[ ]+TemplateInstantiation$}}
// CHECK: {{^event:[ ]+Begin$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:4:14'$}}
// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<0>'$}}
// CHECK: {{^kind:[ ]+Memoization$}}
// CHECK: {{^event:[ ]+Begin$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:4:14'$}}
// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<0>'$}}
// CHECK: {{^kind:[ ]+Memoization$}}
// CHECK: {{^event:[ ]+End$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:4:14'$}}
// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<1>'$}}
// CHECK: {{^kind:[ ]+TemplateInstantiation$}}
// CHECK: {{^event:[ ]+End$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:4:14'$}}
// CHECK-LABEL: {{^---$}}
// CHECK: {{^name:[ ]+'foo<2>'$}}
// CHECK: {{^kind:[ ]+TemplateInstantiation$}}
// CHECK: {{^event:[ ]+End$}}
// CHECK: {{^poi:[ ]+'.*templight-nested-template-instantiation.cpp:}}[[@LINE+1]]{{:8'$}}
foo<2> x;

