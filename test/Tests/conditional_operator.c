// RUN: cpp2c %s | jq '[.[] | select(.IsDefinitionLocationValid == null or .IsDefinitionLocationValid == true)] | sort_by(.PropertiesOf, .DefinitionLocation, .InvocationLocation)' | FileCheck %s --color

#define IF_A_THEN_B_ELSE_C(a, b, c) ((a) ? (b) : (c))
int main(int argc, char const *argv[])
{
    IF_A_THEN_B_ELSE_C(1, 2, 3);
    return 0;
}

// CHECK: [
// CHECK:   {
// CHECK:     "PropertiesOf": "Definition",
// CHECK:     "Name": "IF_A_THEN_B_ELSE_C",
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/conditional_operator.c:3:9"
// CHECK:   },
// CHECK:   {
// CHECK:     "PropertiesOf": "Invocation",
// CHECK:     "Name": "IF_A_THEN_B_ELSE_C",
// CHECK:     "DefinitionLocation": "{{.*}}/Tests/conditional_operator.c:3:9",
// CHECK:     "EndDefinitionLocation": "{{.*}}/Tests/conditional_operator.c:3:53",
// CHECK:     "InvocationLocation": "{{.*}}/Tests/conditional_operator.c:6:5",
// CHECK:     "ASTKind": "Expr",
// CHECK:     "TypeSignature": "int IF_A_THEN_B_ELSE_C(int a, int b, int c)",
// CHECK:     "InvocationDepth": 0,
// CHECK:     "NumASTRoots": 1,
// CHECK:     "NumArguments": 3,
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
// CHECK:     "DoesAnyArgumentContainDeclRefExpr": false,
// CHECK:     "IsHygienic": true,
// CHECK:     "IsDefinitionLocationValid": true,
// CHECK:     "IsInvocationLocationValid": true,
// CHECK:     "IsObjectLike": false,
// CHECK:     "IsInvokedInMacroArgument": false,
// CHECK:     "IsNamePresentInCPPConditional": false,
// CHECK:     "IsExpansionICE": true,
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
// CHECK:     "IsAnyArgumentConditionallyEvaluated": true,
// CHECK:     "IsAnyArgumentNeverExpanded": false,
// CHECK:     "IsAnyArgumentNotAnExpression": false
// CHECK:   }
// CHECK: ]
