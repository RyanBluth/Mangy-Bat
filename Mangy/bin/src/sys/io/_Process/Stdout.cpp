#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_sys_io__Process_Stdout
#include <sys/io/_Process/Stdout.h>
#endif
namespace sys{
namespace io{
namespace _Process{

Void Stdout_obj::__construct(Dynamic p,bool out)
{
HX_STACK_FRAME("sys.io._Process.Stdout","new",0xc765a8f4,"sys.io._Process.Stdout.new","C:\\HaxeToolkit\\haxe\\std/cpp/_std/sys/io/Process.hx",64,0x19dec630)
HX_STACK_THIS(this)
HX_STACK_ARG(p,"p")
HX_STACK_ARG(out,"out")
{
	HX_STACK_LINE(65)
	this->p = p;
	HX_STACK_LINE(66)
	this->out = out;
	HX_STACK_LINE(67)
	::haxe::io::Bytes _g = ::haxe::io::Bytes_obj::alloc((int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(67)
	this->buf = _g;
}
;
	return null();
}

//Stdout_obj::~Stdout_obj() { }

Dynamic Stdout_obj::__CreateEmpty() { return  new Stdout_obj; }
hx::ObjectPtr< Stdout_obj > Stdout_obj::__new(Dynamic p,bool out)
{  hx::ObjectPtr< Stdout_obj > result = new Stdout_obj();
	result->__construct(p,out);
	return result;}

Dynamic Stdout_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stdout_obj > result = new Stdout_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Stdout_obj::Stdout_obj()
{
}

void Stdout_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Stdout);
	HX_MARK_MEMBER_NAME(p,"p");
	HX_MARK_MEMBER_NAME(out,"out");
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_END_CLASS();
}

void Stdout_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(p,"p");
	HX_VISIT_MEMBER_NAME(out,"out");
	HX_VISIT_MEMBER_NAME(buf,"buf");
}

Dynamic Stdout_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { return p; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"out") ) { return out; }
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Stdout_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"p") ) { p=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"out") ) { out=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Stdout_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("p"));
	outFields->push(HX_CSTRING("out"));
	outFields->push(HX_CSTRING("buf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Stdout_obj,p),HX_CSTRING("p")},
	{hx::fsBool,(int)offsetof(Stdout_obj,out),HX_CSTRING("out")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Stdout_obj,buf),HX_CSTRING("buf")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("p"),
	HX_CSTRING("out"),
	HX_CSTRING("buf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Stdout_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stdout_obj::__mClass,"__mClass");
};

#endif

Class Stdout_obj::__mClass;

void Stdout_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io._Process.Stdout"), hx::TCanCast< Stdout_obj> ,sStaticFields,sMemberFields,
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

void Stdout_obj::__boot()
{
}

} // end namespace sys
} // end namespace io
} // end namespace _Process
