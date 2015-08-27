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
	static inline var pipe:String       = "pipe";
	static inline var pipe_s:String     = "p"; 
	static inline var runChain:String   = "run_chain";
	static inline var runChain_s:String = "rc";
	
	static inline var propsFile:String = "props.mangy";
	static inline var logFile:String   = "log.txt";
	
	static var props:PropertySet;
	
	static function main() 
	{
		var props:PropertySet = {
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
		
		var args:Array<String>;
		args = Sys.args();
		Sys.println(args.toString());
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
					if (args.length > 1){
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
							log("Running... " + out + "\n");
							Sys.command("\"" + out + "\"");
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
					
				case pipe | pipe_s:
					if (args.length > 1) {
						var prop:Property = null;
						for (p in props.propsArr) {
							if (p.name == args[1]) {
								prop = p;
								break;
							}
						}
						if (prop != null) {
							log(prop.value);
						}
					}
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
							val = StringTools.trim(val);
							if (val != null) {
								log("Running... " + val + "\n");
								Sys.command("\"" + val + "\"");
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
	
	static function writeProps(props:PropertySet) {
		if(props != null){
			var file:FileOutput = File.write(getFilePath(propsFile), false);
			file.writeString(Json.stringify(props));
			file.close();
		}
	}
}