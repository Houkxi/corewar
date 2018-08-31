# COREWAR

## Grade		125	/100

#### Mandatory	100	/100
#### Bonus		25	/25

## Description

The challenge was to create a compiler named asm or ```Assembler```, to rewrite a ```Champion``` into a language understood by the virtual machine called ```Corewar```.
It was a four-person group project, the ```Assembler``` was done by [cfavero](https://github.com/cfavero) and [myself](https://github.com/mmanley42) and ```Corewar``` was completed by [mconti](https://github.com/m-conti) [tbehra]()

The ```Champion``` is written in assembly syntax and compiled by the ```Assembler``` into a specificaly parsed binary file. It will then be sent to the corewar programm where its bytecode will be loaded into the circular memory of the VM. From that point a process specific to a  ```Champion``` will go through that memory space and execute the commands it finds.
The idea from there is to have a face off between different strategies created for each ```Champions```.  

## Assembler & Champion


The basic idea for a Champion process is to say at least once evry Cycle to die that it is alive.
A simple strategie is to ```Fork``` a process and send the new one to a loop that makes sure the Champion says ```Live```.
The second process will then be free to go on to execute the rest of the instructions, note that it still needs to say alive to not disapear. If no processes remain or none say ```Live``` for the ```Champion``` then he has lost the game. 

An example ```Champion``` :
```assembly
.name "BadAss4Lives"
.comment "
This is a multi line comment
To prove it works
"

start:
	st r1, :stock
	ld	%589913, r1 #%590053 for the end sort of || 589901
	st	r1, :start
	ldi %:stock, %0, r15
	st r15, :second_write
	ld %01, r2
	live %0
	fork %:prep
	ld %0, r3

	aff r1
stock:
	live %0
	zjmp %-6

prep:
	ld %499, r13
	ld %34144755, r3
	fork %:ld_new_proc
	ld %0, r1
	zjmp %:next
	live %01

second_write:
	live %0
	ld %250, r12
	add r2, r12, r2
	ld %0, r1
	zjmp %:wrte

next:
	ld				%510,r2
	ld %34144755, r4
	ld %34144755, r5
	ld %34144755, r6
	ld %34144755, r6
	ld %34144755, r7
	ld %34144755, r8
	ld %:start, r9
	ld %8740996443, r11
	ld %0, r10
	zjmp %:wrte

ld_new_proc:
	live %0
	live %0
	ld %0, r1
	ld %506, r2
	ld %190055425, r3
	ld %190055681, r4
	ld %190055937, r5
	ld %190056193, r6
	ld %190056449, r7
	ld %190056705, r8
	ld %590099, r9
	ld %0, r1

wrte:
	sti r3, r1, r2
	zjmp %499

end:
	live %0
```
Here is the output of the binary file once the ```Assembler``` has compiled the previous ```Champion``` :

```console
00000000  00 ea 83 f3 42 61 64 41  73 73 34 4c 69 76 65 73  |....BadAss4Lives|
00000010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000080  00 00 00 00 00 00 00 00  00 00 01 1f 0a 54 68 69  |.............Thi|
00000090  73 20 69 73 20 61 20 6d  75 6c 74 69 20 6c 69 6e  |s is a multi lin|
000000a0  65 20 63 6f 6d 6d 65 6e  74 0a 54 6f 20 70 72 6f  |e comment.To pro|
000000b0  76 65 20 69 74 20 77 6f  72 6b 73 0a 00 00 00 00  |ve it works.....|
000000c0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000890  03 70 01 00 36 02 90 00  09 00 59 01 03 70 01 ff  |.p..6.....Y..p..|
000008a0  f4 0a a4 00 25 00 00 0f  03 70 0f 00 46 02 90 00  |....%....p..F...|
000008b0  00 00 01 02 01 00 00 00  00 0c 00 15 02 90 00 00  |................|
000008c0  00 00 03 10 40 01 01 00  00 00 00 09 ff fa 02 90  |....@...........|
000008d0  00 00 01 f3 0d 02 90 02  09 01 f3 03 0c 00 76 02  |..............v.|
000008e0  90 00 00 00 00 01 09 00  23 01 00 00 00 01 01 00  |........#.......|
000008f0  00 00 00 02 90 00 00 00  fa 0c 04 54 02 0c 02 02  |...........T....|
00000900  90 00 00 00 00 01 09 00  9c 02 90 00 00 01 fe 02  |................|
00000910  02 90 02 09 01 f3 04 02  90 02 09 01 f3 05 02 90  |................|
00000920  02 09 01 f3 06 02 90 02  09 01 f3 06 02 90 02 09  |................|
00000930  01 f3 07 02 90 02 09 01  f3 08 02 90 ff ff ff 56  |...............V|
00000940  09 02 90 09 01 05 5b 0b  02 90 00 00 00 00 0a 09  |......[.........|
00000950  00 53 01 00 00 00 00 01  00 00 00 00 02 90 00 00  |.S..............|
00000960  00 00 01 02 90 00 00 01  fa 02 02 90 0b 54 04 01  |.............T..|
00000970  03 02 90 0b 54 05 01 04  02 90 0b 54 06 01 05 02  |....T......T....|
00000980  90 0b 54 07 01 06 02 90  0b 54 08 01 07 02 90 0b  |..T......T......|
00000990  54 09 01 08 02 90 00 09  01 13 09 02 90 00 00 00  |T...............|
000009a0  00 01 0b 54 03 01 02 09  01 f3 01 00 00 00 00     |...T...........|
000009af
```
The first part of the file will be the header, parsed in a specific amount of bytes, defined in the [op.h](https://github.com/mmanley42/corewar/blob/master/asmb/includes/op.h). After the comment comes the instructions.

The ```Assembler``` cannot leak, has a wide range of errors to deal with but must not quit unexpectedly (Segmentation fault, bus error, double free, etc).
No ```Assembler``` will look alike seeing that the error management is left to one owns discretion.

## Corewar

```Corewar``` is a virtual machine with a circular memory, of size defined in [op.h](https://github.com/mmanley42/corewar/blob/master/asmb/includes/op.h). Its role is to load the ```Champion``` into the arena (aka the memory block) and start up a process that will then read each octet and tell the VM which commands to execute. This will useally happen with a great number of processes at once.

![Memory Block](https://github.com/mmanley42/ressources/blob/master/memory_block.gif)

Same as the ```Assembler``` the program cannot quit unexpectedly and will deal with the errors its own waym for expamplem it may choose to ignore a none existing command or choose to quit properly.

The command line to execute ```Corewar``` :

```
Import image of command line
```

```
Import image of result
```

The final output of the program will tell us the victor of this battle.

## Bonus

**Assembler Bonus**

A binary visualizer, flag -bi :

![Binary image](https://github.com/mmanley42/ressources/blob/master/asm_output.gif)

It is the same output as the HexDump but with a color code to maje it much more readable.

**Corewar Bonus**

A visualizer, flag -v.
A complete information sheet of each process with its location in the VM :

![process sheet](https://github.com/mmanley42/ressources/blob/master/process_bonus.gif)

## Additional information

Download project.
*make* both programs (*asm*) & (*corewar*).
Give a ```Champion``` (*.s extension*) file to the ```Assembler``` it will return a file (*.cor extension*) which will be given to ```Corewar``` as such.
Now have fun and write your own ```Champion``` and beat them all !!
