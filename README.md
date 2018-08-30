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

![My image](https://github.com/mmanley42/corewar/blob/master/BadAss4Lives.s)

Here is an output of the binary file once the ```Assembler``` has compiled the ```Champion``` :

```
Import image of the Hexdump
```
The first part of the file will be the header, parsed in a specific amount of bytes, defined in the [op.h](https://github.com/mmanley42/corewar/blob/master/asmb/includes/op.h). After the comment comes the instructions.

The ```Assembler``` cannot leak, has a wide range of errors to deal with but must not quit unexpectedly (Segmentation fault, bus error, double free, etc).
No ```Assembler``` will look alike seeing that the error management is left to one owns discretion.

## Corewar

```Corewar``` is a virtual machine with a circular memory, of size defined in [op.h](https://github.com/mmanley42/corewar/blob/master/asmb/includes/op.h). Its role is to load the ```Champion``` into the arena (aka the memory block) and start up a process that will then read each octet and tell the VM which commands to execute. This will useally happen with a great number of processes at once.

```
Import image of the memory block with multiple processes
```

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

```
Import image binary output
```
It is the same output as the HexDump but with a color code to maje it much more readable.

**Corewar Bonus**

A visualizer, flag -v :

```
Import image of VM
```

A complete information sheet of each process with its location in the VM :

```
Import image of the rapsheet
```

## Additional information

Download project
*make* both programs (*asm*) & (*corewar*)
Give a ```Champion``` (*.s extension*) file to the ```Assembler``` it will return a file (*.cor extension*) which will be given to ```Corewar``` as such.
Now have fun and write your own ```Champion``` and beat them all !!
