package;

import cpp.Lib;
import haxe.Log;
import Sys;
import sys.FileStat;
import sys.FileSystem;
import sys.io.File;
import sys.io.FileOutput;
import sys.io.Process;
import haxe.Json;

/**
 * ...
 * @author Ryan Bluth
 */

typedef PropertySet = {
	var propsArr:Array<Property>;
}
 
typedef Property = {
	var name:String;
	var value:String;
}

typedef Command = {
	var command:String;
	var args:Array<String>;
	var dashArgs:Map<String, String>;
	var extras:Array<String>;
}
 
class Main 
{
	static inline var go:String         = "go";
	static inline var go_s:String       = "g";
	static inline var set:String        = "s"; 
	static inline var set_s:String      = "set"; 
	static inline var explore:String    = "explore"; 
	static inline var explore_s:String  = "e"; 
	static inline var list:String       = "list"; 
	static inline var list_s:String     = "l"; 
	static inline var run:String        = "run"; 
	static inline var run_s:String      = "r"; 
	static inline var delete:String     = "delete"; 
	static inline var delete_s:String   = "d"; 
	
	static inline var propsFile:String = "props.mangy";
	
	static var props:PropertySet;
	
	static var globalCommand:Command;
	
	static var args:Array<String>;
	
	static var currentPath:String;
	
	static function main() 
	{
		
		props = {
			propsArr : new Array()
		}	
		
		if(FileSystem.exists(getFilePath(propsFile))){
			var contents:String = File.getContent(getFilePath(propsFile));
			if(contents.length > 0){
				var rawProps:Dynamic = Json.parse(contents);
				for (i in 0...rawProps.propsArr.length) {
					var p:Property = {
						name : rawProps.propsArr[i].name.toString(),
						value: rawProps.propsArr[i].value.toString()
					}
					props.propsArr.push(p);
				}
			}
		}else{
			var file:FileOutput = File.write(getFilePath(propsFile), false);
			file.writeString("");
			file.close();
		}
		
		globalCommand = processMangyArguments(Sys.args());
		
		args = Sys.args();
		if (args.length > 1) {
			currentPath = args[0];
			Sys.setCwd(currentPath);
			args.shift();
			doCommand(args[0]);
		}else {
			Sys.println("\n*************");
			Sys.println("* Mangy Bat *");
			Sys.println("*************\n");
			Sys.println("set(s)       %1 %2  - Create/update variable with name %1 and value %2 ");
			Sys.println("go(g)        %1     - CD to the specified variable(%1)");
			Sys.println("delete(d)    %1     - Delete the specified variable(%1)");
			Sys.println("list(l)             - List all variables");
			Sys.println("explore(e)   %1     - Open an explorer window at the specified variable(%1)");
			Sys.println("run(r)       %1     - Run the specfied variable - An exe for example(%1)");
			Sys.println("Auto Select  %1     - If one of the above is not specified Mangy Bat will attempt to ");
			Sys.println("                      determine the best action. If the variable is a Path go will be run,");
			Sys.println("                      otherwise the value of the variable will be run");
			Sys.println("-- Syntax --");
			Sys.println("{VAR} -- Will be expanded to the value of VAR");
			Sys.println("$1, $2, $3... -- Can be used in run commands"); 
			Sys.println("    Ex. (Creation) mangy set com \"git commit -m $1\"");
			Sys.println("    Ex. (Usage)    mangy run com - \"This is a message for $1\"");
		}
	}
	
