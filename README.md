Author: Shiladitya Mandal - 2010C6PS632G

Directory: airport/

Files:
airportMain.c
addcost.c
appendBaggageID.c
boarding_pass.c
How to compile program: Type to this directory and type: make
Then type: ./exe to execute

Description:
1. time - for storing flight time/return flight time/visa expiry/passport expiry time
hour,min

2. date - for entry date/flight date/return date
dd,mm,yy
3. flight - for flight/return flight
ticket_no - ticket number
flt_no - flight number
ftime - flight arrival time
fdate - flight date
dest - destination

4. passenger - for each passenger
valid - to set if passenger allowed in airport/ later invalidated for some purpose
ret_flag - if passenger has a return flight
flt - of type flight
ret_flt - of type flight ( for return flight)
passNo - passport number
pass_exp - passport expiry date
// other names are mnemonic


Bugs:
1. Even though I tried, I could not implement immigration. When PASSPORT validation fails, it works properly. I am having problems when VISA is called if PASSPORT is valid. I have commented the portion of the code of immigration
2. Although there is an element
3. For larger inputs, the program has not been tested. Correct output is not assured. In some places, it is assumed that a particular
   piece of code will finish executing in some specified sleep time.


How i would have solved them:
1. The immigration problem could have been easily solved by examining the sleep intervals for all the connected processes
3. To avoid the uncertainty and prevent sleeping for specified intervals till the next object in the cycle is ready for next input --
   I thought of using some asynchronous mechanism to interact between processes. For example, when baggage counter sends a passenger
   to the immigration stage, there should be some asynchronous signal from immigration that it has finished processing the last person
   so that baggage sends the next guy only after that.

