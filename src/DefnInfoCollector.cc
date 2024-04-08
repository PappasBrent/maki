#include "DefnInfoCollector.hh"

namespace cpp2c {

DefnInfoCollector::DefnInfoCollector(clang::ASTContext &Ctx)
        : SM(Ctx.getSourceManager())
        , LO(Ctx.getLangOpts()) {
}

void DefnInfoCollector::MacroDefined(const clang::Token &MacroNameTok,
                                           const clang::MacroDirective *MD) {
        std::string Name = clang::Lexer::getSpelling(MacroNameTok, SM, LO);
        MacroNamesDefinitions.push_back({ Name, MD });
}

void DefnInfoCollector::MacroUndefined(
        const clang::Token &MacroNameTok, const clang::MacroDefinition &MD,
        const clang::MacroDirective *Undef) {
        auto Name = clang::Lexer::getSpelling(MacroNameTok, SM, LO);
        InspectedMacroNames.insert(Name);
}

void DefnInfoCollector::Defined(const clang::Token &MacroNameTok,
                                      const clang::MacroDefinition &MD,
                                      clang::SourceRange Range) {
        auto Name = clang::Lexer::getSpelling(MacroNameTok, SM, LO);
        InspectedMacroNames.insert(Name);
}

void DefnInfoCollector::Ifdef(clang::SourceLocation Loc,
                                    const clang::Token &MacroNameTok,
                                    const clang::MacroDefinition &MD) {
        auto Name = clang::Lexer::getSpelling(MacroNameTok, SM, LO);
        InspectedMacroNames.insert(Name);
}

void DefnInfoCollector::Ifndef(clang::SourceLocation Loc,
                                     const clang::Token &MacroNameTok,
                                     const clang::MacroDefinition &MD) {
        auto Name = clang::Lexer::getSpelling(MacroNameTok, SM, LO);
        InspectedMacroNames.insert(Name);
}

} // namespace cpp2c
