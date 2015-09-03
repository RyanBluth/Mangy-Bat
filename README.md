# Mangy-Bat
Making command line navigation quicker

##Usage

Mangy bat allows quick navigation through PATH-like variables. 

For example to add a path to C:\Projects\example\src simply run 
```
mangy set exProj C:\Projects\example\src 
```
###The {KEY} Syntax

It is possible to use the {KEY} syntax to reference a set value. For example if the value of x is "C:\Stuff\Z\Y\X" then {x} would be expanded to C:\Stuff\Z\Y\X
This is useful when building chain commands. For example if a chain command were being written to copy a file to a couple common locations it would be easy to write
```
m s copy_ex "copy {x}/file.txt {y}/file.txt, copy {x}/file.txt {z}/file.txt"
```

###The - Syntax

It is possible to pass arguments into commands. These arguments are denoted by entering -- and then declaring the arguments. For example if a chain command is created we may want to use it multiple times with some variation.
Referring back to the example in the previous section we may re-write our copy chain command to 
```
m s copy_ex "copy $1 $2 $3"
```
We could then run the command like so 
```
m c copy_ex -- {x}/file.txt {y}/file.txt {z}/file.txt
```
While this isn't a great example it shows how arguments can add flexability to commands. It also shows a better use of the {KEY} syntax

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
```chain(c) %1```    | Used to run a chain of comma seperated commands(The value of **%1** wiil be run). These commands can be set using the set command. For example a command to add all changes in git and then commit them might look like **mangy set git_C "git add --all, git commit -m $1"**. It would then be run like so **mangy chain git_c - "This is a message for $1"**. NOTE the chain command accepts the -fr flag which specifies which directory to run the commands from. You may take advantage of the **{key}** syntax to make this more efficent. For example if I had a key value pair of **ma = C:\Projects\MangyBat** and wanted to run **git_c** in that directory I could run the command as follows **mangy chain git_c -fr {ma} - "This is a message for $1"**. **{ma}** will be expanded to C:\Projects\MangyBat. 

##Speed Tip##
One way to speed up typing is to create a symbolic link. I created one simply called m.bat
Using this along with command shortforms I can now type m g exProj as opposed to mangy go exProj

A symbolic link can be created using the mklink command
```
mklink m.bat mangy.bat
```

