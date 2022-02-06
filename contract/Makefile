CREATOR =  gcc -Wall -ansi -pedantic

# creating the final executable - contract
contract: contract.o
	$(CREATOR) -g contract.o -o contract


# Creating contract.o file
contract.o: contract.c
	$(CREATOR) -c contract.c -o contract.o