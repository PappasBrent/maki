// RUN: cpp2c %s | FileCheck %s --color

#include "h4.h"

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Include",
// CHECK:     "IsIncludeLocationValid": true,
// CHECK:     "IncludeName": "{{.*}}/Tests/h4.h"
// CHECK:   }
// CHECK: ]
