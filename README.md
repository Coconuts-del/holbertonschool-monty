<div style="text-align:center"><img src="https://zupimages.net/up/23/36/xjje.png" /></div>


## `Description`
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


### `C - Stacks, Queues - LIFO, FIFO` :dart:

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables


### `Requirements`     :floppy_disk:


```
git clone https://github.com/Coconuts-del/holbertonschool-monty.git
```

|               Compilation & Output                |
| :------------------------------------------------:|
|gcc -Wall -Werror -Wextra -pedantic *.c -o monty   |
|Any output must be printed on stdout               |
|Any error message must be printed on stderr        | 
|Any error message must be printed on stderr        |


### `Script files`
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
```

### `How to run Monty program`

Here we take as example the file 00.m from bytecodes directory

```
$ ./monty bytecodes/00.m
3
2
1
```


##### `Resources`   :earth_africa:
* [*How do I use extern to share variables between source files in C?:*] (https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
* [*GOOGLE:*] (https://www.google.com/search?channel=fs&client=ubuntu-sn&q=google)

## `Authors`
* [**Abdelkader AOUAR**](https://github.com/powerofcode2023)
* [**Claudine Sillam**](https://github.com/Coconuts-del)
* [**Jean-Luc Bilo**](https://github.com/Luckisback)
