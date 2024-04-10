// RUN: cpp2c %s | FileCheck %s --color

#define ONE 1

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "ONE",
// CHECK:     "IsObjectLike": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/one.h:3:9"
// CHECK:   }
// CHECK: ]
