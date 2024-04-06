// RUN: cpp2c %s | jq '[.[] | select(.IsDefinitionLocationValid == null or .IsDefinitionLocationValid == true)] | sort_by(.PropertiesOf, .DefinitionLocation, .InvocationLocation)' | FileCheck %s --color

typedef struct
{
    char *name;
    unsigned int age;
} Person;
#define PARENT_GET_AGE(P) ((P).age)
#define PARENT_PTR_GET_AGE(P) ((P)->age)
enum COLOR_TYPE
{
    RGB,
    HSL
};
struct color_t
{
    enum COLOR_TYPE ty;
    union
    {
        struct
        {
            unsigned int r, g, b;
        } rgb;
        struct
        {
            unsigned int h, s, l;
        } hsl;
    };
};
#define RGB_GET_R(rgb) ((rgb).r)
#define RGB_PTR_GET_R(rgb) ((rgb)->r)
int main(int argc, char const *argv[])
{
    Person p;
    p.age = 30;
    PARENT_GET_AGE(p);
    PARENT_PTR_GET_AGE(&p);
    struct color_t c;
    c.ty = RGB;
    c.rgb.r = 0x255;
    c.rgb.g = 0x255;
    c.rgb.b = 0;
    RGB_GET_R(c.rgb);
    RGB_PTR_GET_R(&c.rgb);
    return 0;
}

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "RGB_GET_R",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:30:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "RGB_PTR_GET_R",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:31:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "PARENT_GET_AGE",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:8:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "PARENT_PTR_GET_AGE",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:9:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Invocation",
// CHECK:     "Name": "RGB_GET_R",
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:30:9",
// CHECK:     "EndDefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:30:32",
// CHECK:     "InvocationLocation": "{{.*}}/Tests/anonymous_type_arguments.c:43:5",
// CHECK:     "ASTKind": "Expr",
// CHECK:     "TypeSignature": "unsigned int RGB_GET_R(struct color_t::(unnamed at {{.*}}/anonymous_type_arguments.c:20:9) rgb)",
// CHECK:     "InvocationDepth": 0,
// CHECK:     "NumASTRoots": 1,
// CHECK:     "NumArguments": 1,
// CHECK:     "HasStringification": false,
// CHECK:     "HasTokenPasting": false,
// CHECK:     "HasAlignedArguments": true,
// CHECK:     "HasSameNameAsOtherDeclaration": false,
// CHECK:     "IsExpansionControlFlowStmt": false,
// CHECK:     "DoesBodyReferenceMacroDefinedAfterMacro": false,
// CHECK:     "DoesBodyReferenceDeclDeclaredAfterMacro": false,
// CHECK:     "DoesBodyContainDeclRefExpr": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveLocalType": true,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro": false,
// CHECK:     "DoesAnyArgumentHaveSideEffects": false,
// CHECK:     "DoesAnyArgumentContainDeclRefExpr": true,
// CHECK:     "IsHygienic": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "IsInvocationLocationValid": true,
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsInvokedInMacroArgument": false,
// CHECK:     "IsNamePresentInCPPConditional": false,
// CHECK:     "IsExpansionICE": false,
// CHECK:     "IsExpansionTypeNull": false,
// CHECK:     "IsExpansionTypeAnonymous": false,
// CHECK:     "IsExpansionTypeLocalType": false,
// CHECK:     "IsExpansionTypeDefinedAfterMacro": false,
// CHECK:     "IsExpansionTypeVoid": false,
// CHECK:     "IsAnyArgumentTypeNull": false,
// CHECK:     "IsAnyArgumentTypeAnonymous": true,
// CHECK:     "IsAnyArgumentTypeLocalType": true,
// CHECK:     "IsAnyArgumentTypeDefinedAfterMacro": false,
// CHECK:     "IsAnyArgumentTypeVoid": false,
// CHECK:     "IsInvokedWhereModifiableValueRequired": false,
// CHECK:     "IsInvokedWhereAddressableValueRequired": false,
// CHECK:     "IsInvokedWhereICERequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereModifiableValueRequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereAddressableValueRequired": false,
// CHECK:     "IsAnyArgumentConditionallyEvaluated": false,
// CHECK:     "IsAnyArgumentNeverExpanded": false,
// CHECK:     "IsAnyArgumentNotAnExpression": false
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Invocation",
// CHECK:     "Name": "RGB_PTR_GET_R",
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:31:9",
// CHECK:     "EndDefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:31:37",
// CHECK:     "InvocationLocation": "{{.*}}/Tests/anonymous_type_arguments.c:44:5",
// CHECK:     "ASTKind": "Expr",
// CHECK:     "TypeSignature": "unsigned int RGB_PTR_GET_R(struct color_t::(unnamed at {{.*}}/anonymous_type_arguments.c:20:9) * rgb)",
// CHECK:     "InvocationDepth": 0,
// CHECK:     "NumASTRoots": 1,
// CHECK:     "NumArguments": 1,
// CHECK:     "HasStringification": false,
// CHECK:     "HasTokenPasting": false,
// CHECK:     "HasAlignedArguments": true,
// CHECK:     "HasSameNameAsOtherDeclaration": false,
// CHECK:     "IsExpansionControlFlowStmt": false,
// CHECK:     "DoesBodyReferenceMacroDefinedAfterMacro": false,
// CHECK:     "DoesBodyReferenceDeclDeclaredAfterMacro": false,
// CHECK:     "DoesBodyContainDeclRefExpr": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveLocalType": true,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro": false,
// CHECK:     "DoesAnyArgumentHaveSideEffects": false,
// CHECK:     "DoesAnyArgumentContainDeclRefExpr": true,
// CHECK:     "IsHygienic": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "IsInvocationLocationValid": true,
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsInvokedInMacroArgument": false,
// CHECK:     "IsNamePresentInCPPConditional": false,
// CHECK:     "IsExpansionICE": false,
// CHECK:     "IsExpansionTypeNull": false,
// CHECK:     "IsExpansionTypeAnonymous": false,
// CHECK:     "IsExpansionTypeLocalType": false,
// CHECK:     "IsExpansionTypeDefinedAfterMacro": false,
// CHECK:     "IsExpansionTypeVoid": false,
// CHECK:     "IsAnyArgumentTypeNull": false,
// CHECK:     "IsAnyArgumentTypeAnonymous": true,
// CHECK:     "IsAnyArgumentTypeLocalType": true,
// CHECK:     "IsAnyArgumentTypeDefinedAfterMacro": false,
// CHECK:     "IsAnyArgumentTypeVoid": false,
// CHECK:     "IsInvokedWhereModifiableValueRequired": false,
// CHECK:     "IsInvokedWhereAddressableValueRequired": false,
// CHECK:     "IsInvokedWhereICERequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereModifiableValueRequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereAddressableValueRequired": false,
// CHECK:     "IsAnyArgumentConditionallyEvaluated": false,
// CHECK:     "IsAnyArgumentNeverExpanded": false,
// CHECK:     "IsAnyArgumentNotAnExpression": false
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Invocation",
// CHECK:     "Name": "PARENT_GET_AGE",
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:8:9",
// CHECK:     "EndDefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:8:35",
// CHECK:     "InvocationLocation": "{{.*}}/Tests/anonymous_type_arguments.c:36:5",
// CHECK:     "ASTKind": "Expr",
// CHECK:     "TypeSignature": "unsigned int PARENT_GET_AGE(Person P)",
// CHECK:     "InvocationDepth": 0,
// CHECK:     "NumASTRoots": 1,
// CHECK:     "NumArguments": 1,
// CHECK:     "HasStringification": false,
// CHECK:     "HasTokenPasting": false,
// CHECK:     "HasAlignedArguments": true,
// CHECK:     "HasSameNameAsOtherDeclaration": false,
// CHECK:     "IsExpansionControlFlowStmt": false,
// CHECK:     "DoesBodyReferenceMacroDefinedAfterMacro": false,
// CHECK:     "DoesBodyReferenceDeclDeclaredAfterMacro": false,
// CHECK:     "DoesBodyContainDeclRefExpr": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveLocalType": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro": false,
// CHECK:     "DoesAnyArgumentHaveSideEffects": false,
// CHECK:     "DoesAnyArgumentContainDeclRefExpr": true,
// CHECK:     "IsHygienic": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "IsInvocationLocationValid": true,
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsInvokedInMacroArgument": false,
// CHECK:     "IsNamePresentInCPPConditional": false,
// CHECK:     "IsExpansionICE": false,
// CHECK:     "IsExpansionTypeNull": false,
// CHECK:     "IsExpansionTypeAnonymous": false,
// CHECK:     "IsExpansionTypeLocalType": false,
// CHECK:     "IsExpansionTypeDefinedAfterMacro": false,
// CHECK:     "IsExpansionTypeVoid": false,
// CHECK:     "IsAnyArgumentTypeNull": false,
// CHECK:     "IsAnyArgumentTypeAnonymous": false,
// CHECK:     "IsAnyArgumentTypeLocalType": false,
// CHECK:     "IsAnyArgumentTypeDefinedAfterMacro": false,
// CHECK:     "IsAnyArgumentTypeVoid": false,
// CHECK:     "IsInvokedWhereModifiableValueRequired": false,
// CHECK:     "IsInvokedWhereAddressableValueRequired": false,
// CHECK:     "IsInvokedWhereICERequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereModifiableValueRequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereAddressableValueRequired": false,
// CHECK:     "IsAnyArgumentConditionallyEvaluated": false,
// CHECK:     "IsAnyArgumentNeverExpanded": false,
// CHECK:     "IsAnyArgumentNotAnExpression": false
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Invocation",
// CHECK:     "Name": "PARENT_PTR_GET_AGE",
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:9:9",
// CHECK:     "EndDefinitionLocation": "{{.*}}/Tests/anonymous_type_arguments.c:9:40",
// CHECK:     "InvocationLocation": "{{.*}}/Tests/anonymous_type_arguments.c:37:5",
// CHECK:     "ASTKind": "Expr",
// CHECK:     "TypeSignature": "unsigned int PARENT_PTR_GET_AGE(Person * P)",
// CHECK:     "InvocationDepth": 0,
// CHECK:     "NumASTRoots": 1,
// CHECK:     "NumArguments": 1,
// CHECK:     "HasStringification": false,
// CHECK:     "HasTokenPasting": false,
// CHECK:     "HasAlignedArguments": true,
// CHECK:     "HasSameNameAsOtherDeclaration": false,
// CHECK:     "IsExpansionControlFlowStmt": false,
// CHECK:     "DoesBodyReferenceMacroDefinedAfterMacro": false,
// CHECK:     "DoesBodyReferenceDeclDeclaredAfterMacro": false,
// CHECK:     "DoesBodyContainDeclRefExpr": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveLocalType": false,
// CHECK:     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro": false,
// CHECK:     "DoesAnyArgumentHaveSideEffects": false,
// CHECK:     "DoesAnyArgumentContainDeclRefExpr": true,
// CHECK:     "IsHygienic": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "IsInvocationLocationValid": true,
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsInvokedInMacroArgument": false,
// CHECK:     "IsNamePresentInCPPConditional": false,
// CHECK:     "IsExpansionICE": false,
// CHECK:     "IsExpansionTypeNull": false,
// CHECK:     "IsExpansionTypeAnonymous": false,
// CHECK:     "IsExpansionTypeLocalType": false,
// CHECK:     "IsExpansionTypeDefinedAfterMacro": false,
// CHECK:     "IsExpansionTypeVoid": false,
// CHECK:     "IsAnyArgumentTypeNull": false,
// CHECK:     "IsAnyArgumentTypeAnonymous": false,
// CHECK:     "IsAnyArgumentTypeLocalType": false,
// CHECK:     "IsAnyArgumentTypeDefinedAfterMacro": false,
// CHECK:     "IsAnyArgumentTypeVoid": false,
// CHECK:     "IsInvokedWhereModifiableValueRequired": false,
// CHECK:     "IsInvokedWhereAddressableValueRequired": false,
// CHECK:     "IsInvokedWhereICERequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereModifiableValueRequired": false,
// CHECK:     "IsAnyArgumentExpandedWhereAddressableValueRequired": false,
// CHECK:     "IsAnyArgumentConditionallyEvaluated": false,
// CHECK:     "IsAnyArgumentNeverExpanded": false,
// CHECK:     "IsAnyArgumentNotAnExpression": false
// CHECK:   }
// CHECK: ]
