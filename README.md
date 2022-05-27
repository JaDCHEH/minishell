# minishell

This project is about creating a simple shell.

Yes, our own little bash.

# Final Grade (101/125)

Mandatory (100/100)

Bonus (1/25)

## how to use

simply using `make` will create a `minishell` executable 

just run it with :
```
./minishell
```

##Supported options

Minishell runs executables from an absolute, relative or environment PATH (`/bin/ls` or `ls`),

including arguments or options. `'` and `"` work the same as bash, except for multiline commands.

You can use pipes `|` as well as use redirections `>` `>>` `<` and heredoc `<<`.

Environment variables are handled, like `$HOME`, including the return code `$?`.

Finally, you can use `Ctrl-C` to interrupt and `Ctrl-\` to quit a program, as well as `Ctrl-D` to throw an EOF, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable,

we re-coded them directly. It's the case for `echo`, `pwd`, `cd`, `env`, `export`, `unset` and `exit`.

##credit

This team project was done with [ie_laabb](https://github.com/elyass546)

I was responsible for the parsing, argument checking, execution, redirection and piping.

ie_laabb took care of the environment variables, built-in functions, and signal handling.