	static function doCommand(command:String) {
		// fr argument sets the directory to run the command from
		if (globalCommand.dashArgs.exists("fr")) {
			Sys.setCwd(globalCommand.dashArgs.get("fr"));
		}
		
		switch(command){
			case go | go_s:
				if (args.length > 1) {
					var path:String = null;
					for (p in props.propsArr) {
						if (p.name == args[1].toString()) {
							path = p.value;
							break;
						}
					}
					Sys.println("cd " + path);
				}
			case set | set_s:
				if (args.length > 2) {
					var prop:Property = {
						name  : args[1].toString(),
						value : args[2].toString()
					};
					if (prop.value.toLowerCase() == "here") {
						prop.value = currentPath;
					}
					var exists:Bool = false;
					for (p in props.propsArr) {
						if (p.name == prop.name) {
							p.value = prop.value;
							exists = true;
							break;
						}
					}
					if (!exists) {
						props.propsArr.push(prop);
					}
					writeProps(props);
				}
			case explore | explore_s:
				if (args.length > 1) {
					var path:String = null;
					if (args[1].toLowerCase() == "here") {
						path = currentPath;
					}else{
						for (p in props.propsArr) {
							if (p.name == args[1].toString()) {
								path = p.value;
								break;
							}
						}
					}
					if(path != null){
						Sys.command("explorer", [path]);
					}
				}
				
			case list | list_s:
				
				var longest:Int = 0;
				var paths:Array<Dynamic> = [];
				var others:Array<Dynamic> = [];
				var pathsString:String = "";
				var othersString:String = "";
				Sys.println("\n__________Paths___________\n");
				for (p in props.propsArr) {
					if (p.name.length > longest) {
						longest = p.name.length;
					}
					if(FileSystem.exists(p.value)){
						paths.push( { name:p.name,  value:p.value} );
					}else {
						others.push( { name:p.name,  value:p.value } ); 
					}
				}
				
				for (val in paths) {
					var str:String = val.name;
					for (i in 0...cast((longest - val.name.length), Int)) {
						str += " ";
					}
					Sys.println(str + " : " + val.value);
				}
				Sys.println("\n__________Commands___________\n");
				for (val in others) {
					var str:String = val.name;
					for (i in 0...cast((longest - val.name.length), Int)) {
						str += " ";
					}
					Sys.println(str + " : " + val.value);
				}
				
			case delete | delete_s:
				if (args.length > 1) {
					var pr:Property = null;
					for (p in props.propsArr) {
						if (p.name == args[1].toString()) {
							pr = p;
							break;
						}
					}
					if (pr != null) {
						props.propsArr.remove(pr);
						Sys.println("Removed " + args[1] + "\n");
						writeProps(props);
					}
				}			
				
			case run | run_s:
				if (args.length > 1) {
					var out:String = null;
					
					for (p in props.propsArr) {
						if (p.name == args[1].toString()) {
							out = p.value;
							break;
						}
					}
					
					var vals:Array<String> = out.split(",");
					
					for (val in vals) {
						
						var command:Command = processCommandArguments(val);
						
						for (x in 0...command.args.length) {
							for (i in 0...globalCommand.extras.length) {
								command.args[x] = StringTools.replace(command.args[x], "$" + Std.string(i + 1), expandPropertyArg(globalCommand.extras[i]));
							}
							command.args[x] = expandPropertyArg(command.args[x]);
							command.args[x] = StringTools.replace(command.args[x], "'", "");
							command.args[x] = StringTools.replace(command.args[x], '"', "");
						}
						
						command.command = StringTools.replace(command.command, "'", "");
						command.command = StringTools.replace(command.command, '"', "");
						
						if (command != null) { 
							Sys.println("Running... " + command.command + " with arguments " + command.args.toString() + " from " + Sys.getCwd() + "\n");
							Sys.command(command.command, command.args);
						}
					}
				}else {
					Sys.println("Invalid number of arguments\n");
				}
			
			default:
				var matched = false;
				for (p in props.propsArr) {
					if (p != null && p.name == command) {
						command = p.value;
						matched = true;
						break;
					}
				}
				if (matched) {
					if (FileSystem.exists(command)) {
						args.unshift(go);
						doCommand(go);
					}else {
						args.unshift(run);
						doCommand(run);
					}
				}
		}
	}
	
	static function getFilePath(file:String):String{
		var split = Sys.executablePath().split("\\");
		var path:String = "";
		for (s in 0...split.length - 1) {
			path += split[s] + "\\";
		}
		path += file;
		return path;
	}
	
