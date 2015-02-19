# Mangy-Bat
Making command line navigation quicker

##Usage

Mangy bat allows quick navigation through PATH-like variables. 

For example to add a path to C:\Projects\example\src simply run 
```
mangy set exProj C:\Projects\example\src 
```
Once the variable has been set the following commands can be used

*Each command has a short form. This is contained within () in the table below*
*For example the short form of set is s*

Command              | Result
-------------        | -------------
```set(s) %1  %2```  | Sets variable with name **%1** to value **%2** 
```explore(e) %1```  | Opens an explorer window to the location of **%1**'s value
```delete(d) %1```   | Deletes the variable **%1**
```go(g) %1```       | CDs to the value of **%1**
```list(l)```        | Lists all variables
```run(r) %1```      | Used for a variable which points to an exe. The value of **%1** will be run

##Speed Tip##
One way to speed up typing is to create a symbolic link. I created one simply called m.bat
Using this along with command shortforms I can now type m g exProj as opposed to mangy go exProj

A symbolic link can be created using the mklink command
```
mklink m.bat mangy.bat
```

