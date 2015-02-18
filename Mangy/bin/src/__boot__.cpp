#include <hxcpp.h>

#include <sys/io/FileOutput.h>
#include <sys/io/File.h>
#include <sys/FileSystem.h>
#include <haxe/io/Path.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Output.h>
#include <haxe/io/Bytes.h>
#include <haxe/format/JsonPrinter.h>
#include <haxe/format/JsonParser.h>
#include <haxe/ds/StringMap.h>
#include <haxe/Utf8.h>
#include <Type.h>
#include <ValueType.h>
#include <Sys.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Std.h>
#include <Reflect.h>
#include <IMap.h>
#include <Main.h>
#include <cpp/Lib.h>
#include <Date.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::sys::io::FileOutput_obj::__register();
::sys::io::File_obj::__register();
::sys::FileSystem_obj::__register();
::haxe::io::Path_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::format::JsonPrinter_obj::__register();
::haxe::format::JsonParser_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::Utf8_obj::__register();
::Type_obj::__register();
::ValueType_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::Reflect_obj::__register();
::IMap_obj::__register();
::Main_obj::__register();
::cpp::Lib_obj::__register();
::Date_obj::__register();
::cpp::Lib_obj::__boot();
::Date_obj::__boot();
::Main_obj::__boot();
::IMap_obj::__boot();
::Reflect_obj::__boot();
::Std_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::ValueType_obj::__boot();
::Type_obj::__boot();
::haxe::Utf8_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::format::JsonParser_obj::__boot();
::haxe::format::JsonPrinter_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Output_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Path_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileOutput_obj::__boot();
}

