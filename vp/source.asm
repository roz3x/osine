# this is comment 


# the virtual process is following howard architecture 
# machine has 10 registers 
# 255 byte long instructions buffer 
# 255 byte long data buffer 

# the data can be set by SET command 
# the register values can be set by the MOV command



# format for SET command
# SET `LOCATION` `VALUE`
# loction can be 0-255 and value can be 0-255

SET 0 1
SET 1 20
SET 2 38
SET 3 39
SET 4 55
SET 5 100
SET 6 101
SET 7 111


# format for mov command 
# MOV 	`REGS NUMBER` `VALUE` 
# REGS can be 1-10 and value can be 0-255

# REGS 1 contains the upper bound for the binary search array
# upper bound
MOV 1 8

# REGS 7 also contains the length but it is static as for the  REGS 1 will keep on changing 
# with the calculations 
MOV 7 8


# REGS 2 will contain the lower bound for the binary serach
MOV 2 0


# REGS 3 will contain the search value 
MOV 3 100


# PRINT will print the first [RGES 7] registers and storage 
PRINT

# XCMP is a special command specific for to binary serach 
# it works as the comaring part in the binary search 
#     REGS 1 < REGS 2  ; REGS 4 = 0
#     DATA[REGS 1 + REGS 2 / 2 ]  == REGS 3; REGS 4 = 1
#     DATA[REGS 1 + REGS 2 / 2 ]  >  REGS 3; REGS 4 = 2
#     DATA[REGS 1 + REGS 2 / 2 ]  <  REGS 3; REGS 4 = 3 

XCMP



# format for JMP command 
# JMP `value`
# JMP is a  command to jump -val steps in instruction pointer 
# if REGS 4 is 2 or 3 , and it will break if it has REGS 4 as 1 or 0;

JMP


# EXIT command for gracefully stoping the machine
EXIT
