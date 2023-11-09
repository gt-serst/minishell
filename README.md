# minishell
## read the command line
#### first of all, get the command line from arguments and store it in a string using readline from stdio library.
## tokenizer
#### each chars of the command are scanned, the tokenizer function does its work. While loop with three conditions works well, first scenario chars are whitespaces and it skipped. Second scenario, chars are separators (metacharacters in shell langage), it follows an identification process and then stored in a linked list with all tokens. Last scenario, chars are identifiers (any other chars) and it directly stored in a linked list with all tokens. Separators will receive different types of tokens (great, less, pipe,...) and identifiers only receive identifier type.
#### at that time, first cleaning is done. Whitespaces are skipped, each part of the command are classified into a type of token and basic syntax errors are handled (e.g. ";" not handled by bash).
## parser
#### By passing over each token two possible scenarios: if it is an identifier token then its value is returned. If it's an operator token then we enter a recursive loop with the same condition previously checked as the stop condition (while it's an operator). In the while loop, we move on to the next token and call the recursive function again until the stop condition is no longer valid. The recursive function returns the value of the right command to be executed with the left command. We use an AST to travel into pipes and simple cmds.
## expander
#### First part handle simple quotes, double quotes (remove if necessary) and environment variables (display value if necessary). Second part take care of redirections (input, output, append and heredoc).
## execution
## built-ins
## signals
## errors management
