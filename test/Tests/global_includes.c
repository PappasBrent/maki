// RUN: cpp2c %s | jq '[.[] | select(.IsDefinitionLocationValid == null or .IsDefinitionLocationValid == true)] | sort_by(.PropertiesOf, .DefinitionLocation, .InvocationLocation)' | FileCheck %s --color

#include "h1.h"
struct person_t
{
    char *name;
    int age;
};
#include "h2.h"
int x = 1;
#include "h3.h"
int main(int argc, char const *argv[])
{
    return 0;
}

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Include",
// CHECK:     "IsIncludeLocationValid": true,
// CHECK:     "IncludeName": "{{.*}}/Tests/h1.h"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Include",
// CHECK:     "IsIncludeLocationValid": true,
// CHECK:     "IncludeName": "{{.*}}/Tests/h2.h"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Include",
// CHECK:     "IsIncludeLocationValid": true,
// CHECK:     "IncludeName": "{{.*}}/Tests/h4.h"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Include",
// CHECK:     "IsIncludeLocationValid": true,
// CHECK:     "IncludeName": "{{.*}}/Tests/h3.h"
// CHECK:   }
// CHECK: ]