	static function writeProps(props:PropertySet) {
		if(props != null){
			var file:FileOutput = File.write(getFilePath(propsFile), false);
			file.writeString(Json.stringify(props));
			file.close();
		}
	}
	
	
	// Splits a command with arguments into an array
	static function processCommandArguments(command:String):Command {
		
		command = StringTools.trim(command);
		
		var quote:String = '';
		var args:Array<String> = [];
		var currentValue = "";
		
		for (c in 0...command.length) {
			if (command.charAt(c) == "'" || command.charAt(c) == '"') {
				if (quote == command.charAt(c)) {
					quote = '';
				}else {
					quote = command.charAt(c);
				}
			}
			
			if ((command.charAt(c) == ' ' && quote == '')) {
				args.push(currentValue);
				currentValue = "";
			}else if (c == command.length - 1) {
				currentValue += command.charAt(c);
				args.push(currentValue);
			}else {
				currentValue += command.charAt(c);
			}
		}
		
		var com:Command = {
			command  : args.shift(),
			args     : args,
			dashArgs : new Map<String, String>(),
			extras   : []
		}
		
		return com;
	}
	
	// Processes the argumetns passed into the system
	static function processMangyArguments(args:Array<String>):Command {
		var command:Command = {
			command  : args[0],
			args     : [],
			dashArgs : new Map<String, String>(),
			extras   : []
 		}
		
		var idx = 1;
	
		var extraIdx:Int = -1;
		
		for (i in 0...args.length) {
			if (extraIdx >= 0) {
				command.extras.push(expandPropertyArg(args[i]));
			}
			if (extraIdx == -1 && args[i] == "-") {
				extraIdx = i;
			}
		}
		
		while (idx < (extraIdx >= 0 ? extraIdx : args.length)) {
			var arg = args[idx];
			if (StringTools.startsWith(arg, "-") && (contains(arg, "'") || contains(arg, '"'))) {
				var keyVal:Array<String> = null;
				if (contains(arg, "'")) {
					keyVal = arg.split("'");
				}else if (contains(arg, '"')) {
					keyVal = arg.split('"');
				}
				if(keyVal != null && keyVal.length > 1){
					var key = keyVal[0];
					var value = keyVal[1];
					key   = StringTools.replace(key, "-", "");
					value = StringTools.replace(value, "'", "");
					value = StringTools.replace(value, '"', "");
					
					command.dashArgs.set(key, expandPropertyArg(value));
				}
			}
			if(StringTools.startsWith(arg, "-")){
				var key = StringTools.replace(arg, "-", "");
				if(idx + 1 < args.length){
					idx++;
					var value = args[idx];
					command.dashArgs.set(key, expandPropertyArg(value));
				}
			}else {
				command.args.push(expandPropertyArg(arg));
			}
			
			idx++;
		}
		return command;
	}
	
	static function contains(string:String, match:String):Bool {
		var count = 0;
		for (c in 0...string.length) {
			if (string.charAt(c) == match.charAt(count)) {
				count++;
			}else {
				count = 0;
			}
			if (count == match.length) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Attempts to expand a propery argument
	 * If it fails then it just returns the argument and logs a message
	 * 
	 * @param arg  The argument to expand 
	 * @return The expanded value
	 */
	static function expandPropertyArg(arg:String):String {
		var outArg:String = "";
		if (arg != null) {
			var vars:Array<String> = arg.split("{");
			for (va in vars) {
				if (contains(va, "}")) {
					var vas = va.split("}");
					va = vas[0];
					var matched:Bool = false;
					if (va != null) {
						for (p in props.propsArr) {
							if (p != null && p.name == va) {
								outArg += p.value;
								matched = true;
								break;
							}
						}
					}
					for (i in 1...vas.length) {
						outArg += vas[i];
					}
					if (!matched) {
						Sys.println("Could not expand " + arg);
					}
				}else {
					outArg += va;
				}
			}
		}
		if (outArg.length > 0) {
			return outArg;
		}else{
			return arg;
		}
	}
}