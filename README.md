# Stacked
A simple esoteric programming language, inspired from brainfuck. The only data structure that can be used are stacks.
## Syntax
The syntax of ** Stacked ** is simple. It contains the following isntructions:  
* `% <name>` - creates a new stacks with the name `<name>`
* `- <name>` - pops the top of the stack named `<name>`
* `+ <name> <value>` - pushes the `<value>` into the stack named `<name>`
* `" <name>` - this instruction acts like pop, but it returns a value, and it changes the top to be the next element after the last pop. It works on the stack called `<name>`
* `? <name>` - this instruction resets the top pointer of the previous instruction. It works on the stack called `<name>`
Blocks:  
 * The only block available is math block. The math block is used to process an expression. A math block's syntax is: `( "expression" )`. The only instruction usable inside this block is `"`. An example of this block being used is:
 ```
 + stack ((70 - 50) + 30 / (" stack))
 ```
Each operation inside a math block (+, -, /, *) accepts only 2 terms. `(50 * 50 * 50)` is invalid for instance. But `(50 * (50 * 50))` is valid since `(50 * 50)` is considered as a single term, since it's a math block.  
__In stacked, value referes to what a math block returns. Numeric values/constants/what `"` returns cannot be used as input for `+`__
The following is invalid:
```
+ stack 50
+ stack " anotherStack
```
It should be:
 ```
 + stack (50)
 + stack (" anotherStack)
 ```
 __In parsing, there is no support for negative numbers, instead of writing `-50` the `(0 - 50)` should be written.__
 
 There is no support for printing. The only ways to print are by using the instruction `"` on a line. Or a math block on a line.  

Upcoming features:
  * a proper way to print
  * if and while blocks
