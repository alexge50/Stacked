# Stacked  
A programming language made for fun, that uses aspects from brainfuck and assembly. Only stacks can be used.
## Syntax  
Stacked is similar to assembly, from a syntax stand point of view. Each line contains an instruction. But, unlike assembly there are a lot less instructions, and the instructions operate only on stacks.  
Each stacks is identified by its name, which is a string. The stack specific instructions are the following:  
*  `% <name>` - "new stack" creates a new stacks with the name <name> 
*  `- <name>` - "pop from stack" pops the top of the stack named <name> 
*  `+ <name> <value>` - "push to stack" pushes the <value> into the stack named <name> 
*  `" <name>` - "next element" this instruction acts like pop, but it returns a value, and it changes the top to be the next element after the last pop. It doesn't delete the current top. It works on the stack called <name> 
* ? <name> - "reset stack" this instruction resets the top pointer of the previous instruction. It works on the stack called <name> 

Apart from instructions that operate on stacks, there is one more instruction:
! <name> - "call signal", a signal is an internal functionality that is registered in `StackedLanguageManager`.  
		
```cpp
langManager.addSignal<OutputSignal>("print");
langManager.addSignal<InputSignal>("scan");
langManager.addSignal<SyscallSignal>("system");
//stacked.cpp – registering signals
```   
Signals can have their own stacks, for instance `print` has an `output` stack. The currently defined signals are:

* `print`: it prints `output` content in stdout
* `scan`: it gets stdin's content and copies it into `input` stack. The input stacks ends in `-1`
* `system`: it makes a system call with the content of `system`

***Since the signals uses stacks, the elements are popped in the reverse order they were pushed.***
So, to print `Hello, World!`, it is needed to push the elements in the reversed order: `!dlroW ,olleH`. In stacked, it is as follows:
```
+ output (10)

+ output (33)
+ output (100)
+ output (108)
+ output (114)
+ output (111)
+ output (87)

+ output (32)

+ output (44)
+ output (111)
+ output (108)
+ output (108)
+ output (101)
+ output (72)

! print
```
There are no strings, so the only way to use string is to push the ascii codes. However this might be changed in the future.

In stacked, blocks are defined as more instruction (while or if) or an set of arithmetic operations (math block/mathematical expression)
math block - The math block is used to process an expression. A math block's syntax is: ( "expression" ). The only instruction usable inside this block is ". An example of this block being used is. **math block is the only way to return a value**: 
+ stack ((70 - 50) + 30 / (" stack))
Each operation inside a math block (+, -, /, *) accepts only 2 terms. (50 * 50 * 50) is invalid for instance. But (50 * (50 * 50)) is valid since (50 * 50) is considered as a single term, since it's a math block.
`<value>` refers to what a math block returns. Numeric values/constants/what " returns cannot be used as argument for +. The following is invalid:
+ stack 50
+ stack " anotherStack
It should be:
+ stack (50)
+ stack (" anotherStack)
In parsing, there is no support for negative numbers, instead of writing -50 the (0 - 50) should be written.


* `if block` – this is an if, and the block of instructions is executed only if the condition returns true:
The only types of conditions are comparison instructions, which compares the top (the top, not what `next element` returns) of 2 stacks. The available comparison instructions are:
`> leftStack rightStack` - which is the same as: `leftStack's top > rightStack's top`
`= leftStack rightStack` - which is the same as: `leftStack's top = rightStack's top`
`< leftStack rightStack` - which is the same as: `leftStack's top < rightStack's top`

The if block looks as follows:
	
 ```	
	{ : condition :
 	  instructions
	}
```
* `while block` - the syntax for while is as follows: 
	The theory behind while block is the same as if's block, but instead of executed once if the condition is met, it executes until the condition is not met anymore
	the while block looks as follows:

```
	[ : condition :
 	  instructions
	]
```

Upcoming features:
* an instruction to check if a stack is not empty
* function calls (ie. call a set of instruction from another file) 
* a better error log  
