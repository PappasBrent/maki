// RUN: cpp2c %s | jq '[.[] | select(.IsDefinitionLocationValid == null or .IsDefinitionLocationValid == true)] | sort_by(.PropertiesOf, .DefinitionLocation, .InvocationLocation)' | FileCheck %s --color

#define ONE 1
#define FOO() 2
int main(int argc, char const *argv[])
{
#undef ONE
#undef FOO
    return 0;
}

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "ONE",
// CHECK:     "IsObjectLike": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/undef.c:3:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "FOO",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/undef.c:4:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "InspectedByCPP",
// CHECK:     "Name": "FOO"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "InspectedByCPP",
// CHECK:     "Name": "ONE"
// CHECK:   }
// CHECK: ]
