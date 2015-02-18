#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
namespace sys{

Void FileSystem_obj::__construct()
{
	return null();
}

//FileSystem_obj::~FileSystem_obj() { }

Dynamic FileSystem_obj::__CreateEmpty() { return  new FileSystem_obj; }
hx::ObjectPtr< FileSystem_obj > FileSystem_obj::__new()
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Dynamic FileSystem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Dynamic FileSystem_obj::sys_exists;


FileSystem_obj::FileSystem_obj()
{
}

Dynamic FileSystem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"sys_exists") ) { return sys_exists; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileSystem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"sys_exists") ) { sys_exists=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileSystem_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sys_exists"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_exists,"sys_exists");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_exists,"sys_exists");
};

#endif

Class FileSystem_obj::__mClass;

void FileSystem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.FileSystem"), hx::TCanCast< FileSystem_obj> ,sStaticFields,sMemberFields,
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

void FileSystem_obj::__boot()
{
	sys_exists= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exists"),(int)1);
}

} // end namespace sys
