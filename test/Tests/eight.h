// RUN: cpp2c %s | FileCheck %s --color

#define EIGHT 8

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "EIGHT",
// CHECK:     "IsObjectLike": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/eight.h:3:9"
// CHECK:   }
// CHECK: ]
