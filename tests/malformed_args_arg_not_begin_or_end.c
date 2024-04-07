#define X_PLUS_Y_PLUS_2(x, y) 1 + x + y + 1

#define SUM__ONE_X_Y_X_Y_ONE(x, y) 1 + x + y + x + y + 1

int main(int argc, char const *argv[])
{
    // All of these macros have aligned bodies,
    // but unaligned arguments

    X_PLUS_Y_PLUS_2(1 << 2, 3 >> 4);
    X_PLUS_Y_PLUS_2(1 & 2, 3 | 4);
    SUM__ONE_X_Y_X_Y_ONE(1 << 2, 3 >> 4);
    SUM__ONE_X_Y_X_Y_ONE(1 & 2, 3 | 4);

    return 0;
}


// Expected invocation properties:
// Invocation	{     "Name" : "X_PLUS_Y_PLUS_2",     "DefinitionLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:1:9",     "InvocationLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:10:5",     "ASTKind" : "Stmt",     "TypeSignature" : "",     "InvocationDepth" : 0,     "NumASTRoots" : 1,     "NumArguments" : 2,     "HasStringification" : false,     "HasTokenPasting" : false,     "HasAlignedArguments" : false,     "HasSameNameAsOtherDeclaration" : false,     "IsExpansionControlFlowStmt" : false,     "DoesBodyReferenceMacroDefinedAfterMacro" : false,     "DoesBodyReferenceDeclDeclaredAfterMacro" : false,     "DoesBodyContainDeclRefExpr" : false,     "DoesSubexpressionExpandedFromBodyHaveLocalType" : false,     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro" : false,     "DoesAnyArgumentHaveSideEffects" : false,     "DoesAnyArgumentContainDeclRefExpr" : false,     "IsHygienic" : true,     "IsDefinitionLocationValid" : true,     "IsInvocationLocationValid" : true,     "IsObjectLike" : false,     "IsInvokedInMacroArgument" : false,     "IsNamePresentInCPPConditional" : false,     "IsExpansionICE" : true,     "IsExpansionTypeNull" : false,     "IsExpansionTypeAnonymous" : false,     "IsExpansionTypeLocalType" : false,     "IsExpansionTypeDefinedAfterMacro" : false,     "IsExpansionTypeVoid" : false,     "IsAnyArgumentTypeNull" : true,     "IsAnyArgumentTypeAnonymous" : false,     "IsAnyArgumentTypeLocalType" : true,     "IsAnyArgumentTypeDefinedAfterMacro" : false,     "IsAnyArgumentTypeVoid" : false,     "IsInvokedWhereModifiableValueRequired" : true,     "IsInvokedWhereAddressableValueRequired" : true,     "IsInvokedWhereICERequired" : false,     "IsAnyArgumentExpandedWhereModifiableValueRequired" : false,     "IsAnyArgumentExpandedWhereAddressableValueRequired" : true,     "IsAnyArgumentConditionallyEvaluated" : false,     "IsAnyArgumentNeverExpanded" : false,     "IsAnyArgumentNotAnExpression" : false  }
// Invocation	{     "Name" : "X_PLUS_Y_PLUS_2",     "DefinitionLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:1:9",     "InvocationLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:11:5",     "ASTKind" : "Stmt",     "TypeSignature" : "",     "InvocationDepth" : 0,     "NumASTRoots" : 1,     "NumArguments" : 2,     "HasStringification" : false,     "HasTokenPasting" : false,     "HasAlignedArguments" : false,     "HasSameNameAsOtherDeclaration" : false,     "IsExpansionControlFlowStmt" : false,     "DoesBodyReferenceMacroDefinedAfterMacro" : false,     "DoesBodyReferenceDeclDeclaredAfterMacro" : false,     "DoesBodyContainDeclRefExpr" : false,     "DoesSubexpressionExpandedFromBodyHaveLocalType" : false,     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro" : false,     "DoesAnyArgumentHaveSideEffects" : false,     "DoesAnyArgumentContainDeclRefExpr" : false,     "IsHygienic" : true,     "IsDefinitionLocationValid" : true,     "IsInvocationLocationValid" : true,     "IsObjectLike" : false,     "IsInvokedInMacroArgument" : false,     "IsNamePresentInCPPConditional" : false,     "IsExpansionICE" : true,     "IsExpansionTypeNull" : false,     "IsExpansionTypeAnonymous" : false,     "IsExpansionTypeLocalType" : false,     "IsExpansionTypeDefinedAfterMacro" : false,     "IsExpansionTypeVoid" : false,     "IsAnyArgumentTypeNull" : true,     "IsAnyArgumentTypeAnonymous" : false,     "IsAnyArgumentTypeLocalType" : true,     "IsAnyArgumentTypeDefinedAfterMacro" : false,     "IsAnyArgumentTypeVoid" : false,     "IsInvokedWhereModifiableValueRequired" : true,     "IsInvokedWhereAddressableValueRequired" : true,     "IsInvokedWhereICERequired" : false,     "IsAnyArgumentExpandedWhereModifiableValueRequired" : false,     "IsAnyArgumentExpandedWhereAddressableValueRequired" : true,     "IsAnyArgumentConditionallyEvaluated" : false,     "IsAnyArgumentNeverExpanded" : false,     "IsAnyArgumentNotAnExpression" : false  }
// Invocation	{     "Name" : "SUM__ONE_X_Y_X_Y_ONE",     "DefinitionLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:3:9",     "InvocationLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:12:5",     "ASTKind" : "Stmt",     "TypeSignature" : "",     "InvocationDepth" : 0,     "NumASTRoots" : 1,     "NumArguments" : 2,     "HasStringification" : false,     "HasTokenPasting" : false,     "HasAlignedArguments" : false,     "HasSameNameAsOtherDeclaration" : false,     "IsExpansionControlFlowStmt" : false,     "DoesBodyReferenceMacroDefinedAfterMacro" : false,     "DoesBodyReferenceDeclDeclaredAfterMacro" : false,     "DoesBodyContainDeclRefExpr" : false,     "DoesSubexpressionExpandedFromBodyHaveLocalType" : false,     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro" : false,     "DoesAnyArgumentHaveSideEffects" : false,     "DoesAnyArgumentContainDeclRefExpr" : false,     "IsHygienic" : true,     "IsDefinitionLocationValid" : true,     "IsInvocationLocationValid" : true,     "IsObjectLike" : false,     "IsInvokedInMacroArgument" : false,     "IsNamePresentInCPPConditional" : false,     "IsExpansionICE" : true,     "IsExpansionTypeNull" : false,     "IsExpansionTypeAnonymous" : false,     "IsExpansionTypeLocalType" : false,     "IsExpansionTypeDefinedAfterMacro" : false,     "IsExpansionTypeVoid" : false,     "IsAnyArgumentTypeNull" : true,     "IsAnyArgumentTypeAnonymous" : false,     "IsAnyArgumentTypeLocalType" : true,     "IsAnyArgumentTypeDefinedAfterMacro" : false,     "IsAnyArgumentTypeVoid" : false,     "IsInvokedWhereModifiableValueRequired" : true,     "IsInvokedWhereAddressableValueRequired" : true,     "IsInvokedWhereICERequired" : false,     "IsAnyArgumentExpandedWhereModifiableValueRequired" : false,     "IsAnyArgumentExpandedWhereAddressableValueRequired" : true,     "IsAnyArgumentConditionallyEvaluated" : false,     "IsAnyArgumentNeverExpanded" : false,     "IsAnyArgumentNotAnExpression" : false  }
// Invocation	{     "Name" : "SUM__ONE_X_Y_X_Y_ONE",     "DefinitionLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:3:9",     "InvocationLocation" : "/maki/tests/malformed_args_arg_not_begin_or_end.c:13:5",     "ASTKind" : "Stmt",     "TypeSignature" : "",     "InvocationDepth" : 0,     "NumASTRoots" : 1,     "NumArguments" : 2,     "HasStringification" : false,     "HasTokenPasting" : false,     "HasAlignedArguments" : false,     "HasSameNameAsOtherDeclaration" : false,     "IsExpansionControlFlowStmt" : false,     "DoesBodyReferenceMacroDefinedAfterMacro" : false,     "DoesBodyReferenceDeclDeclaredAfterMacro" : false,     "DoesBodyContainDeclRefExpr" : false,     "DoesSubexpressionExpandedFromBodyHaveLocalType" : false,     "DoesSubexpressionExpandedFromBodyHaveTypeDefinedAfterMacro" : false,     "DoesAnyArgumentHaveSideEffects" : false,     "DoesAnyArgumentContainDeclRefExpr" : false,     "IsHygienic" : true,     "IsDefinitionLocationValid" : true,     "IsInvocationLocationValid" : true,     "IsObjectLike" : false,     "IsInvokedInMacroArgument" : false,     "IsNamePresentInCPPConditional" : false,     "IsExpansionICE" : true,     "IsExpansionTypeNull" : false,     "IsExpansionTypeAnonymous" : false,     "IsExpansionTypeLocalType" : false,     "IsExpansionTypeDefinedAfterMacro" : false,     "IsExpansionTypeVoid" : false,     "IsAnyArgumentTypeNull" : true,     "IsAnyArgumentTypeAnonymous" : false,     "IsAnyArgumentTypeLocalType" : true,     "IsAnyArgumentTypeDefinedAfterMacro" : false,     "IsAnyArgumentTypeVoid" : false,     "IsInvokedWhereModifiableValueRequired" : true,     "IsInvokedWhereAddressableValueRequired" : true,     "IsInvokedWhereICERequired" : false,     "IsAnyArgumentExpandedWhereModifiableValueRequired" : false,     "IsAnyArgumentExpandedWhereAddressableValueRequired" : true,     "IsAnyArgumentConditionallyEvaluated" : false,     "IsAnyArgumentNeverExpanded" : false,     "IsAnyArgumentNotAnExpression" : false  }
