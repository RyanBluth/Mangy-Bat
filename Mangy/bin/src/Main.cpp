#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_format_JsonParser
#include <haxe/format/JsonParser.h>
#endif
#ifndef INCLUDED_haxe_format_JsonPrinter
#include <haxe/format/JsonPrinter.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

::String Main_obj::go;

::String Main_obj::go_s;

::String Main_obj::set;

::String Main_obj::set_s;

::String Main_obj::explore;

::String Main_obj::explore_s;

::String Main_obj::list;

::String Main_obj::list_s;

::String Main_obj::run;

::String Main_obj::run_s;

Dynamic Main_obj::props;

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",41,0x087e5c05)
		HX_STACK_LINE(43)
		Dynamic _g = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static Dynamic Block( Dynamic &_g){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",42,0x087e5c05)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("propsArr") , _g,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(42)
		Dynamic props = _Function_1_1::Block(_g);		HX_STACK_VAR(props,"props");
		struct _Function_1_2{
			inline static bool Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",45,0x087e5c05)
				{
					HX_STACK_LINE(45)
					::String path = ::Main_obj::getFilePath();		HX_STACK_VAR(path,"path");
					HX_STACK_LINE(45)
					::String _g1 = ::haxe::io::Path_obj::removeTrailingSlashes(path);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(45)
					return ::sys::FileSystem_obj::sys_exists(_g1);
				}
				return null();
			}
		};
		HX_STACK_LINE(45)
		if ((_Function_1_2::Block())){
			HX_STACK_LINE(46)
			::String _g2 = ::Main_obj::getFilePath();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(46)
			::String contents = ::sys::io::File_obj::getContent(_g2);		HX_STACK_VAR(contents,"contents");
			HX_STACK_LINE(47)
			Dynamic rawProps = ::haxe::format::JsonParser_obj::__new(contents)->parseRec();		HX_STACK_VAR(rawProps,"rawProps");
			HX_STACK_LINE(48)
			{
				HX_STACK_LINE(48)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(48)
				int _g3 = rawProps->__Field(HX_CSTRING("propsArr"),true)->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(48)
				while((true)){
					HX_STACK_LINE(48)
					if ((!(((_g1 < _g3))))){
						HX_STACK_LINE(48)
						break;
					}
					HX_STACK_LINE(48)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(50)
					::String _g31 = rawProps->__Field(HX_CSTRING("propsArr"),true)->__GetItem(i)->__Field(HX_CSTRING("name"),true)->toString();		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(51)
					::String _g4 = rawProps->__Field(HX_CSTRING("propsArr"),true)->__GetItem(i)->__Field(HX_CSTRING("value"),true)->toString();		HX_STACK_VAR(_g4,"_g4");
					struct _Function_4_1{
						inline static Dynamic Block( ::String &_g31,::String &_g4){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",49,0x087e5c05)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("name") , _g31,false);
								__result->Add(HX_CSTRING("value") , _g4,false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(49)
					Dynamic p = _Function_4_1::Block(_g31,_g4);		HX_STACK_VAR(p,"p");
					HX_STACK_LINE(53)
					props->__Field(HX_CSTRING("propsArr"),true)->__Field(HX_CSTRING("push"),true)(p);
				}
			}
		}
		else{
			HX_STACK_LINE(56)
			::String _g5 = ::Main_obj::getFilePath();		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(56)
			::sys::io::FileOutput file = ::sys::io::File_obj::write(_g5,false);		HX_STACK_VAR(file,"file");
			HX_STACK_LINE(57)
			file->writeString(HX_CSTRING(""));
			HX_STACK_LINE(58)
			file->close();
		}
		HX_STACK_LINE(60)
		Array< ::String > args;		HX_STACK_VAR(args,"args");
		HX_STACK_LINE(61)
		Array< ::String > _g6 = ::Sys_obj::args();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(61)
		args = _g6;
		HX_STACK_LINE(62)
		::String _g7 = args->toString();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(62)
		::Sys_obj::println(_g7);
		HX_STACK_LINE(63)
		if (((args->length > (int)0))){
			HX_STACK_LINE(64)
			::String _g1 = args->__get((int)0);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(64)
			::String _switch_1 = (_g1);
			if (  ( _switch_1==HX_CSTRING("go")) ||  ( _switch_1==HX_CSTRING("g"))){
				HX_STACK_LINE(66)
				if (((args->length > (int)1))){
					HX_STACK_LINE(67)
					::String path = null();		HX_STACK_VAR(path,"path");
					HX_STACK_LINE(68)
					{
						HX_STACK_LINE(68)
						int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(68)
						Dynamic _g2 = props->__Field(HX_CSTRING("propsArr"),true);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(68)
						while((true)){
							HX_STACK_LINE(68)
							if ((!(((_g11 < _g2->__Field(HX_CSTRING("length"),true)))))){
								HX_STACK_LINE(68)
								break;
							}
							HX_STACK_LINE(68)
							Dynamic p = _g2->__GetItem(_g11);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(68)
							++(_g11);
							HX_STACK_LINE(69)
							::String _g8 = args->__get((int)1).toString();		HX_STACK_VAR(_g8,"_g8");
							HX_STACK_LINE(69)
							if (((p->__Field(HX_CSTRING("name"),true) == _g8))){
								HX_STACK_LINE(70)
								path = p->__Field(HX_CSTRING("value"),true);
								HX_STACK_LINE(71)
								break;
							}
						}
					}
					HX_STACK_LINE(74)
					::Sys_obj::print((HX_CSTRING("cd ") + path));
				}
			}
			else if (  ( _switch_1==HX_CSTRING("s")) ||  ( _switch_1==HX_CSTRING("set"))){
				HX_STACK_LINE(77)
				if (((args->length > (int)2))){
					HX_STACK_LINE(79)
					::String _g9 = args->__get((int)1).toString();		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(80)
					::String _g10 = args->__get((int)2).toString();		HX_STACK_VAR(_g10,"_g10");
					struct _Function_4_1{
						inline static Dynamic Block( ::String &_g10,::String &_g9){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",78,0x087e5c05)
							{
								hx::Anon __result = hx::Anon_obj::Create();
								__result->Add(HX_CSTRING("name") , _g9,false);
								__result->Add(HX_CSTRING("value") , _g10,false);
								return __result;
							}
							return null();
						}
					};
					HX_STACK_LINE(78)
					Dynamic prop = _Function_4_1::Block(_g10,_g9);		HX_STACK_VAR(prop,"prop");
					HX_STACK_LINE(82)
					bool exists = false;		HX_STACK_VAR(exists,"exists");
					HX_STACK_LINE(83)
					{
						HX_STACK_LINE(83)
						int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(83)
						Dynamic _g2 = props->__Field(HX_CSTRING("propsArr"),true);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(83)
						while((true)){
							HX_STACK_LINE(83)
							if ((!(((_g11 < _g2->__Field(HX_CSTRING("length"),true)))))){
								HX_STACK_LINE(83)
								break;
							}
							HX_STACK_LINE(83)
							Dynamic p = _g2->__GetItem(_g11);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(83)
							++(_g11);
							HX_STACK_LINE(84)
							if (((p->__Field(HX_CSTRING("name"),true) == prop->__Field(HX_CSTRING("name"),true)))){
								HX_STACK_LINE(85)
								p->__FieldRef(HX_CSTRING("value")) = prop->__Field(HX_CSTRING("value"),true);
								HX_STACK_LINE(86)
								exists = true;
								HX_STACK_LINE(87)
								break;
							}
						}
					}
					HX_STACK_LINE(90)
					if ((!(exists))){
						HX_STACK_LINE(91)
						props->__Field(HX_CSTRING("propsArr"),true)->__Field(HX_CSTRING("push"),true)(prop);
					}
					HX_STACK_LINE(93)
					::String _g11 = ::Main_obj::getFilePath();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(93)
					::sys::io::FileOutput file = ::sys::io::File_obj::write(_g11,false);		HX_STACK_VAR(file,"file");
					HX_STACK_LINE(94)
					::String _g12 = ::haxe::format::JsonPrinter_obj::print(props,null(),null());		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(94)
					file->writeString(_g12);
					HX_STACK_LINE(95)
					file->close();
				}
			}
			else if (  ( _switch_1==HX_CSTRING("explore")) ||  ( _switch_1==HX_CSTRING("e"))){
				HX_STACK_LINE(98)
				if (((args->length > (int)1))){
					HX_STACK_LINE(99)
					::String path = null();		HX_STACK_VAR(path,"path");
					HX_STACK_LINE(100)
					{
						HX_STACK_LINE(100)
						int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(100)
						Dynamic _g2 = props->__Field(HX_CSTRING("propsArr"),true);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(100)
						while((true)){
							HX_STACK_LINE(100)
							if ((!(((_g11 < _g2->__Field(HX_CSTRING("length"),true)))))){
								HX_STACK_LINE(100)
								break;
							}
							HX_STACK_LINE(100)
							Dynamic p = _g2->__GetItem(_g11);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(100)
							++(_g11);
							HX_STACK_LINE(101)
							::String _g13 = args->__get((int)1).toString();		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(101)
							if (((p->__Field(HX_CSTRING("name"),true) == _g13))){
								HX_STACK_LINE(102)
								path = p->__Field(HX_CSTRING("value"),true);
								HX_STACK_LINE(103)
								break;
							}
						}
					}
					HX_STACK_LINE(106)
					if (((path != null()))){
						HX_STACK_LINE(107)
						::Sys_obj::command(HX_CSTRING("explorer"),Array_obj< ::String >::__new().Add(path));
					}
				}
			}
			else if (  ( _switch_1==HX_CSTRING("list")) ||  ( _switch_1==HX_CSTRING("l"))){
				HX_STACK_LINE(112)
				::String out = HX_CSTRING("Items = ");		HX_STACK_VAR(out,"out");
				HX_STACK_LINE(113)
				{
					HX_STACK_LINE(113)
					int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(113)
					Dynamic _g2 = props->__Field(HX_CSTRING("propsArr"),true);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(113)
					while((true)){
						HX_STACK_LINE(113)
						if ((!(((_g11 < _g2->__Field(HX_CSTRING("length"),true)))))){
							HX_STACK_LINE(113)
							break;
						}
						HX_STACK_LINE(113)
						Dynamic p = _g2->__GetItem(_g11);		HX_STACK_VAR(p,"p");
						HX_STACK_LINE(113)
						++(_g11);
						HX_STACK_LINE(114)
						hx::AddEq(out,(((p->__Field(HX_CSTRING("name"),true) + HX_CSTRING(" : ")) + p->__Field(HX_CSTRING("value"),true)) + HX_CSTRING(", ")));
					}
				}
				HX_STACK_LINE(116)
				::Sys_obj::print((HX_CSTRING("echo ") + out));
			}
			else if (  ( _switch_1==HX_CSTRING("run")) ||  ( _switch_1==HX_CSTRING("r"))){
				HX_STACK_LINE(119)
				if (((args->length > (int)1))){
					HX_STACK_LINE(120)
					::String out = null();		HX_STACK_VAR(out,"out");
					HX_STACK_LINE(121)
					{
						HX_STACK_LINE(121)
						int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(121)
						Dynamic _g2 = props->__Field(HX_CSTRING("propsArr"),true);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(121)
						while((true)){
							HX_STACK_LINE(121)
							if ((!(((_g11 < _g2->__Field(HX_CSTRING("length"),true)))))){
								HX_STACK_LINE(121)
								break;
							}
							HX_STACK_LINE(121)
							Dynamic p = _g2->__GetItem(_g11);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(121)
							++(_g11);
							HX_STACK_LINE(122)
							::String _g14 = args->__get((int)1).toString();		HX_STACK_VAR(_g14,"_g14");
							HX_STACK_LINE(122)
							if (((p->__Field(HX_CSTRING("name"),true) == _g14))){
								HX_STACK_LINE(123)
								out = p->__Field(HX_CSTRING("value"),true);
								HX_STACK_LINE(124)
								break;
							}
						}
					}
					HX_STACK_LINE(127)
					if (((out != null()))){
						HX_STACK_LINE(128)
						::Sys_obj::command(out,null());
					}
				}
			}
		}
		else{
			HX_STACK_LINE(133)
			::Sys_obj::println(HX_CSTRING("Argument expected."));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))

::String Main_obj::getFilePath( ){
	HX_STACK_FRAME("Main","getFilePath",0x88904962,"Main.getFilePath","Main.hx",137,0x087e5c05)
	HX_STACK_LINE(138)
	Array< ::String > split = ::Sys_obj::executablePath().split(HX_CSTRING("/"));		HX_STACK_VAR(split,"split");
	HX_STACK_LINE(139)
	::String path = HX_CSTRING("");		HX_STACK_VAR(path,"path");
	HX_STACK_LINE(140)
	{
		HX_STACK_LINE(140)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(140)
		int _g = (split->length - (int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(140)
		while((true)){
			HX_STACK_LINE(140)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(140)
				break;
			}
			HX_STACK_LINE(140)
			int s = (_g1)++;		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(141)
			hx::AddEq(path,(s + HX_CSTRING("/")));
		}
	}
	HX_STACK_LINE(143)
	hx::AddEq(path,HX_CSTRING("props.mangy"));
	HX_STACK_LINE(144)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,getFilePath,return )


Main_obj::Main_obj()
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"props") ) { return props; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getFilePath") ) { return getFilePath_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"props") ) { props=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("go"),
	HX_CSTRING("go_s"),
	HX_CSTRING("set"),
	HX_CSTRING("set_s"),
	HX_CSTRING("explore"),
	HX_CSTRING("explore_s"),
	HX_CSTRING("list"),
	HX_CSTRING("list_s"),
	HX_CSTRING("run"),
	HX_CSTRING("run_s"),
	HX_CSTRING("props"),
	HX_CSTRING("main"),
	HX_CSTRING("getFilePath"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Main_obj::go,"go");
	HX_MARK_MEMBER_NAME(Main_obj::go_s,"go_s");
	HX_MARK_MEMBER_NAME(Main_obj::set,"set");
	HX_MARK_MEMBER_NAME(Main_obj::set_s,"set_s");
	HX_MARK_MEMBER_NAME(Main_obj::explore,"explore");
	HX_MARK_MEMBER_NAME(Main_obj::explore_s,"explore_s");
	HX_MARK_MEMBER_NAME(Main_obj::list,"list");
	HX_MARK_MEMBER_NAME(Main_obj::list_s,"list_s");
	HX_MARK_MEMBER_NAME(Main_obj::run,"run");
	HX_MARK_MEMBER_NAME(Main_obj::run_s,"run_s");
	HX_MARK_MEMBER_NAME(Main_obj::props,"props");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Main_obj::go,"go");
	HX_VISIT_MEMBER_NAME(Main_obj::go_s,"go_s");
	HX_VISIT_MEMBER_NAME(Main_obj::set,"set");
	HX_VISIT_MEMBER_NAME(Main_obj::set_s,"set_s");
	HX_VISIT_MEMBER_NAME(Main_obj::explore,"explore");
	HX_VISIT_MEMBER_NAME(Main_obj::explore_s,"explore_s");
	HX_VISIT_MEMBER_NAME(Main_obj::list,"list");
	HX_VISIT_MEMBER_NAME(Main_obj::list_s,"list_s");
	HX_VISIT_MEMBER_NAME(Main_obj::run,"run");
	HX_VISIT_MEMBER_NAME(Main_obj::run_s,"run_s");
	HX_VISIT_MEMBER_NAME(Main_obj::props,"props");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Main_obj::__boot()
{
	go= HX_CSTRING("go");
	go_s= HX_CSTRING("g");
	set= HX_CSTRING("s");
	set_s= HX_CSTRING("set");
	explore= HX_CSTRING("explore");
	explore_s= HX_CSTRING("e");
	list= HX_CSTRING("list");
	list_s= HX_CSTRING("l");
	run= HX_CSTRING("run");
	run_s= HX_CSTRING("r");
}

