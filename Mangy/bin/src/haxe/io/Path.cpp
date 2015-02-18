#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Path
#include <haxe/io/Path.h>
#endif
namespace haxe{
namespace io{

Void Path_obj::__construct()
{
	return null();
}

//Path_obj::~Path_obj() { }

Dynamic Path_obj::__CreateEmpty() { return  new Path_obj; }
hx::ObjectPtr< Path_obj > Path_obj::__new()
{  hx::ObjectPtr< Path_obj > result = new Path_obj();
	result->__construct();
	return result;}

Dynamic Path_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Path_obj > result = new Path_obj();
	result->__construct();
	return result;}

::String Path_obj::removeTrailingSlashes( ::String path){
	HX_STACK_FRAME("haxe.io.Path","removeTrailingSlashes",0x2dc73462,"haxe.io.Path.removeTrailingSlashes","C:\\HaxeToolkit\\haxe\\std/haxe/io/Path.hx",293,0x4f1aa280)
	HX_STACK_ARG(path,"path")
	HX_STACK_LINE(294)
	while((true)){
		HX_STACK_LINE(295)
		Dynamic _g = path.charCodeAt((path.length - (int)1));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(295)
		Dynamic _switch_1 = (_g);
		if (  ( _switch_1==(int)47) ||  ( _switch_1==(int)92)){
			HX_STACK_LINE(296)
			::String _g1 = path.substr((int)0,(int)-1);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(296)
			path = _g1;
		}
		else  {
			HX_STACK_LINE(297)
			break;
		}
;
;
	}
	HX_STACK_LINE(300)
	return path;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Path_obj,removeTrailingSlashes,return )


Path_obj::Path_obj()
{
}

Dynamic Path_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 21:
		if (HX_FIELD_EQ(inName,"removeTrailingSlashes") ) { return removeTrailingSlashes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Path_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Path_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("removeTrailingSlashes"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Path_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Path_obj::__mClass,"__mClass");
};

#endif

Class Path_obj::__mClass;

void Path_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Path"), hx::TCanCast< Path_obj> ,sStaticFields,sMemberFields,
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

void Path_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
