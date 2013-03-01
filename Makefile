exe: input.o luggage.o airportMain.c makepass.o checkcost.o addcost.o addid.o handbag.o
	gcc -o exe airportMain.c input.o luggage.o makepass.o checkcost.o addcost.o addid.o handbag.o
input.o: getInput.c
	gcc -c getInput.c -o input.o
handbag.o: checkMFbag.c luggage.o
	gcc -c checkMFbag.c -o handbag.o luggage.o
	
luggage.o: luggage_security.c 
	gcc -c luggage_security.c -o luggage.o
makepass.o: boarding_pass.c
	gcc -c boarding_pass.c -o makepass.o
	
checkcost.o: checkExtraCost.c
	gcc -c checkExtraCost.c -o checkcost.o
addcost.o: addcost.c
	gcc -c addcost.c -o addcost.o
addid.o: appendBaggageID.c
	gcc -c appendBaggageID.c -o addid.o

