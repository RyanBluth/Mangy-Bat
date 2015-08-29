package;

import cpp.Lib;
import Sys;
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

typedef DashArg = {
	var key:String;
	var value:String;
}

typedef Command = {
	var command:String;
	var args:Array<String>;
	var dashArgs:Array<DashArg>;
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
	static inline var path:String       = "path";
	static inline var path_s:String     = "p"; 
	static inline var runChain:String   = "run_chain";
	static inline var runChain_s:String = "rc";
	
	static inline var propsFile:String = "props.mangy";
	static inline var logFile:String   = "log.txt";
	
	static var props:PropertySet;
	
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
		
		//Clear log
		log("", true);
		
		logLine(Std.string(processMangyArguments()));
		
		var args:Array<String>;
		args = Sys.args();
		if (args.length > 0) {
			switch(args[0]){
				case go | go_s:
					if (args.length > 1) {
						var path:String = null;
						for (p in props.propsArr) {
							if (p.name == args[1].toString()) {
								path = p.value;
								break;
							}
						}
						Sys.print("cd " + path);
					}
				case set | set_s:
					if (args.length > 2) {
						var prop:Property = {
							name  : args[1].toString(),
							value : args[2].toString()
						};
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
						for (p in props.propsArr) {
							if (p.name == args[1].toString()) {
								path = p.value;
								break;
							}
						}
						if(path != null){
							Sys.command("explorer", [path]);
						}
					}
					
				case list | list_s:
					var out:String = "\n__________Items___________\n";
					for (p in props.propsArr) {
						out += p.name + " : " + p.value + "\n";
					}
					log(out);
					
				case run | run_s:
					if (args.length > 1) {
						var out:String = null;
						var prop = null;
						for (p in props.propsArr) {
							if (p.name == args[1].toString()) {
								out = p.value;
								prop = p;
								break;
							}
						}
						
						if (out != null) {
							for (c in 0...out.length) {
								if (out.charAt(c) == ',') {
									log(prop.name + " appears to be a chain command, chain commands must be run using run_chain or rc\n");
									break;
								}
							}
							
							var command = processCommandArguments(out);
							
							log("Running... " + command.command + " with arguments " + command.args.toString() + " from " + Sys.getCwd() + "\n");
							Sys.command(command.command, command.args);
						}
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
							log("Removed " + args[1] + "\n");
							writeProps(props);
						}
					}
					
				case path | path_s:
					if (args.length > 1) {
						var value:String = null;
						for (arg in args) {
							if (arg == "-p" || arg == "-property") {
								for (p in props.propsArr) {
									if (p.name == args[1]) {
										value = p.value;
										break;
									}
								}	
							}
						}
						
						if (value == null) {
							value = args[1];
						}
						
						var path:String = Sys.getEnv("PATH");

						if (path != null) {
							Sys.command("setx path \"%PATH%;" + value + " /m"); 
							Sys.command("path=%PATH%;" + value); 
						}
						
						log(Sys.getEnv("PATH") + "\n");
					}
					
				/**
				 * Possible Arguments 
				 * 
				 * -fr = Which directoty to run from
				 */	
				case runChain | runChain_s:
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
							
							var command = processCommandArguments(val);
							
							if (command != null) { 
								log("Running... " + command.command + " with arguments " + command.args.toString() + " from " + Sys.getCwd() + "\n");
								Sys.command(command.command, command.args);
							}
						}
					}else {
						log("Invalid number of arguments\n");
					}
			}
		}else {
			Sys.println("Argument expected.");
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
	
	static function log(content:String, clear:Bool = false) {		
		var file:FileOutput = null;
		if(clear){
			file = File.write(getFilePath(logFile), false);
		}else {
			file = File.append(getFilePath(logFile), false);
		}
		file.writeString(content);
		file.close();
	}
	
	static function logLine(content:String, clear:Bool = false) {
		log(content + "\n", clear);
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
			dashArgs : null
		}
		
		return com;
	}
	
	// Processes the argumetns passed into the system
	static function processMangyArguments():Command {
		var args = Sys.args();
		var command:Command = {
			command  : args[0],
			args     : [],
			dashArgs : []
 		}
		
		var idx = 1;
		
		while (idx < args.length) {
			
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
					
					command.dashArgs.push({
						key   : key,
						value : expandPropertyArg(value)
					});
				}
			}else if(StringTools.startsWith(arg, "-")){
				var key = StringTools.replace(arg, "-", "");
				if(idx + 1 < args.length){
					idx++;
					var value = args[idx];
					command.dashArgs.push({
						key   : key,
						value : expandPropertyArg(value)
					});
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
		if (arg != null && arg.length > 2) {
			if (contains(arg, "{") && contains(arg, "}")) {
				var valOne = null;
				if (StringTools.startsWith(arg, "{")) {
					valOne = arg.substring(1, arg.length);
				}else {
					valOne = arg.split("{")[1];
				}
				
				var matched:Bool = false;
				
				if (valOne != null) {
					var val = null;
					if (StringTools.endsWith(arg, "}")) {
						val = valOne.substring(0, valOne.length - 1);
					}else {
						val = valOne.split("}")[0];
					}
					if (val != null) {
						for (p in props.propsArr) {
							if (p != null && p.name == val) {
								arg = p.value;
								matched = true;
								break;
							}
						}
					}
					logLine("VAL " + val);
				}
				if (!matched) {
					logLine("Could not expand " + arg);
				}
			}
		}
		return arg;
	}
}