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
	static inline var go:String        = "go";
	static inline var go_s:String      = "g";
	static inline var set:String       = "s"; 
	static inline var set_s:String     = "set"; 
	static inline var explore:String   = "explore"; 
	static inline var explore_s:String = "e"; 
	static inline var list:String      = "list"; 
	static inline var list_s:String    = "l"; 
	static inline var run:String      = "run"; 
	static inline var run_s:String    = "r"; 
	
	static var props:PropertySet;
	
	static function main() 
	{
		var props:PropertySet = {
			propsArr : new Array()
		}	
		if(FileSystem.exists(getFilePath())){
			var contents:String = File.getContent(getFilePath());
			var rawProps:Dynamic = Json.parse(contents);
			for (i in 0...rawProps.propsArr.length) {
				var p:Property = {
					name : rawProps.propsArr[i].name.toString(),
					value: rawProps.propsArr[i].value.toString()
				}
				props.propsArr.push(p);
			}
		}else{
			var file:FileOutput = File.write(getFilePath(), false);
			file.writeString("");
			file.close();
		}
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
						var file:FileOutput = File.write(getFilePath(), false);
						file.writeString(Json.stringify(props));
						file.close();
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
					var out:String = "Items = ";
					for (p in props.propsArr) {
						out += p.name + " : " + p.value + ", ";
					}
					Sys.print("echo " + out);
					
				case run | run_s:
					if (args.length > 1){
						var out:String = null;
						for (p in props.propsArr) {
							if (p.name == args[1].toString()) {
								out = p.value;
								break;
							}
						}
						if (out != null) {
							Sys.command(out);
						}
					}
			}
		}else {
			Sys.println("Argument expected.");
		}
	}
	
	static function getFilePath():String{
		var split = Sys.executablePath().split("/");
		var path:String = "";
		for (s in 0...split.length - 1) {
			path += s + "/";
		}
		path += "props.mangy";
		return path;
	}
}