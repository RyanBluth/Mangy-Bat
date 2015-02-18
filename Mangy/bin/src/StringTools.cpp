#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void StringTools_obj::__construct()
{
	return null();
}

//StringTools_obj::~StringTools_obj() { }

Dynamic StringTools_obj::__CreateEmpty() { return  new StringTools_obj; }
hx::ObjectPtr< StringTools_obj > StringTools_obj::__new()
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

Dynamic StringTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

::String StringTools_obj::lpad( ::String s,::String c,int l){
	HX_STACK_FRAME("StringTools","lpad",0x23bd8feb,"StringTools.lpad","C:\\HaxeToolkit\\haxe\\std/StringTools.hx",248,0xb9dbeb2d)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(c,"c")
	HX_STACK_ARG(l,"l")
	HX_STACK_LINE(249)
	if (((c.length <= (int)0))){
		HX_STACK_LINE(250)
		return s;
	}
	HX_STACK_LINE(252)
	while((true)){
		HX_STACK_LINE(252)
		if ((!(((s.length < l))))){
			HX_STACK_LINE(252)
			break;
		}
		HX_STACK_LINE(253)
		s = (c + s);
	}
	HX_STACK_LINE(255)
	return s;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,lpad,return )


StringTools_obj::StringTools_obj()
{
}

Dynamic StringTools_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"lpad") ) { return lpad_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StringTools_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void StringTools_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("lpad"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

#endif

Class StringTools_obj::__mClass;

void StringTools_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringTools"), hx::TCanCast< StringTools_obj> ,sStaticFields,sMemberFields,
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

void StringTools_obj::__boot()
{
}

