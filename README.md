# minishell
## read the command line
#### first of all, get the command line from arguments and store it in a string using readline from stdio library
## lexer
#### each char of the command are scanned, the tokenizer function does it work. While loop with three conditions works well, first scenario the char is a whitespace and it skipped. Second scenario, the char looks like a separator (metacharacter in shell langage) and it is indentified and then stored in a linked list with all tokens. Last scenario, it is a identifier (any other chars) and it directly stored in a linked list with all tokens.
## parser
####
