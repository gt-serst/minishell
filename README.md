# minishell
## read the command line
#### first of all, get the command line from arguments and store it in a string using readline from stdio library.
## tokenizer
#### each chars of the command are scanned, the tokenizer function does its work. While loop with three conditions works well, first scenario chars are whitespaces and it skipped. Second scenario, chars are separators (metacharacters in shell langage), it follows an identification process and then stored in a linked list with all tokens. Last scenario, chars are identifiers (any other chars) and it directly stored in a linked list with all tokens. Separators will receive different types of tokens (great, less, pipe, paren,...) and identifiers only receive identifier type.
#### at that time, first cleaning is done. Whitespaces are skipped, each part of the command are classified into a type of token and basic syntax errors are handled (e.g. "||", ">>>" or typo mistakes).
#### last thing to handle is quotes
## parser
#### By passing over each token two possible scenarios: if it is an identifier token then its value is returned. If it's an operator token and the value of its precedence is greater than or equal to that of the previous element, then we enter a recursive with the same condition previously checked as the stop condition. In the while loop, we move on to the next token, increment the min precedence and call the recursive function again until the stop condition is no longer valid. At this point, the operator with the highest precedence has been found. The recursive function returns the value of the right command to be executed with the left command.
## expander
#### envars
#### redirections
## executor
## built-ins
## signals
